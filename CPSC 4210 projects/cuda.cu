/* CPSC 4210 Project 2
	Tony Ho
	cuda.cu
	Implement paralleled matrix-matrix multiplication with CUDA

*/

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <omp.h>
# include <unistd.h>
# include <string.h>
# include <getopt.h>
# include <time.h>

double r8_uniform_01(int *seed);

//Get a matrix element
__device__ float get_e(float* matrix, unsigned long long int row, unsigned long long int col, unsigned long long int e);
//Set values in the matrix
__device__ void set_value(float* matrix, float val, unsigned long long int row, unsigned long long int col, unsigned long long int e);
//Get the next sub-block of a matrix
__device__ float* get_block(float* matrix, unsigned long long int row, unsigned long long int col, unsigned long long int e);

//Kernel function, use threads compute the elements of matrix A and add them together in the end
__global__ void kernel_global(float* A, float* B, float* C, unsigned long long int e);
//Implement MM with GPU's global memory
double* matrix_global(float* A, float* B, float* C, unsigned long long int e, int time_run);
//Kernel function, use threads compute the elements of matrix A by shared memory
__global__ void kernel_shared(float* A, float* B, float* C, unsigned long long int e);
//Implement MM with GPU's shared memory
double* matrix_shared(float* A, float* B, float* C, unsigned long long int e, int time_run);

/* Please modify for GPU Experiments */
/* @@@ Shahadat Hossain (SH) March 12, 2018 */
/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

   <<< SH:  Skeletal c code for performing dense matrix times matrix. >>>
   <<<      a = b*c where a, b, c are matrices of size n X n          >>>


  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

   @@@ Shahadat Hossain (SH) Nov 08, 2019

 */
{
    int id;
    unsigned long long int l;
    unsigned long long int m;
    unsigned long long int n;
    double* temp;
    double avg_dt;	//Average elapse time from 3 runs
    double avg_rate;	//Average rate from 3 runs

  printf ( "\n" );
  printf ( "Dense MXM\n" );
  printf ( "  C/OpenMP version.\n" );
  printf ( "\n" );
  printf ( "  Matrix multiplication tests.\n" );

/*
    @@@ SH Note 1b:

     These values need to be read in from command line. Assume that
     l = m = n.
*/
  //l = 4096;
  //m = 4096;
  //n = 4096;

    char option;
    while((option = getopt(argc, argv, "n:h")) != -1)
    {
        switch(option)
        {
            //When user triggered the flag for assigning, assign the dimensions for matrices
            case 'n':
                e = atoi(optarg);
                break;
            case 'h':
                exit(0);
            default:
                exit(1);
        }
    }

    //Allocate memory space for matricies
    float* A = (float*)malloc(e * e * sizeof(float));
    float* B = (float*)malloc(e * e * sizeof(float));
    float* C = (float*)malloc(e * e * sizeof(float));

    int seed = 123456789;  //Seed value used to generate pseudorandom numbers

    //Generate pseudorandom numbers and assign them to the matrices
    //Assign values for A
    for(i = 0; i < e; i++)
    {
        for(j = 0; j < e; j++)
            A[e * i + j] = (float) (r8_uniform_01(&seed));
    }
    //Assign values for B
    for(i = 0; i < e; i++)
    {
        for(j = 0; j < e; j++)
            A[e * i + j] = (float) (r8_uniform_01(&seed));
    }
    //Assign values for C
    for(i = 0; i < e; i++)
    {
        for(j = 0; j < e; j++)
            A[e * i + j] = (float) (r8_uniform_01(&seed));
    }

	printf ( "\n" );
	printf ( "Cuda Processing\n");
  printf (" Element size = %llu\n", e);
	printf ( "Block size: 16\n");
//=====================================================================================================
	printf( "\n" );
	printf( "CUDA global memory:" );
	for (id = 0; id < 3; id++ )
	{
		temp = matrix_global(A, B, C, e, id);
		avg_dt += temp[0];
		avg_rate += temp[1];
	}
	avg_rate = (double) avg_rate/3;
	avg_dt = (double) avg_dt/3;
	printf("Average Elapsed Time dT: %f\n", avg_dt);
	printf("Average Rate: %f\n", avg_rate);
	avg_rate = avg_dt = 0.0;
	printf( "\n" );
	printf( "------------------------------------------------------------------------------" );
//=====================================================================================================
	printf( "\n" );
	printf( "CUDA shared memory:" );
	for (id = 0; id < 3; id++ )
	{
		temp = matrix_shared(A, B, C, e, id);
		avg_dt += temp[0];
		avg_rate += temp[1];
	}
	avg_rate = (double) avg_rate/3;
	avg_dt = (double) avg_dt/3;
	printf("Average Elapsed Time dT: %f\n", avg_dt);
	printf("Average Rate: %f\n", avg_rate);
	avg_rate = avg_dt = 0.0;
	printf( "\n" );
	printf( "------------------------------------------------------------------------------" );
//=====================================================================================================
/*
  Terminate.
*/
    //Deallocating
    free(A);
    free(B);
    free(C);

  printf ( "\n" );
  printf ( "Dense MXM:\n" );
  printf ( "  Normal end of execution.\n" );

  return 0;
}

//Get a matrix element
__device__ float get_e(float* matrix, unsigned long long int row, unsigned long long int col, unsigned long long int e)
{
    return matrix[e * row + col];
}

//Set values in matrix
__device__ void set_value(float* matrix, float value, unsigned long long int row, unsigned long long int col, unsigned long long int e)
{
    matrix[e * row + col] = value;
}
//Get the next block of a matrix
__device__ float* get_block(float* matrix, unsigned long long int row, unsigned long long int col, unsigned long long int e)
{
    float* block;
    block = &matrix[e * 16 * row + 16 * col];  //Block size = 16
    return block;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Kernel function, use threads compute the elements of matrix A and add them together in the end
__global__ void kernel_global(float* A, float* B, float* C, unsigned long long int e)
{
    //Acumulated results of a
    float total = 0.0;
    //Go through row and column of thread block
    unsigned long long int row = threadIdx.y + blockIdx.y * blockDim.y;
    unsigned long long int col = threadIdx.x + blockIdx.x * blockDim.x;
    //Stop if out of range
    if( row > e || col > e )
        return;
    //Find the correct element in B'row and C's, store in total, then assign to A
    int i;
    for(i = 0; i < e; i++)
        total += (B[(row * e) + i]) * (C[col + (e * i)]);
    A[(row * e) + col] = total;
}

//Implement MM with GPU's global memory
double* matrix_global(float* A, float* B, float* C, unsigned long long int e, int time_run)
{
    //Arrays to store matrix A, B, C
    float* matrix_a;
    float* matrix_b;
    float* matrix_c;

    float time_elapsed;
    double rate;
    double dt_rate[2];
    unsigned long long int ops;
    //unsigned long long l = e;
    //unsigned long long m = e;
    //unsigned long long n = e;
    int block_size = 16;
    //Size device memory
    unsigned long long int size = e * e * sizeof(float);

    //Allocation A,B,C matrices
    cudaMalloc(&matrix_a, size);
    cudaMalloc(&matrix_b, size);
    cudaMalloc(&matrix_c, size);
    //Copying memory
    cudaMemcpy(matrix_a, A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(matrix_b, B, size, cudaMemcpyHostToDevice);
    cudaMemcpy(matrix_c, C, size, cudaMemcpyHostToDevice);

    //Setup the grid and block dimensions
    dim3 block(block_size, block_size); //16X16 block
    //Setup grid based on block
    dim3 grid((e + block.x - 1) / block.x, (e + block.y - 1) / block.y);

    //Timer
    cudaEvent_t start, end;
    //Create CUDA event
    cudaEventCreate(&start);
    cudaEventCreate(&end);
    //Timer for CUDA start events
    cudaEventRecord(start, 0);

    //Run the kernel function on GPU
    kernel_global<<<grid, block>>>(matrix_a, matrix_b, matrix_c, e);
    //Synchronize threads
    cudaThreadSynchronize();

    //Timer for CUDA stop events
    cudaEventRecord(end, 0);
    cudaEventSynchronize(end);
    //Store the elapsed time
    cudaEventElapsedTime(&time_elapsed, start, end);
    //Deallocate the events when done
    cudaEventDestroy(start);
    cudaEventDestroy(end);
/*
  Generate Report.

*/
    ops = e * e * (e * 2);
    time_elapsed = time_elapsed / 1000.0;
    rate = (double) (ops) / time_elapsed / 1000000.0;

    printf ( "\n" );
    printf ( "CUDA global memory matrix multiplication timing.\n" );
    printf ( "Time Run: %d\n", time_run + 1 );
    printf ( "A(LxN) = B(LxM) * C(MxN)\n" );
    printf ( "L = %llu\n", e );
    printf ( "M = %llu\n", e );
    printf ( "N = %llu\n", e );
    printf ( "Floating point OPS roughly %llu\n", ops );
    printf ( "Elapsed time dT = %f\n", time_elapsed );
    printf ( "Rate = MegaOPS/dT = %f\n", rate );

    //Copy matrix A from device memory to host memory
    cudaMemcpy(A, matrix_a, size, cudaMemcpyDeviceToHost);

    dt_rate[0] = time_elapsed;
    dt_rate[1] = rate;

    //Deallocate memory space
    cudaFree(matrix_a);
    cudaFree(matrix_b);
    cudaFree(matrix_c);

    return dt_rate;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Kernel function, compute the elements of matrix A and add them together on shared memory
__global__ void kernel_shared(float* A, float* B, float* C, unsigned long long int e)
{
    int i, j;
    //Accumulated results of a
    float total = 0.0;
    //Block's row and column
    unsigned long long int block_row = blockIdx.y;
    unsigned long long int block_col = blockIdx.x;
    //Get next block to compute
    float* block_sub_A = get_block(A, block_row, block_col, e);
    //Thread row and col
    unsigned long long int thread_row = threadIdx.y;
    unsigned long long int thread_col = threadIdx.x;
    //Multiply each pairs of the matrices together, the store in total
    for( i = 0; i < e; i++ )
    {
        //Get block from B
        float* block_B = get_block(B, block_row, i, e);
        //Get block from C
        float* block_C = get_block(C, i, block_col, e);

        //Shared memory used to store the tiles of B and C
        //Block size is 16
        __shared__ float shared_B[16][16];
        __shared__ float shared_C[16][16];

        //Load tiles from device memory to shared memory
        shared_B[thread_row][thread_col] = get_e(B, thread_row, thread_col, e);
        shared_C[thread_row][thread_col] = get_e(C, thread_row, thread_col, e);

        //Synchronize threads before computation
        __syncthreads();

        //Multiply the blocks from B and C, then add
        //Block size is 16
        for(j = 0; j < 16; j++)
            total += shared_B[thread_row][j] * shared_C[j][thread_col];

        //Synchronize threads before stop
        //Get ready for the next turn of computation
        __syncthreads();

        //Put the value to A's block
        set_value(block_sub_A, total, thread_row, thread_col, e);
    }
}

//Implement MM with GPU's shared memory
double* matrix_shared(float* A, float* B, float* C, unsigned long long int e, int time_run)
{
    //Arrays to store matrix A, B, C
    float* matrix_a;
    float* matrix_b;
    float* matrix_c;

    float time_elapsed;
    double rate;
    double dt_rate[2];
    unsigned long long int ops;
    //unsigned long long l = e;
    //unsigned long long m = e;
    //unsigned long long n = e;
    int block_size = 16;

    //Size device memory
    unsigned long long int size = e * e * sizeof(float);

    //Allocation A,B,C
    cudaMalloc(&matrix_a, size);
    cudaMalloc(&matrix_b, size);
    cudaMalloc(&matrix_c, size);
    //Copying memory
    cudaMemcpy(matrix_a, A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(matrix_b, B, size, cudaMemcpyHostToDevice);
    cudaMemcpy(matrix_c, C, size, cudaMemcpyHostToDevice);

    //Setup the grid and block dimensions
    dim3 block(block_size, block_size); //16X16 block
    //Setup grid based on block
    dim3 grid((e + block.x - 1) / block.x, (e + block.y - 1) / block.y);

    //Timer
    cudaEvent_t start, end;
    //Create CUDA event
    cudaEventCreate(&start);
    cudaEventCreate(&end);
    //Timer for CUDA start events
    cudaEventRecord(start, 0);

    //Run the kernel function on GPU
    kernel_shared<<<grid, block>>>(matrix_a, matrix_b, matrix_c, e);
    //Synchronize threads
    cudaThreadSynchronize();

    //Timer for CUDA stop events
    cudaEventRecord(end, 0);
    cudaEventSynchronize(end);
    //Store the elapsed time
    cudaEventElapsedTime(&time_elapsed, start, end);
    //Deallocate the events when done
    cudaEventDestroy(start);
    cudaEventDestroy(end);
/*
  Generate Report.

*/
    ops = e * e * (e * 2);
    time_elapsed = time_elapsed / 1000.0;
    rate = (double) (ops) / time_elapsed / 1000000.0;

    printf ( "\n" );
    printf ( "CUDA shared memory matrix multiplication timing.\n" );
    printf ( "Time Run: %d\n", time_run + 1 );
    printf ( "A(LxN) = B(LxM) * C(MxN)\n" );
    printf ( "L = %llu\n", e );
    printf ( "M = %llu\n", e );
    printf ( "N = %llu\n", e );
    printf ( "Floating point OPS roughly %llu\n", ops );
    printf ( "Elapsed time dT = %f\n", time_elapsed );
    printf ( "Rate = MegaOPS/dT = %f\n", rate );

    //Copy matrix A from device memory to host memory
    cudaMemcpy(A, matrix_a, size, cudaMemcpyDeviceToHost);

    dt_rate[0] = time_elapsed;
    dt_rate[1] = rate;

    //Deallocate memory space
    cudaFree(matrix_a);
    cudaFree(matrix_b);
    cudaFree(matrix_c);

    return dt_rate;
}

/******************************************************************************/

double r8_uniform_01 ( int *seed )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_01 is a unit pseudorandom double precision real number R8.

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2**31 - 1 )
      unif = seed / ( 2**31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 August 2004

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Springer Verlag, pages 201-202, 1983.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, pages 362-376, 1986.

  Parameters:

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R8_UNIFORM_01, a new pseudorandom variate, strictly between
    0 and 1.
*/
{
  int k;
  double r;

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )
  {
    *seed = *seed + 2147483647;
  }

  r = ( double ) ( *seed ) * 4.656612875E-10;

  return r;
}

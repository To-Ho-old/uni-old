/* CPSC 4210 Project 2
	Tony Ho
	openmp.c
	Implement matrix-matrix multiplication in original, loop optimized, and blocking state
	With OpenMP in static, dynamic, and guided schedule
*/

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <omp.h>
# include <unistd.h>
# include <string.h>
# include <getopt.h>
# include <time.h>

double r8_uniform_01 ( int *seed );
//Original MM
double* origin_omp_static(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num, unsigned long long time_run);
double* origin_omp_dynamic(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num, unsigned long long time_run);
double* origin_omp_guided(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num, unsigned long long time_run);
//Loop optimized MM
double* loop_omp_static(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num, unsigned long long time_run);
double* loop_omp_dynamic(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num, unsigned long long time_run);
double* loop_omp_guided(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num, unsigned long long time_run);
//Blocking MM
double* block_omp_static(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num, unsigned long long time_run);
double* block_omp_dynamic(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num, unsigned long long time_run);
double* block_omp_guided(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num, unsigned long long time_run);


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
  unsigned long long t_num;
  double* temp;
  double avg_dt;	//Average elapse time from 3 runs
  double avg_rate;	//Average rate from 3 runs

  printf ( "\n" );
  printf ( "Dense MXM\n" );
  printf ( "  C/OpenMP version.\n" );
  printf ( "\n" );
  printf ( "  Matrix multiplication tests.\n" );

/*  @@@ SH Note 1a:

   You must read in the dimension of the matrix and the number of threads
   from the command line.
*/
  printf ( "\n" );
  printf ( "  Number of processors available = %d\n", omp_get_num_procs ( ) );
  printf ( "  Number of threads =              %d\n", omp_get_max_threads ( ) );

/*
    @@@ SH Note 1b:

     These values need to be read in from command line. Assume that
     l = m = n.
*/
  //l = 4096;
  //m = 4096;
  //n = 4096;

    char option;
    while((option = getopt(argc, argv, "n:t:h")) != -1)
    {
        switch(option)
        {
            //When user triggered the flag for assigning, assign the dimensions for matrices
            case 'n':
                l = m = n = atoi(optarg);
                break;
			 case 't':
                t_num = atoi(optarg);
                break;
            case 'h':
                exit(0);
            default:
                exit(1);
        }
    }

	printf ( "\n" );
	printf ( "OpenMP Parallel Processing\n");
	printf ( "Matrix Size: %llu\n", l);
	printf ( "Number of threads Used = %d\n", t_num );
//=====================================================================================================
	printf( "\n" );
	printf( "Original Parallel Static MM:" );
	for (id = 0; id < 3; id++ )
	{
		temp = origin_omp_static( l, m, n, t_num, id);
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
	printf( "Original Parallel Dynamic MM:" );
	for (id = 0; id < 3; id++ )
	{
		temp = origin_omp_dynamic( l, m, n,  t_num, id);
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
	printf( "Original Parallel Guided MM:" );
	for (id = 0; id < 3; id++ )
	{
		temp = origin_omp_guided( l, m, n, t_num, id);
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
  printf( "------------------------------------------------------------------------------" );
//=====================================================================================================
//=====================================================================================================
	printf( "\n" );
	printf( "Loop Optimized Parallel Static MM:" );
	for (id = 0; id < 3; id++)
	{
	  temp = loop_omp_static( l, m, n, t_num, id);
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
	printf( "Loop Optimized Parallel Dynamic MM:" );
	for (id = 0; id < 3; id++)
	{
	  temp = loop_omp_dynamic( l, m, n, t_num, id);
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
	printf( "Loop Optimized Parallel Guided MM:" );
	for (id = 0; id < 3; id++)
	{
	  temp = loop_omp_guided( l, m, n, t_num, id);
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
  printf( "------------------------------------------------------------------------------" );
//=====================================================================================================
//=====================================================================================================
	printf( "\n" );
	printf( "Blocking Parallel Static MM:" );
	for(id = 0; id < 3; id++)
	{
		temp = block_omp_static( l, m, n, t_num, id);
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
	printf( "Blocking Parallel Dynamic MM:" );
	for(id = 0; id < 3; id++)
	{
		temp = block_omp_dynamic( l, m, n, t_num, id);
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
	printf( "Blocking Parallel Guided MM:" );
	for(id = 0; id < 3; id++)
	{
		temp = block_omp_guided( l, m, n, t_num, id);
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
  printf( "------------------------------------------------------------------------------" );
//=====================================================================================================
//=====================================================================================================
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "Dense MXM:\n" );
  printf ( "  Normal end of execution.\n" );

  return 0;
}
//=====================================================================================================================
//Original Parallel Static
double* origin_omp_static(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num, unsigned long long  time_run)
//=====================================================================================================================
{
	double **a;
	double **b;
	double **c;
	int i;
	int j;
	int k;
	unsigned long long int ops;
	double rate;
	int seed;
	double time_begin;
	double time_elapsed;
	double time_stop;
	double dt_rate[2];
/*
  Allocate the storage for matrices.
*/
  a = ( double ** ) calloc ( l, sizeof ( double ) );
  b = ( double ** ) calloc ( l , sizeof ( double ) );
  c = ( double ** ) calloc ( m , sizeof ( double ) );
  for ( i = 0; i < l ; i++)
    a[i] = (double *) calloc (n, sizeof (double));
  for ( i = 0; i < l ; i++)
    b[i] = (double *) calloc (m, sizeof (double));
 for ( i = 0; i < m ; i++)
    c[i] = (double *) calloc (n, sizeof (double));
/*
  Assign randomly generated values to the input matrices B and C.
*/
  seed = 123456789;

  for ( k = 0; k < l ; k++ )
    for ( j = 0; j < m; j++)
    {
      b[k][j] = r8_uniform_01 ( &seed );
    }

  for ( k = 0; k < m ; k++ )
    for (j = 0; j < n; j++)
     {
       c[k][j] = r8_uniform_01 ( &seed );
     }

  time_begin = omp_get_wtime ( );


//set the number of threads
	omp_set_num_threads(t_num);

//Origin Parallel Static MM
	#pragma omp parallel shared(a, b, c, l, m, n) private(i, j, k)
	{
		for ( i = 0; i < l; i++)
		{
			# pragma omp for schedule(static)
			for ( j = 0; j < n; j++ )
			{
				a[i][j] = 0.0;
				for ( k = 0; k < m; k++ )
				{
					a[i][j] = a[i][j] + b[i][k] * c[k][j];
				}
			}
		}
	}
	time_stop = omp_get_wtime ( );
/*
  Generate Report.
*/
	ops = l * n * ( 2 * m );
	time_elapsed = time_stop - time_begin;
	rate = ( long double ) ( ops ) / time_elapsed / 1000000.0;

	printf ( "\n" );
	printf ( "Original Parallel Static MM timing.\n" );
	printf ( "Time run #: %d\n", time_run+1);
	printf ( "  A(LxN) = B(LxM) * C(MxN).\n" );
	printf ( "  L = %d\n", l );
	printf ( "  M = %d\n", m );
	printf ( "  N = %d\n", n );
	printf ( "  Floating point OPS roughly %d\n", ops );
	printf ( "  Elapsed time dT = %f\n", time_elapsed );
	printf ( "  Rate = MegaOPS/dT = %f\n", rate );

	//Deallocate memory space
	for(i = 0; i < l; i++)
        free(a[i]);
    for(i = 0; i < l; i++)
        free(b[i]);
    for(i = 0; i < m; i++)
        free(c[i]);
	free ( a );
	free ( b );
	free ( c );

	dt_rate[0] = time_elapsed;
	dt_rate[1] = rate;

	return dt_rate;
}
//=====================================================================================================================
//Original Parallel Dynamic
double* origin_omp_dynamic(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num, unsigned long long time_run)
//=====================================================================================================================
{
	double **a;
	double **b;
	double **c;
	int i;
	int j;
	int k;
	unsigned long long int ops;
	double rate;
	int seed;
	double time_begin;
	double time_elapsed;
	double time_stop;
	double dt_rate[2];
/*
  Allocate the storage for matrices.
*/
  a = ( double ** ) calloc ( l, sizeof ( double ) );
  b = ( double ** ) calloc ( l , sizeof ( double ) );
  c = ( double ** ) calloc ( m , sizeof ( double ) );
  for ( i = 0; i < l ; i++)
    a[i] = (double *) calloc (n, sizeof (double));
  for ( i = 0; i < l ; i++)
    b[i] = (double *) calloc (m, sizeof (double));
 for ( i = 0; i < m ; i++)
    c[i] = (double *) calloc (n, sizeof (double));
/*
  Assign randomly generated values to the input matrices B and C.
*/
  seed = 123456789;

  for ( k = 0; k < l ; k++ )
    for ( j = 0; j < m; j++)
    {
      b[k][j] = r8_uniform_01 ( &seed );
    }

  for ( k = 0; k < m ; k++ )
    for (j = 0; j < n; j++)
     {
       c[k][j] = r8_uniform_01 ( &seed );
     }

  time_begin = omp_get_wtime ( );

//set the number of threads
	omp_set_num_threads(t_num);

//Origin Parallel Schedule MM
    #pragma omp parallel shared(a, b, c, l, m, n) private(i, j, k)
    {
        for(i = 0; i < l; i++)
        {
			#pragma omp for schedule(dynamic)
            for(j = 0; j < n; j++)
            {
                a[i][j] = 0.0;
                for(k = 0; k < m; k++)
                {
                    a[i][j] = a[i][j] + b[i][k] * c[k][j];
                }
            }
        }
    }
	time_stop = omp_get_wtime ( );
/*
  Generate Report.
*/
	ops = l * n * ( 2 * m );
	time_elapsed = time_stop - time_begin;
	rate = ( long double ) ( ops ) / time_elapsed / 1000000.0;

	printf ( "\n" );
	printf ( "Original Parallel Dynamic MM timing.\n" );
	printf ( "Time run #: %d\n", time_run+1);
	printf ( "  A(LxN) = B(LxM) * C(MxN).\n" );
	printf ( "  L = %d\n", l );
	printf ( "  M = %d\n", m );
	printf ( "  N = %d\n", n );
	printf ( "  Floating point OPS roughly %d\n", ops );
	printf ( "  Elapsed time dT = %f\n", time_elapsed );
	printf ( "  Rate = MegaOPS/dT = %f\n", rate );

	//Deallocate memory space
	for(i = 0; i < l; i++)
        free(a[i]);
    for(i = 0; i < l; i++)
        free(b[i]);
    for(i = 0; i < m; i++)
        free(c[i]);
	free ( a );
	free ( b );
	free ( c );

	dt_rate[0] = time_elapsed;
	dt_rate[1] = rate;

	return dt_rate;
}
//=====================================================================================================================
//Original Parallel Guided
double* origin_omp_guided(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num, unsigned long long time_run)
//=====================================================================================================================
{
	double **a;
	double **b;
	double **c;
	int i;
	int j;
	int k;
	unsigned long long int ops;
	double rate;
	int seed;
	double time_begin;
	double time_elapsed;
	double time_stop;
	double dt_rate[2];
/*
  Allocate the storage for matrices.
*/
  a = ( double ** ) calloc ( l, sizeof ( double ) );
  b = ( double ** ) calloc ( l , sizeof ( double ) );
  c = ( double ** ) calloc ( m , sizeof ( double ) );
  for ( i = 0; i < l ; i++)
    a[i] = (double *) calloc (n, sizeof (double));
  for ( i = 0; i < l ; i++)
    b[i] = (double *) calloc (m, sizeof (double));
 for ( i = 0; i < m ; i++)
    c[i] = (double *) calloc (n, sizeof (double));
/*
  Assign randomly generated values to the input matrices B and C.
*/
  seed = 123456789;

  for ( k = 0; k < l ; k++ )
    for ( j = 0; j < m; j++)
    {
      b[k][j] = r8_uniform_01 ( &seed );
    }

  for ( k = 0; k < m ; k++ )
    for (j = 0; j < n; j++)
     {
       c[k][j] = r8_uniform_01 ( &seed );
     }

  time_begin = omp_get_wtime ( );

//set the number of threads
	omp_set_num_threads(t_num);

//Origin Parallel Guided MM
    #pragma omp parallel shared(a, b, c, l, m, n) private(i, j, k)
    {
        for(i = 0; i < l; i++)
        {
			#pragma omp for schedule(guided)
            for(j = 0; j < n; j++)
            {
                a[i][j] = 0.0;
                for(k = 0; k < m; k++)
                {
                    a[i][j] = a[i][j] + b[i][k] * c[k][j];
                }
            }
        }
    }
	time_stop = omp_get_wtime ( );
/*
  Generate Report.
*/
	ops = l * n * ( 2 * m );
	time_elapsed = time_stop - time_begin;
	rate = ( long double ) ( ops ) / time_elapsed / 1000000.0;

	printf ( "\n" );
	printf ( "Original Parallel Guided MM timing.\n" );
	printf ( "Time run #: %d\n", time_run + 1);
	printf ( "  A(LxN) = B(LxM) * C(MxN).\n" );
	printf ( "  L = %d\n", l );
	printf ( "  M = %d\n", m );
	printf ( "  N = %d\n", n );
	printf ( "  Floating point OPS roughly %d\n", ops );
	printf ( "  Elapsed time dT = %f\n", time_elapsed );
	printf ( "  Rate = MegaOPS/dT = %f\n", rate );

	//Deallocate memory space
	for(i = 0; i < l; i++)
        free(a[i]);
    for(i = 0; i < l; i++)
        free(b[i]);
    for(i = 0; i < m; i++)
        free(c[i]);
	free ( a );
	free ( b );
	free ( c );

	dt_rate[0] = time_elapsed;
	dt_rate[1] = rate;

	return dt_rate;
}
//=====================================================================================================================
//Loop optimized Static MM
double* loop_omp_static(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num, unsigned long long time_run)
//=====================================================================================================================
{
	double **a;
	double **b;
	double **c;
	int i;
	int j;
	int k;
	unsigned long long int ops;
	double rate;
	int seed;
	double time_begin;
	double time_elapsed;
	double time_stop;
	double dt_rate[2];
/*
  Allocate the storage for matrices.
*/
  a = ( double ** ) calloc ( l, sizeof ( double ) );
  b = ( double ** ) calloc ( l , sizeof ( double ) );
  c = ( double ** ) calloc ( m , sizeof ( double ) );
  for ( i = 0; i < l ; i++)
    a[i] = (double *) calloc (n, sizeof (double));
  for ( i = 0; i < l ; i++)
    b[i] = (double *) calloc (m, sizeof (double));
 for ( i = 0; i < m ; i++)
    c[i] = (double *) calloc (n, sizeof (double));
/*
  Assign randomly generated values to the input matrices B and C.
*/
  seed = 123456789;

  for ( k = 0; k < l ; k++ )
    for ( j = 0; j < m; j++)
    {
      b[k][j] = r8_uniform_01 ( &seed );
    }

  for ( k = 0; k < m ; k++ )
    for (j = 0; j < n; j++)
     {
       c[k][j] = r8_uniform_01 ( &seed );
     }


  time_begin = omp_get_wtime ( );
  //set the number of threads
  omp_set_num_threads(t_num);

//Loop optimized Parallel Static MM
    #pragma omp parallel shared(a, b, c, l, m, n) private(i, j, k)
    {
        for( i = 0; i < l; i++)
        {
			#pragma omp for schedule(static)
            for( k = 0; k < m; k++)
            {
                for( j = 0; j < n; j++)
                {
                    a[i][j] = a[i][j] + c[i][k] * b[k][j];
                }
            }
        }
    }

	time_stop = omp_get_wtime ( );
/*
  Generate Report.
*/
	ops = l * n * ( 2 * m );
	time_elapsed = time_stop - time_begin;
	rate = ( long double ) ( ops ) / time_elapsed / 1000000.0;

	printf ( "\n" );
	printf ( "Loop optimized Parallel Static MM timing.\n" );
	printf ( "Time run #: %d\n", time_run+1);
	printf ( "  A(LxN) = B(LxM) * C(MxN).\n" );
	printf ( "  L = %d\n", l );
	printf ( "  M = %d\n", m );
	printf ( "  N = %d\n", n );
	printf ( "  Floating point OPS roughly %d\n", ops );
	printf ( "  Elapsed time dT = %f\n", time_elapsed );
	printf ( "  Rate = MegaOPS/dT = %f\n", rate );

	//Deallocate memory space
	for(i = 0; i < l; i++)
        free(a[i]);
    for(i = 0; i < l; i++)
        free(b[i]);
    for(i = 0; i < m; i++)
        free(c[i]);
	free ( a );
	free ( b );
	free ( c );

	dt_rate[0] = time_elapsed;
	dt_rate[1] = rate;

	return dt_rate;
}
//=====================================================================================================================
//Loop optimized Dynamic MM
double* loop_omp_dynamic(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num, unsigned long long time_run)
//=====================================================================================================================
{
	double **a;
	double **b;
	double **c;
	int i;
	int j;
	int k;
	unsigned long long int ops;
	double rate;
	int seed;
	double time_begin;
	double time_elapsed;
	double time_stop;
	double dt_rate[2];
/*
  Allocate the storage for matrices.
*/
  a = ( double ** ) calloc ( l, sizeof ( double ) );
  b = ( double ** ) calloc ( l , sizeof ( double ) );
  c = ( double ** ) calloc ( m , sizeof ( double ) );
  for ( i = 0; i < l ; i++)
    a[i] = (double *) calloc (n, sizeof (double));
  for ( i = 0; i < l ; i++)
    b[i] = (double *) calloc (m, sizeof (double));
 for ( i = 0; i < m ; i++)
    c[i] = (double *) calloc (n, sizeof (double));
/*
  Assign randomly generated values to the input matrices B and C.
*/
  seed = 123456789;

  for ( k = 0; k < l ; k++ )
    for ( j = 0; j < m; j++)
    {
      b[k][j] = r8_uniform_01 ( &seed );
    }

  for ( k = 0; k < m ; k++ )
    for (j = 0; j < n; j++)
     {
       c[k][j] = r8_uniform_01 ( &seed );
     }


  time_begin = omp_get_wtime ( );
  //set the number of threads
  omp_set_num_threads(t_num);

//Loop optimized Parallel Dynamic MM
    #pragma omp parallel shared(a, b, c, l, m, n) private(i, j, k)
    {
        for( i = 0; i < l; i++)
        {
			#pragma omp for schedule(dynamic)
            for( k = 0; k < m; k++)
            {
                for( j = 0; j < n; j++)
                {
                    a[i][j] = a[i][j] + c[i][k] * b[k][j];
                }
            }
        }
    }

	time_stop = omp_get_wtime ( );
/*
  Generate Report.
*/
	ops = l * n * ( 2 * m );
	time_elapsed = time_stop - time_begin;
	rate = ( long double ) ( ops ) / time_elapsed / 1000000.0;

	printf ( "\n" );
	printf ( "Loop optimized Parallel Dynamic MM timing.\n" );
	printf ( "Time run #: %d\n", time_run+1);
	printf ( "  A(LxN) = B(LxM) * C(MxN).\n" );
	printf ( "  L = %d\n", l );
	printf ( "  M = %d\n", m );
	printf ( "  N = %d\n", n );
	printf ( "  Floating point OPS roughly %d\n", ops );
	printf ( "  Elapsed time dT = %f\n", time_elapsed );
	printf ( "  Rate = MegaOPS/dT = %f\n", rate );

	//Deallocate memory space
	for(i = 0; i < l; i++)
        free(a[i]);
    for(i = 0; i < l; i++)
        free(b[i]);
    for(i = 0; i < m; i++)
        free(c[i]);
	free ( a );
	free ( b );
	free ( c );

	dt_rate[0] = time_elapsed;
	dt_rate[1] = rate;

	return dt_rate;
}//=====================================================================================================================
//Loop optimized Guided MM
double* loop_omp_guided(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num, unsigned long long time_run)
//=====================================================================================================================
{
	double **a;
	double **b;
	double **c;
	int i;
	int j;
	int k;
	unsigned long long int ops;
	double rate;
	int seed;
	double time_begin;
	double time_elapsed;
	double time_stop;
	double dt_rate[2];
/*
  Allocate the storage for matrices.
*/
  a = ( double ** ) calloc ( l, sizeof ( double ) );
  b = ( double ** ) calloc ( l , sizeof ( double ) );
  c = ( double ** ) calloc ( m , sizeof ( double ) );
  for ( i = 0; i < l ; i++)
    a[i] = (double *) calloc (n, sizeof (double));
  for ( i = 0; i < l ; i++)
    b[i] = (double *) calloc (m, sizeof (double));
 for ( i = 0; i < m ; i++)
    c[i] = (double *) calloc (n, sizeof (double));
/*
  Assign randomly generated values to the input matrices B and C.
*/
  seed = 123456789;

  for ( k = 0; k < l ; k++ )
    for ( j = 0; j < m; j++)
    {
      b[k][j] = r8_uniform_01 ( &seed );
    }

  for ( k = 0; k < m ; k++ )
    for (j = 0; j < n; j++)
     {
       c[k][j] = r8_uniform_01 ( &seed );
     }


  time_begin = omp_get_wtime ( );
  //set the number of threads
  omp_set_num_threads(t_num);

//Loop optimized Parallel Guided MM
    #pragma omp parallel shared(a, b, c, l, m, n) private(i, j, k)
    {
        for( i = 0; i < l; i++)
        {
			#pragma omp for schedule(guided)
            for( k = 0; k < m; k++)
            {
                for( j = 0; j < n; j++)
                {
                    a[i][j] = a[i][j] + c[i][k] * b[k][j];
                }
            }
        }
    }

	time_stop = omp_get_wtime ( );
/*
  Generate Report.
*/
	ops = l * n * ( 2 * m );
	time_elapsed = time_stop - time_begin;
	rate = ( long double ) ( ops ) / time_elapsed / 1000000.0;

	printf ( "\n" );
	printf ( "Loop optimized Parallel Guided MM timing.\n" );
	printf ( "Time run #: %d\n", time_run+1);
	printf ( "  A(LxN) = B(LxM) * C(MxN).\n" );
	printf ( "  L = %d\n", l );
	printf ( "  M = %d\n", m );
	printf ( "  N = %d\n", n );
	printf ( "  Floating point OPS roughly %d\n", ops );
	printf ( "  Elapsed time dT = %f\n", time_elapsed );
	printf ( "  Rate = MegaOPS/dT = %f\n", rate );

	//Deallocate memory space
	for(i = 0; i < l; i++)
        free(a[i]);
    for(i = 0; i < l; i++)
        free(b[i]);
    for(i = 0; i < m; i++)
        free(c[i]);
	free ( a );
	free ( b );
	free ( c );

	dt_rate[0] = time_elapsed;
	dt_rate[1] = rate;

	return dt_rate;
}
//=====================================================================================================================
//Blocking Parallel Static MM
double* block_omp_static(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num,unsigned long long time_run)
//=====================================================================================================================
{
	double **a;
	double **b;
	double **c;
	int i;
	int j;
	int k;
	unsigned long long int ops;
	double rate;
	int seed;
	double time_begin;
	double time_elapsed;
	double time_stop;
	double dt_rate[2];
	int block_size = 16;
/*
  Allocate the storage for matrices.
*/
  a = ( double ** ) calloc ( l, sizeof ( double ) );
  b = ( double ** ) calloc ( l , sizeof ( double ) );
  c = ( double ** ) calloc ( m , sizeof ( double ) );
  for ( i = 0; i < l ; i++)
    a[i] = (double *) calloc (n, sizeof (double));
  for ( i = 0; i < l ; i++)
    b[i] = (double *) calloc (m, sizeof (double));
 for ( i = 0; i < m ; i++)
    c[i] = (double *) calloc (n, sizeof (double));
/*
  Assign randomly generated values to the input matrices B and C.
*/
  seed = 123456789;

  for ( k = 0; k < l ; k++ )
    for ( j = 0; j < m; j++)
    {
      b[k][j] = r8_uniform_01 ( &seed );
    }

  for ( k = 0; k < m ; k++ )
    for (j = 0; j < n; j++)
     {
       c[k][j] = r8_uniform_01 ( &seed );
     }


  time_begin = omp_get_wtime ( );
  //set the number of threads
  omp_set_num_threads(t_num);

//Blocking Parallel Static MM
    int x;
    int y;
    #pragma omp parallel shared(a, b, c, l, m, n) private(i, j, k, x, y)
    {
        for( x = 0; x < n; x += block_size)
        {
            for( y = 0; y < n; y += block_size)
            {
				#pragma omp for schedule(static)
                for( i = 0; i < l; i++)
                {
                    for( j = x; j < ( x + block_size); j++)
                    {
                        for( k = y; k < ( y + block_size); k++)
                            a[i][j] = a[i][j] + b[i][k] * c[k][j];
                    }
                }
            }
        }
    }

	time_stop = omp_get_wtime ( );
/*
  Generate Report.
*/
	ops = l * n * ( 2 * m );
	time_elapsed = time_stop - time_begin;
	rate = ( long double ) ( ops ) / time_elapsed / 1000000.0;

	printf ( "\n" );
	printf ( "Blocking Parallel Static MM timing.\n" );
	printf ( "Time run #: %d\n", time_run+1);
	printf ( "  A(LxN) = B(LxM) * C(MxN).\n" );
	printf ( "  L = %d\n", l );
	printf ( "  M = %d\n", m );
	printf ( "  N = %d\n", n );
	printf ( "  Floating point OPS roughly %d\n", ops );
	printf ( "  Elapsed time dT = %f\n", time_elapsed );
	printf ( "  Rate = MegaOPS/dT = %f\n", rate );

	//Deallocate memory space
	for(i = 0; i < l; i++)
        free(a[i]);
    for(i = 0; i < l; i++)
        free(b[i]);
    for(i = 0; i < m; i++)
        free(c[i]);
	free ( a );
	free ( b );
	free ( c );

	dt_rate[0] = time_elapsed;
	dt_rate[1] = rate;

	return dt_rate;
}
//=====================================================================================================================
//Blocking Parallel Dynamic MM
double* block_omp_dynamic(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num,unsigned long long time_run)
//=====================================================================================================================
{
	double **a;
	double **b;
	double **c;
	int i;
	int j;
	int k;
	unsigned long long int ops;
	double rate;
	int seed;
	double time_begin;
	double time_elapsed;
	double time_stop;
	double dt_rate[2];
	int block_size = 16;
/*
  Allocate the storage for matrices.
*/
  a = ( double ** ) calloc ( l, sizeof ( double ) );
  b = ( double ** ) calloc ( l , sizeof ( double ) );
  c = ( double ** ) calloc ( m , sizeof ( double ) );
  for ( i = 0; i < l ; i++)
    a[i] = (double *) calloc (n, sizeof (double));
  for ( i = 0; i < l ; i++)
    b[i] = (double *) calloc (m, sizeof (double));
 for ( i = 0; i < m ; i++)
    c[i] = (double *) calloc (n, sizeof (double));
/*
  Assign randomly generated values to the input matrices B and C.
*/
  seed = 123456789;

  for ( k = 0; k < l ; k++ )
    for ( j = 0; j < m; j++)
    {
      b[k][j] = r8_uniform_01 ( &seed );
    }

  for ( k = 0; k < m ; k++ )
    for (j = 0; j < n; j++)
     {
       c[k][j] = r8_uniform_01 ( &seed );
     }


  time_begin = omp_get_wtime ( );
  //set the number of threads
  omp_set_num_threads(t_num);

//Blocking Parallel Dynamic MM
    int x;
    int y;
    #pragma omp parallel shared(a, b, c, l, m, n) private(i, j, k, x, y)
    {
        for( x = 0; x < n; x += block_size)
        {
            for( y = 0; y < n; y += block_size)
            {
				#pragma omp for schedule(dynamic)
                for( i = 0; i < l; i++)
                {
                    for( j = x; j < ( x + block_size); j++)
                    {
                        for( k = y; k < ( y + block_size); k++)
                            a[i][j] = a[i][j] + b[i][k] * c[k][j];
                    }
                }
            }
        }
    }

	time_stop = omp_get_wtime ( );
/*
  Generate Report.
*/
	ops = l * n * ( 2 * m );
	time_elapsed = time_stop - time_begin;
	rate = ( long double ) ( ops ) / time_elapsed / 1000000.0;

	printf ( "\n" );
	printf ( "Blocking Parallel Dynamic MM timing.\n" );
	printf ( "Time run #: %d\n", time_run+1);
	printf ( "  A(LxN) = B(LxM) * C(MxN).\n" );
	printf ( "  L = %d\n", l );
	printf ( "  M = %d\n", m );
	printf ( "  N = %d\n", n );
	printf ( "  Floating point OPS roughly %d\n", ops );
	printf ( "  Elapsed time dT = %f\n", time_elapsed );
	printf ( "  Rate = MegaOPS/dT = %f\n", rate );

	//Deallocate memory space
	for(i = 0; i < l; i++)
        free(a[i]);
    for(i = 0; i < l; i++)
        free(b[i]);
    for(i = 0; i < m; i++)
        free(c[i]);
	free ( a );
	free ( b );
	free ( c );

	dt_rate[0] = time_elapsed;
	dt_rate[1] = rate;

	return dt_rate;
}
//=====================================================================================================================
//Blocking Parallel Guided MM
double* block_omp_guided(unsigned long long int l, unsigned long long int m, unsigned long long int n, unsigned long long t_num,unsigned long long time_run)
//=====================================================================================================================
{
	double **a;
	double **b;
	double **c;
	int i;
	int j;
	int k;
	unsigned long long int ops;
	double rate;
	int seed;
	double time_begin;
	double time_elapsed;
	double time_stop;
	double dt_rate[2];
	int block_size = 16;
/*
  Allocate the storage for matrices.
*/
  a = ( double ** ) calloc ( l, sizeof ( double ) );
  b = ( double ** ) calloc ( l , sizeof ( double ) );
  c = ( double ** ) calloc ( m , sizeof ( double ) );
  for ( i = 0; i < l ; i++)
    a[i] = (double *) calloc (n, sizeof (double));
  for ( i = 0; i < l ; i++)
    b[i] = (double *) calloc (m, sizeof (double));
 for ( i = 0; i < m ; i++)
    c[i] = (double *) calloc (n, sizeof (double));
/*
  Assign randomly generated values to the input matrices B and C.
*/
  seed = 123456789;

  for ( k = 0; k < l ; k++ )
    for ( j = 0; j < m; j++)
    {
      b[k][j] = r8_uniform_01 ( &seed );
    }

  for ( k = 0; k < m ; k++ )
    for (j = 0; j < n; j++)
     {
       c[k][j] = r8_uniform_01 ( &seed );
     }


  time_begin = omp_get_wtime ( );
  //set the number of threads
  omp_set_num_threads(t_num);

//Blocking Parallel Guided MM
    int x;
    int y;
    #pragma omp parallel shared(a, b, c, l, m, n) private(i, j, k, x, y)
    {
        for( x = 0; x < n; x += block_size)
        {
            for( y = 0; y < n; y += block_size)
            {
				#pragma omp for schedule(guided)
                for( i = 0; i < l; i++)
                {
                    for( j = x; j < ( x + block_size); j++)
                    {
                        for( k = y; k < ( y + block_size); k++)
                            a[i][j] = a[i][j] + b[i][k] * c[k][j];
                    }
                }
            }
        }
    }

	time_stop = omp_get_wtime ( );
/*
  Generate Report.
*/
	ops = l * n * ( 2 * m );
	time_elapsed = time_stop - time_begin;
	rate = ( long double ) ( ops ) / time_elapsed / 1000000.0;

	printf ( "\n" );
	printf ( "Blocking Parallel Guided MM timing.\n" );
	printf ( "Time run #: %d\n", time_run+1);
	printf ( "  A(LxN) = B(LxM) * C(MxN).\n" );
	printf ( "  L = %d\n", l );
	printf ( "  M = %d\n", m );
	printf ( "  N = %d\n", n );
	printf ( "  Floating point OPS roughly %d\n", ops );
	printf ( "  Elapsed time dT = %f\n", time_elapsed );
	printf ( "  Rate = MegaOPS/dT = %f\n", rate );

	//Deallocate memory space
	for(i = 0; i < l; i++)
        free(a[i]);
    for(i = 0; i < l; i++)
        free(b[i]);
    for(i = 0; i < m; i++)
        free(c[i]);
	free ( a );
	free ( b );
	free ( c );

	dt_rate[0] = time_elapsed;
	dt_rate[1] = rate;

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

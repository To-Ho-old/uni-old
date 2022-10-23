CC = /usr/bin/gcc
CFLAGS = -g -Wall -std=c99 -m64 -fopenmp
CUDA = /usr/local/cuda-10.1/bin/nvcc

all: serial openmp cuda

serial_mult:
	$(CC) $(CFLAGS) -o serial serial.c

openmp_mult:
	$(CC) $(CFLAGS) -o openmp openmp.c

cuda_mult:
	$(CUDA) -o cuda cuda.cu

clean:
	rm -fv serial openmp cuda *.o

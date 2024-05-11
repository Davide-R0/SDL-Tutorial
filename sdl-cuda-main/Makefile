CXX=g++
NVCC=nvcc

CUDA_VERSION=10.0
INC_DIRS=/usr/local/cuda-${CUDA_VERSION}/include
INC=$(foreach d, $(INC_DIRS), -I$d)

all: main

main: main.o cudaRender.o
	${CXX} -o main main.o cudaRender.o -lSDL2 -lcudart

main.o: main.cpp
	${CXX} -c -o main.o main.cpp

cudaRender.o: cudaRender.cu cudaRender.h
	nvcc $(INC) -c -o cudaRender.o cudaRender.cu

clean: 
	rm -f *.o main

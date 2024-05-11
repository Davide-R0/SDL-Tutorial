#OBJS specifies which files to compile as part of the project
MAIN = 6-main.cpp

#EXEC_NAME specifies the name of the exectuable
EXEC_NAME = 6-main 
OBJ_NAME = 6-main.o

#CC specifies which compiler is used
# C compiler 
CC = g++
# CUDA compiler 
#NCC = nvcc

#COMPILER_FLAGS specifies the additional compilation options
# -w suppresses all warnings
# -Wall Show compiler warnings 
# -g add debug informations
COMPILER_FLAGS = -Wall -g 
#-O2 

#LINKER_FLAGS specifies the libraries linked
LINKER_FLAGS = -lSDL2 
#-lSDL2_image 

#This is the target that compiles our executable
# This ran multiple functions and then execute the commands
all: main

run: main
	./$(EXEC_NAME)

main: $(OBJ_NAME) SDLcontrol.o 
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC_NAME) $(OBJ_NAME) SDLcontrol.o

#2-main.o SDLcontrol.o
	#$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC_NAME) 2-main.o SDLcontrol.o && ./$(EXEC_NAME)

$(OBJ_NAME): $(MAIN) SDLcontrol.h 
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c $(MAIN)

SDLcontrol.o: SDLcontrol.h SDLcontrol.cpp
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c SDLcontrol.cpp	

clean:
	$(RM) $(EXEC_NAME) *.o

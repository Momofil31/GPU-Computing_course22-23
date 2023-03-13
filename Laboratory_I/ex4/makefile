# create a makefile variable named CC for your C/C++ compiler (es gcc, c++, ... )
CC = gcc

# create a makefile variable named OPT with your favorite C flags (at least with -std=c99 -O3)
OPT = -std=c99 -O3


BIN_FOLDER := bin
OBJ_FOLDER := obj
SRC_FOLDER := src
BATCH_OUT_FOLDER := outputs

MAIN    =  lab1_ex4.c
OBJECTS = $(OBJ_FOLDER)/lab1_ex4_lib.o

all: $(BIN_FOLDER)/lab1_ex4

#create the target 'bin/lab1_ex4' which needs 'lab1_ex4.c' and 'lab1_ex4_lib.o', generate the folder 'bin' and compile lab1_ex4.c using CC and OPT

$(BIN_FOLDER)/lab1_ex4: lab1_ex4.c $(OBJ_FOLDER)/lab1_ex4_lib.o
	@mkdir -p $(BIN_FOLDER) $(OBJ_FOLDER) $(BATCH_OUT_FOLDER)
	$(CC) lab1_ex4.c $(OBJ_FOLDER)/lab1_ex4_lib.o -o $@ $(OPT)


$(OBJ_FOLDER)/lab1_ex4_lib.o: $(SRC_FOLDER)/lab1_ex4_lib.c
	@mkdir -p $(BIN_FOLDER) $(OBJ_FOLDER) $(BATCH_OUT_FOLDER)
	$(CC) -c $(SRC_FOLDER)/lab1_ex4_lib.c -o $@ $(OPT)


#create the target 'clean' which recursively remove the folders 'bin' and 'obj'
clean: 
	rm -rf $(BIN_FOLDER) $(OBJ_FOLDER)

clean_batch_outputs:
	rm $(BATCH_OUT_FOLDER)/*

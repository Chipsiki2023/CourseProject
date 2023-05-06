CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC_PATH = src
OBJ_PATH = obj
BIN_PATH = bin

LIB_SRC = src/playlib
LIB_OBJ = obj/playlib

APP_NAME = exe

all: exe

exe: $(LIB_OBJ)/libplaylib.a $(OBJ_PATH)/main.o
	$(CC) $(OBJ_PATH)/main.o -L$(LIB_OBJ) -lplaylib -o $(BIN_PATH)/$(APP_NAME)

$(OBJ_PATH)/main.o: $(SRC_PATH)/main.c
	$(CC) $(SRC_PATH)/main.c -c -o $(OBJ_PATH)/main.o

$(LIB_OBJ)/libplaylib.a: $(LIB_OBJ)/play.o
	ar rcs $(LIB_OBJ)/libplaylib.a $(LIB_OBJ)/play.o

$(LIB_OBJ)/play.o: $(LIB_SRC)/play.c
	$(CC) $(LIB_SRC)/play.c -c -o $(LIB_OBJ)/play.o

clean:
	rm $(OBJ_PATH)/main.o $(LIB_OBJ)/*  $(BIN_PATH)/$(APP_NAME)

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC_PATH = src
OBJ_PATH = obj
BIN_PATH = bin
LIB_PATH = obj/playlib

APP_NAME = exe

all: exe

exe: $(LIB_PATH)/libplaylib.a $(OBJ_PATH)/main.o
	$(CC) $(OBJ_PATH)/main.o -L$(LIB_PATH) -lplaylib -o $(BIN_PATH)/$(APP_NAME)

$(OBJ_PATH)/main.o: $(SRC_PATH)/main.c
	$(CC) $(SRC_PATH)/main.c -o $(OBJ_PATH)/main.o

$(LIB_PATH)/libplaylib.a: $(OBJ_PATH)/play.o
	ar rcs $(LIB_PATH)/libplaylib.a play.o

$(OBJ_PATH)/play.o: $(SRC_PATH)/play.c
	$(CC) $(SRC_PATH)/play.c -o $(OBJ_PATH)/play.o


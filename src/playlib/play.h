#ifndef PLAY_H
#define PLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCREEN_LINES 50

#define MAX_NAME_LEN 16
#define MAX_HEAP_SIZE 10
#define HEAP_COUNT 3

#define PLAYER_1 0
#define PLAYER_2 1

void clearScreen();

void askPlayersNames(char* p1, char* p2);
int mainCycle(char* p1, char* p2);
void showWinner(int winner, char* name);

void startGame();

void genHeapSize(int* heaps);
void printHeaps(int* heaps);
int sum(int* heaps);

#endif


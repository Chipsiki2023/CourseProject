#include <stdio.h>
#include <stdlib.h>

#include "playlib/play.h"

#define START 1
#define EXIT 2

#define TRUE 1

void showMenu();

int main() {
	while (TRUE) {
		showMenu();

		int choice = 0;

		printf("Choice: ");
		scanf("%d", &choice);

		while (choice != START && choice != EXIT) {
			printf("Wrong choice!\nChoice: ");
			scanf("%d", &choice);
		}

		if (choice == EXIT)
			break;

		printf("Check 0\n");

		getchar();

		startGame();
	}

	return 0;
}

void showMenu() {
	clearScreen();

	printf("Nim Game!\n");
	printf("1 - Start\n");
	printf("2 - Exit\n");
}


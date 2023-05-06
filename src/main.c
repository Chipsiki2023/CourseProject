#include <stdio.h>
#include <stdlib.h>

#include "play.h"

#define START '1'
#define EXIT '2'

void showMenu();

int main() {
	while (TRUE) {
		showMenu();

		char choice = 0;

		scanf("Choice: %c\n", &choice);

		while (choice != START && choice != EXIT) {
			printf("Wrong choice!\n");
			scanf("Choice: %c\n", &choice);
		}

		if (choice == EXIT)
			break;

		startGame();
	}

	return 0;
}

void showMenu() {
	printf("Nim Game!\n");
	printf("1 - Start\n");
	printf("2 - Exit\n");
}


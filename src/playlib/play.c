#include "play.h"

void startGame() {
	clearScreen();

	char player1[MAX_NAME_LEN];
	char player2[MAX_NAME_LEN];

	askPlayersNames(player1, player2);

	int winner = mainCycle(player1, player2);

	showWinner(winner);

	printf("\nPress any key to continue...");
	getch();

	clearScreen();
}

int mainCycle(char* player1, char* player2) {

	int heaps[HEAP_COUNT];
	genHeapSize(heaps);

	int currentPlayer = PLAYER_2;

	while (sum(int* heaps) != 0) {
		// Changing current player
		currentPlayer = (currentPlayer + 1) % 2;

		clearScreen();
		printHeaps(heaps);

		printf("\nPlayer #%d turn", currentPlayer);

		// Choosing which heap player pick from
		printf("Which heap you choose?\nNumber (1, 2, 3): ");
		int heapChoice;
		scanf("%d", &heapChoice);

		while (heapChoice < 1 || heapChoice > 3) {
			printf("Wrong choice! Enter correct number.\nNumber (1, 2, 3): ");
			scanf("%d", &heapChoice);
		}

		// Choosing how much player pick
		printf("\nHow much you want to pick?\nNumber: ");
		int countChoice;
		scanf("%d", &countChoice);

		while (countChoice < 0 && countChoice > heaps[heapChoice]) {
			printf("Wrong choice! Enter correct number.\nNumber: ");
			scanf("%d", &countChoice);
		}

		// Do arithmetic
		heaps[heapChoice] -= countChoice;
	}

	return currentPlayer;
}

int genHeapSize(int* heaps) {
	int i;
	for (i = 0; i < HEAP_COUNT; i++) {
		heaps[i] = rand() % 10 + 1;
	}
}

void askPlayersNames(char* p1, char* p2) {
	printf("Enter the name of first player: ");
	fgets(p1, MAX_NAME_LEN, stdin);
	printf("\nEnter the name of second player: ");
	fgets(p2, MAX_NAME_LEN, stdin);
}

void clearScreen() {
	char buff[SCREEN_LINES + 1];
	int i;
	for (i = 0; i < SCREEN_LINES; i++) {
		buff[i] = '\n';
	}

	buff[SCREEN_LINES] = 0;

	fputs(buff, stdout);
}

void showWinner(int winner) {
	clearScreen();

	printf("Player #%d wins!", winner);
}

void printHeaps(int* heaps) {
	int i, j;
	for (i = 0; i < HEAP_COUNT; i++) {
		printf("(%d): ", heaps[i]);
		for (j = 0; j < heaps[i]; j++) {
			printf("| ");
		}
		printf("\n");
	}
}

int sum(int* heaps) {
	int sum = 0;
	int i;
	for (i = 0; i < HEAP_COUNT; i++) {
		sum += heaps[i];
	}

	return sum;
}


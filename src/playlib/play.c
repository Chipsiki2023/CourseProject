#include "play.h"

void startGame() {
	printf("Check 1\n");

	clearScreen();

	char player1[MAX_NAME_LEN];
	char player2[MAX_NAME_LEN];

	askPlayersNames(player1, player2);

	int winner = mainCycle(player1, player2);

	showWinner(winner, (winner == PLAYER_1) ? player1 : player2);

	getchar();

	char c = 0;
	while (c != 'y') {
		printf("\nContinue? (y): ");
		scanf("%c", &c);
	}

	clearScreen();
}

int mainCycle(char* player1, char* player2) {
	char* players[] = { player1, player2 };

	int heaps[HEAP_COUNT];
	genHeapSize(heaps);

	int currentPlayer = PLAYER_2;

	while (sum(heaps) != 0) {
		// Changing current player
		currentPlayer = (currentPlayer + 1) % 2;

		clearScreen();
		printHeaps(heaps);

		printf("\nPlayer (#%d) %s turn\n", currentPlayer + 1, players[currentPlayer]);

		// Choosing which heap player pick from
		printf("Which heap you choose?\nNumber (1, 2, 3): ");
		int heapChoice;
		scanf("%d", &heapChoice);

		while (heapChoice < 1 || heapChoice > 3) {
			printf("Wrong choice! Enter correct number.\nNumber (1, 2, 3): ");
			scanf("%d", &heapChoice);
		}

		heapChoice--;

		// Choosing how much player pick
		printf("\nHow much you want to pick?\nNumber: ");
		int countChoice;
		scanf("%d", &countChoice);

		while (countChoice <= 0 || countChoice > heaps[heapChoice]) {
			printf("Wrong choice! Enter correct number.\nNumber: ");
			scanf("%d", &countChoice);
		}

		// Do arithmetic
		heaps[heapChoice] -= countChoice;
	}

	return currentPlayer;
}

void genHeapSize(int* heaps) {
	int i;
	for (i = 0; i < HEAP_COUNT; i++) {
		heaps[i] = rand() % 10 + 1;
	}
}

void askPlayersNames(char* p1, char* p2) {
	printf("Enter the name of first player: ");
	fgets(p1, MAX_NAME_LEN - 1, stdin);
	p1[strlen(p1) - 1] = 0;

	printf("\nEnter the name of second player: ");
	fgets(p2, MAX_NAME_LEN - 1, stdin);
	p2[strlen(p2) - 1] = 0;
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

void showWinner(int winner, char* name) {
	clearScreen();

	printf("Player (#%d) %s wins!", winner + 1, name);
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


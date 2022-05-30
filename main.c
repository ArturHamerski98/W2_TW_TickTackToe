#include <stdio.h>

void printBoard(int board[3][3]);

int main()
{
	int board[3][3] = { {1, 0, 1}, {1, 0, 1}, {1,0,0} };

	printBoard(board);
	return 0;
}

void printBoard(int board[3][3]) {
	
	int vertical = 186;
	int plus = 206;
	int horizontal = 205;

	printf("\n");
	
	printf("  %d %c %d %c %d \n", board[0][0], vertical, board[0][1], vertical, board[0][2]);
	printf(" %c%c%c%c%c%c%c%c%c%c%c\n", horizontal, horizontal, horizontal, plus, horizontal, horizontal, horizontal, plus, horizontal, horizontal, horizontal );
	printf("  %d %c %d %c %d \n", board[1][0], vertical, board[1][1], vertical, board[1][2]);
	printf(" %c%c%c%c%c%c%c%c%c%c%c\n", horizontal, horizontal, horizontal, plus, horizontal, horizontal, horizontal, plus, horizontal, horizontal, horizontal);
	printf("  %d %c %d %c %d \n", board[2][0], vertical, board[2][1], vertical, board[2][2]);
	
}

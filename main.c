#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "tickTack.h"

int main()
{
	while (1) {
		menu();

		char choice;
		choice = _getch();
		system("cls");

		switch (choice)
		{
		case '1':
		{
			modeChoose();
			choice = _getch();
			system("cls");

			// PLAYER VS PLAYER
			if (choice == '1')
			{
				char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ',' ',' '} };
				char player_sign = 'X';
				twoPlayerName();
				chooseToken();
				
				while (checkWinner(board) == ' ') {
					printBoard(board);
					selectPoint(board, player_sign);
					if (player_sign == 'X')
						player_sign = 'O';
					else
						player_sign = 'X';

				}
				printBoard(board);
				
			}
			//COMPUTER VS COMPUTER
			else if (choice == '2')
			{
				compLevel();
				srand(time(0));
				choice = _getch();
				system("cls");

				if (choice == '1')
				{
					char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ',' ',' '} };
					char player_sign = 'X';
					int comp_level = 0;
					while (checkWinner(board) == ' ') {
						printBoard(board);
						computerMove(board,comp_level,player_sign);
						if (player_sign == 'X')
							player_sign = 'O';
						else
							player_sign = 'X';

					}
					printBoard(board);
				}
				else if (choice == '2')
				{
					char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ',' ',' '} };
					char player_sign = 'X';
					int comp_level = 1;
					while (checkWinner(board) == ' ') {
						printBoard(board);
						computerMove(board, comp_level, player_sign);
						if (player_sign == 'X')
							player_sign = 'O';
						else
							player_sign = 'X';

					}
					printBoard(board);

				}
			}
			//PLAYER VS COMPUTER
			else if (choice == '3')
			{
				compLevel();
				choice = _getch();
				system("cls");
				playerName();
				int comp_level = 1;
				char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ',' ',' '} };
				char player_sign = 'X';
				while (checkWinner(board) == ' ') {
					printBoard(board);
					if (player_sign == 'X')
						selectPoint(board, player_sign);
					else
						computerMove(board, comp_level, player_sign);
					if (player_sign == 'X')
						player_sign = 'O';
					else
						player_sign = 'X';

				}
				printBoard(board);
				
			}
		}
		break;
		case '2':
		{
			return 0;
		}
		}
	}


	return 0;
}


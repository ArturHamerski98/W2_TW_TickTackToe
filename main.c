#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void menu();
void modeChoose();
void playAgain();
void compLevel();
void chooseToken();
void playerName();
void twoPlayerName();

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
					twoPlayerName();			
				}
				//COMPUTER VS COMPUTER
				else if (choice == '2')
				{
					compLevel();
					choice = _getch();
					system("cls");

					if (choice == '1')
					{

					}
					else if (choice == '2')
					{

					}
				}
				//PLAYER VS COMPUTER
				else if (choice == '3')
				{
					compLevel();			
					choice = _getch();
					system("cls");

					if (choice == '1')
					{
						playerName();
					}
					else if (choice == '2')
					{
						playerName();
					}
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

void menu()
{
	printf(" ____________________________________\n");
	printf("|          TIC - TAC - TOE           |\n");
	printf("|====================================|\n");
	printf("|                                    |\n");
	printf("|              1.START               |\n");
	printf("|              2.EXIT                |\n");
	printf("|                                    |\n");
	printf("|____________________________________|\n\n");

}
void modeChoose()
{
	printf("      CHOOSE GAME MODE        \n");
	printf("-------------------------------\n");
	printf("   1. PLAYER VS PLAYER         \n");
	printf("   2. COMPUTER VS COMPUTER     \n");
	printf("   3. COMPUTER VS PLAYER     \n\n");
}
void playAgain()
{
	printf("            GAME OVER            \n");
	printf("---------------------------------\n");
	printf("  Would you like to play again?  \n\n");
	printf("            1.YES                \n");
	printf("            2.NO                 \n\n");

}
void compLevel()
{
	printf("      CHOOSE COMPUTER LEVEL      \n");
	printf("---------------------------------\n");
	printf("            1.DUMMY              \n");
	printf("            2.MASTERMIND         \n\n");
}
void chooseToken()
{
	printf("      CHOOSE YOUR TOKEN      \n");
	printf("---------------------------------\n");
	printf("            1.X              \n");
	printf("            2.O         \n\n");
}
void playerName()
{
	char nick[10];
	printf("Enter your nickname: ");
	scanf_s("%s", &nick,9);
	printf("Player: %s\n", nick);
	printf("Player: %s", nick);
}
void twoPlayerName()
{
	char nick[10], nickTwo[10];
	printf("Enter your nickname: ");
	fgets(nick, 10, stdin);
	printf("Enter your nickname: ");
	fgets(nickTwo, 10, stdin);
	printf("\nPlayer 1: %s", nick);
	printf("Player 2: %s\n\n", nickTwo);
}

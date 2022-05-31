#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "tictac.h"
#include <time.h>

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
				pVp();
			}
			//COMPUTER VS COMPUTER
			else if (choice == '2')
			{
				cVc();
			}
			//PLAYER VS COMPUTER
			else if (choice == '3')
			{
				pVc();
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

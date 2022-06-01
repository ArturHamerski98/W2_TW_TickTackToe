#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

void menu();
void modeChoose();
void playAgain();
void compLevel();
void chooseToken();
void playerName();
void twoPlayerName();
void printBoard(char board[3][3]);
int  isNumber(char number[]);
char checkWinner(char board[3][3]);
char checkHypoteticWinner(char board[3][3], int x, int y, char player_sign);
void selectPoint(char board[3][3], char player_sign);
int checkIfOccupied(int x, int y, char board[3][3]);
int checkIfOutside(int x, int y);
void computerMove(char board[3][3], int comp_level, char player_sign);
void pVp();
void cVc();
void pVc();
void offTimmer(clock_t start);
void getPlayerName(char nick[30]);

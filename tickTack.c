#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "tickTack.h"

#pragma warning(disable: 4996)

void menu() {
    printf(" ____________________________________\n");
    printf("|          TIC - TAC - TOE           |\n");
    printf("|====================================|\n");
    printf("|                                    |\n");
    printf("|              1.START               |\n");
    printf("|              2.EXIT                |\n");
    printf("|                                    |\n");
    printf("|____________________________________|\n\n");

}
void modeChoose() {
    printf("      CHOOSE GAME MODE        \n");
    printf("-------------------------------\n");
    printf("   1. PLAYER VS PLAYER         \n");
    printf("   2. COMPUTER VS COMPUTER     \n");
    printf("   3. COMPUTER VS PLAYER     \n\n");
}
void playAgain() {
    printf("            GAME OVER            \n");
    printf("---------------------------------\n");
    printf("  Would you like to play again?  \n\n");
    printf("            1.YES                \n");
    printf("            2.NO                 \n\n");

}
void compLevel() {
    printf("      CHOOSE COMPUTER LEVEL      \n");
    printf("---------------------------------\n");
    printf("            1.DUMMY              \n");
    printf("            2.MASTERMIND         \n\n");
}
void chooseToken() {
    printf("      CHOOSE YOUR TOKEN      \n");
    printf("---------------------------------\n");
    printf("            1.X              \n");
    printf("            2.O         \n\n");
}
void playerName() {
    char nick[10];
    printf("Enter your nickname: ");
    scanf_s("%s", &nick, 9);
    printf("Player: %s\n", nick);
    printf("Player: %s", nick);
}
void twoPlayerName() {
    char nick[10], nickTwo[10];
    printf("Enter your nickname: ");
    fgets(nick, 10, stdin);
    printf("Enter your nickname: ");
    fgets(nickTwo, 10, stdin);
    printf("\nPlayer 1: %s", nick);
    printf("Player 2: %s\n\n", nickTwo);
}

void printBoard(char board[3][3]) {

    int vertical = 186;
    int plus = 206;
    int horizontal = 205;

    printf("\n");

    printf("  %c %c %c %c %c \n", board[0][0], vertical, board[0][1], vertical, board[0][2]);
    printf(" %c%c%c%c%c%c%c%c%c%c%c\n", horizontal, horizontal, horizontal, plus, horizontal, horizontal, horizontal, plus, horizontal, horizontal, horizontal);
    printf("  %c %c %c %c %c \n", board[1][0], vertical, board[1][1], vertical, board[1][2]);
    printf(" %c%c%c%c%c%c%c%c%c%c%c\n", horizontal, horizontal, horizontal, plus, horizontal, horizontal, horizontal, plus, horizontal, horizontal, horizontal);
    printf("  %c %c %c %c %c \n", board[2][0], vertical, board[2][1], vertical, board[2][2]);

}

void selectPoint(char board[3][3], char player_sign) {
    char x0[100];
    int y0[100]; ///nie czaj�, czemu tu char a tu int????
    printf("Enter row #(1-3): ");
    scanf("%s", &x0);

    printf("Enter column #(1-3): ");
    scanf("%s", &y0);

    int x = isNumber(x0);
    int y = isNumber(y0);

    int CHECKIFOUTSIDE = checkIfOutside((x), (y));
    int CHECKIFOCCUPIED = 0;
    if (CHECKIFOUTSIDE == 0)
        CHECKIFOCCUPIED = checkIfOccupied((x - 1), (y - 1), board);

    if (CHECKIFOCCUPIED == 0 && CHECKIFOUTSIDE == 0) {
        x--;
        y--;
        board[x][y] = player_sign;
    }
    else
        selectPoint(board, player_sign);

}

int isNumber(char number[]) {
    int i = 0;

    //checking for negative numbers
    if (number[0] == '-') {
        printf("Invalid input!");
        exit(1);
    }

    for (; number[i] != 0; i++) {
        if (number[i] > '9' || number[i] < '0') {

            printf("Invalid input!");
            exit(1);
        }
    }
    int x = atoi(number);
    return x;
}

char checkWinner(char board[3][3]) {
    //check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }
    //check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        }
    }
    //check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }

    return ' ';
}
char checkHypoteticWinner(char board[3][3], int x, int y, char player_sign) {
    char temp = board[x][y];
    char temp2;
    board[x][y] = player_sign;

    //check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            temp2 = board[i][0];
            board[x][y] = temp;
            return temp2;
        }
    }
    //check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            temp2 = board[0][i];
            board[x][y] = temp;
            return temp2;
        }
    }
    //check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        temp2 = board[0][0];
        board[x][y] = temp;
        return temp2;
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        temp2 = board[0][2];
        board[x][y] = temp;
        return temp2;
    }

    board[x][y] = temp;
    return ' ';
}

void computerMove(char board[3][3], int comp_level, char player_sign) {
    if (comp_level == 0) {

        int x = rand() % 3;
        int y = rand() % 3;

        int CHECKIFOCCUPIED = checkIfOccupied((x), (y), board);

        if (CHECKIFOCCUPIED == 0) {

            board[x][y] = player_sign;
        }
        else
            computerMove(board, comp_level, player_sign);
    }
    if (comp_level == 1) {
        int x;
        int y;
        int status = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ((checkHypoteticWinner(board, i, j, player_sign) == player_sign) && (checkIfOccupied(i, j, board)) == 0) {
                    x = i;
                    y = j;
                    status = 1;

                }
            }
        }
        if (player_sign == 'X')
            player_sign = 'O';
        else
            player_sign = 'X';
        if (status == 0) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if ((checkHypoteticWinner(board, i, j, player_sign) == player_sign) && (checkIfOccupied(i, j, board)) == 0) {
                        x = i;
                        y = j;
                        status = 1;

                    }
                }
            }
        }
        if (player_sign == 'X')
            player_sign = 'O';
        else
            player_sign = 'X';
        if (status == 0) {
            int x = rand() % 3;
            int y = rand() % 3;
            int CHECKIFOCCUPIED = checkIfOccupied((x), (y), board);

            if (CHECKIFOCCUPIED == 0) {

                board[x][y] = player_sign;
            }
            else
                computerMove(board, comp_level, player_sign);

        }
        else
            board[x][y] = player_sign;

    }

}
int checkIfOccupied(int x, int y, char board[3][3]) {
    int occupied = 0;

    if (board[x][y] != ' ') {
        //printf("Invalid move! The entered coordinates pointing to an already occupied spot!\n");
        occupied = 1;
    }
    return occupied;
}
int checkIfOutside(int x, int y) {
    int outside = 0;
    if (x < 1 || x > 3 || y < 1 || y > 3) {
        printf("The entered coordinates are outside of the board!\n");
        outside = 1;
    }
    return outside;
}
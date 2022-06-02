#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "ticTac.h"
#include <string.h>

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
    printf("   3. COMPUTER VS PLAYER       \n");
    printf("   4. HALL OF FAME             \n");
    printf("   5. AI STATS                \n\n");
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
void getPlayerName(char nick[30]) {

    
    scanf("%s", nick);
   
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
    char y0[100];
    printf("\nEnter row #(1-3): ");
    scanf("%s", &x0);

    printf("Enter column #(1-3): ");
    scanf("%s", &y0);

    int x = isNumber(x0);
    int y = isNumber(y0);

    if (x == -1 || y == -1) {
        printf("Invalid input!\n");
        selectPoint(board, player_sign);
    }

    int CHECKIFOUTSIDE = checkIfOutside((x), (y));
    int CHECKIFOCCUPIED = 0;
    if (checkIfOutside((x), (y)) == 0)
        CHECKIFOCCUPIED = userCheckIfOccupied((x - 1), (y - 1), board);

    if (CHECKIFOCCUPIED == 0 && CHECKIFOUTSIDE == 0) {
        x--;
        y--;
        board[x][y] = player_sign;
    }
    else
        selectPoint(board, player_sign);

}

int isNumber(char number[]) { // returning -1 in case there is an invalid input
    int i = 0;

    //checking for negative numbers
    if (number[0] == '-')
        return -1;

    for (; number[i] != 0; i++) {
        if (number[i] > '9' || number[i] < '0')
            return -1;
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
    if (comp_level == 1) {

        int x = rand() % 3;
        int y = rand() % 3;

        int CHECKIFOCCUPIED = checkIfOccupied((x), (y), board);

        if (CHECKIFOCCUPIED == 0) {

            board[x][y] = player_sign;
        }
        else
            computerMove(board, comp_level, player_sign);
    }
    if (comp_level == 2) {
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
        occupied = 1;
    }
    return occupied;
}
int userCheckIfOccupied(int x, int y, char board[3][3]) {
    int occupied = 0;

    if (board[x][y] != ' ') {
        printf("Invalid move! The entered coordinates pointing to an already occupied spot!\n");
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
void pVp() {
    char board[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '}, 
                         {' ', ' ', ' '} };
    char choice;
    char player_sign = 'X';

    printf("Enter name: ");
    char FirstPlayerName[30];
    getPlayerName(FirstPlayerName);
    printf("Enter name: ");
    char SecondPlayerName[30];
    getPlayerName(SecondPlayerName);

    printf("         %s\n", FirstPlayerName);
    printf("          vs \n");
    printf("         %s\n", SecondPlayerName);

    chooseToken();
    choice = _getch();
    if (choice == '1') {
        clock_t start = clock();
        int move = 0;
        while ((checkWinner(board) == ' ') && (move < 9)) {
            printBoard(board);

            if (move % 2 == 0)
                printf("%s", FirstPlayerName);
            else
                printf("%s", SecondPlayerName);

            selectPoint(board, player_sign);
            system("cls");
            if (player_sign == 'X')
                player_sign = 'O';
            else
                player_sign = 'X';
            move++;
        }
        printBoard(board);
        if (checkWinner(board) ==' ')
            printf("DRAW!\n");
        else if (move % 2 == 0)
            printf("WINNER: %s\n", SecondPlayerName);
        else
            printf("WINNER: %s\n", FirstPlayerName);

        printf("Number of moves %d\n", move);
        offTimmer(start);
    }
    else if (choice == '2') {
        clock_t start = clock();
        int move = 0;
        while ((checkWinner(board) == ' ') && (move < 9)) {
            printBoard(board);

            if (move % 2 == 0)
                printf("%s", SecondPlayerName);
            else
                printf("%s", FirstPlayerName);

            selectPoint(board, player_sign);
            system("cls");
            if (player_sign == 'X')
                player_sign = 'O';
            else
                player_sign = 'X';
            move++;
        }
        printBoard(board);
        if (checkWinner(board) == ' ')
            printf("DRAW!\n");
        else if (move % 2 == 0)
            printf("WINNER: %s\n", FirstPlayerName);
        else
            printf("WINNER!: %s\n", SecondPlayerName);

        printf("Number of moves %d\n", move);
        offTimmer(start);
    }

}
void cVc() {
    srand(time(0));

    int comp1lvl;
    int comp2lvl;

    compLevel();
    scanf("%d", &comp1lvl);
    compLevel();
    scanf("%d", &comp2lvl);
    system("cls");

    char board[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };
    char player_sign = 'X';
    int comp_level = comp1lvl;
    clock_t start = clock();
    int move = 0;
    while ((checkWinner(board) == ' ') && (move < 9)) {
        printBoard(board);
        computerMove(board, comp_level, player_sign);
        if (player_sign == 'X')
            player_sign = 'O';
        else
            player_sign = 'X';

        if (comp_level == comp1lvl)
            comp_level = comp2lvl;
        else
            comp_level = comp1lvl;
        move++;

    }
    printBoard(board);
    if (checkWinner(board) == ' ')
        printf("DRAW!\n");
    else if (checkWinner(board) == 'X')
        printf("WINNER: X");
    else
        printf("WINNER!: O");

    printf("Number of moves %d\n", move);
    offTimmer(start);

}
void pVc() {
    char choice;
    int comp1lvl;

    char board[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };
    char player_sign = 'X';

    int move = 0;
    printf("Enter name: ");
    char FirstPlayerName[30];
    getPlayerName(FirstPlayerName);

    compLevel();
    scanf("%d", &comp1lvl);
    system("cls");
    int comp_level = comp1lvl;

    chooseToken();
    choice = _getch();
    clock_t start = clock();
    if (choice == '1') {
        while (checkWinner(board) == ' ') {
            printBoard(board);

            if (player_sign == 'X') {
                printf("MOVE: %s\n", FirstPlayerName);
                selectPoint(board, player_sign);
            }
            else {
                printf("Computer move\n");
                computerMove(board, comp_level, player_sign);
            }
            if (player_sign == 'X')
                player_sign = 'O';
            else
                player_sign = 'X';
            move++;
        }
        printBoard(board);
        if (checkWinner(board) == ' ')
            printf("DRAW!\n");
        else if (move % 2 == 0)
            printf("WINNER: Computer\n");
        else {
            printf("WINNER: %s\n", FirstPlayerName);
            updateProList(move, returnTime(start), FirstPlayerName);
        }

        printf("Number of moves %d\n", move);
        offTimmer(start);
    }
    else if (choice == '2') {
        while (checkWinner(board) == ' ') {
            printBoard(board);

            if (player_sign == 'X') {
                printf("Computer move\n");
                computerMove(board, comp_level, player_sign);
            }
            else {
                printf("MOVE: %s\n", FirstPlayerName);
                selectPoint(board, player_sign);
            }
            if (player_sign == 'X')
                player_sign = 'O';
            else
                player_sign = 'X';
            move++;
        }
        printBoard(board);
        if (checkWinner(board) == ' ')
            printf("DRAW!\n");
        else if (move % 2 == 0) {
            printf("WINNER: %s\n", FirstPlayerName);
            updateProList(move, returnTime(start), FirstPlayerName);
        }
        else
            printf("WINNER: Computer\n");

        printf("Number of moves %d\n", move);
        offTimmer(start);
    }
}

void offTimmer(clock_t start) {
    clock_t end = clock();
    clock_t time = end - start;
    double time_in_sec = ((double)time) / CLOCKS_PER_SEC; // calculate the elapsed time
    printf("Time of the game: %f seconds\n", time_in_sec);

}

float returnTime(clock_t start) {
    clock_t end = clock();
    clock_t time = end - start;
    double time_in_sec = ((double)time) / CLOCKS_PER_SEC; // calculate the elapsed time

    return (float)time_in_sec;
}

void updateProList(int moves, float time, char* name) {

    struct pros pro[6];

    FILE* fptr;
    fptr = fopen("program.txt", "r");
    char singleLine[150];
    int temp = 0;
    int temp2 = 0;

    while (!feof(fptr)) {
        fgets(singleLine, 150, fptr);
        if (temp % 3 == 0)
            pro[temp2].moves = atoi(singleLine);
        else if ((temp - 1) % 3 == 0) {
            pro[temp2].time = atof(singleLine);

        }
        else {
            strcpy(pro[temp2].name, singleLine);
            pro[temp2].name[strlen(pro[temp2].name) - 1] = '\0';
            temp2++;
        }

        temp++;

    }

    fclose(fptr);

    pro[5].moves = moves;
    pro[5].time = time;
    strcpy(pro[5].name, name);
    pro[5].name[strlen(pro[5].name) - 1] = '\0';

    sortProList(pro);

    fptr = fopen("program.txt", "w");

    for (int i = 0; i < 5; i++) {
        if (i == 4) {
            fprintf(fptr, "%d\n", pro[i].moves);
            fprintf(fptr, "%f\n", pro[i].time);
            fprintf(fptr, "%s", pro[i].name);
        }
        else {
            fprintf(fptr, "%d\n", pro[i].moves);
            fprintf(fptr, "%f\n", pro[i].time);
            fprintf(fptr, "%s\n", pro[i].name);
        }

    }

    fclose(fptr);
}

void sortProList(struct pros list[6]) {
    int s = 6;
    int i, j;
    struct pros temp;

    for (i = 0; i < s - 1; i++) {
        for (j = 0; j < (s - 1 - i); j++) {
            if (list[j].time > list[j + 1].time) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void printHallOfFame() {

    struct pros pro[6];
    FILE* fptr;
    fptr = fopen("program.txt", "r");
    char singleLine[150];
    int temp = 0;
    int temp2 = 0;

    while (!feof(fptr)) {
        fgets(singleLine, 150, fptr);
        if (temp % 3 == 0)
            pro[temp2].moves = atoi(singleLine);
        else if ((temp - 1) % 3 == 0) {
            pro[temp2].time = atof(singleLine);

        }
        else {
            strcpy(pro[temp2].name, singleLine);
            pro[temp2].name[strlen(pro[temp2].name) - 1] = '\0';
            temp2++;
        }

        temp++;

    }

    fclose(fptr);
    for (int j = 0; j < 5; j++) {
        printf("%d. Name: %s || Seconds: %f || Moves: %d\n", j + 1, pro[j].name, pro[j].time, pro[j].moves);
    }
  
}

struct result AiCheck(int com1, int com2) {
    struct result results;
    results.win = 0;
    results.lose = 0;
    srand(time(0));
    int comp1_wins = 0;
    
    int comp1lvl = com1;
    int comp2lvl = com2;
    for (int i = 0; i < 1000; i++) {
        

        char board[3][3] = { {' ', ' ', ' '},
                             {' ', ' ', ' '},
                             {' ', ' ', ' '} };
        char player_sign = 'X';
        int comp_level = comp1lvl;
        int move = 0;
        while ((checkWinner(board) == ' ') && (move < 9)) {
            printBoard(board);
            computerMove(board, comp_level, player_sign);
            if (player_sign == 'X')
                player_sign = 'O';
            else
                player_sign = 'X';

            if (comp_level == comp1lvl)
                comp_level = comp2lvl;
            else
                comp_level = comp1lvl;
            move++;

        }
        printBoard(board);
        if (move > 8)
            printf("DRAW!\n");
        printf("Number of moves %d\n", move);

        if (checkWinner(board) == 'X')
            results.win++;
        if (checkWinner(board) == 'O')
            results.lose++;

    }
    return results;
}

void statsOfAi() {

    struct result MVD = AiCheck(2, 1);
    struct result DVM = AiCheck(1, 2);
    struct result MVM = AiCheck(2, 2);
    struct result DVD = AiCheck(1, 1);

    printf("Mastermind (X) vs Dummy (O) WINS %d%%  LOSES %d%%  DRAWS %d%%\n", MVD.win / 10, MVD.lose / 10, ((1000 - MVD.win - MVD.lose) / 10));
    printf("Dummy (X) vs Mastermind (O) WINS %d%%  LOSES %d%%  DRAWS %d%%\n", DVM.win / 10, DVM.lose / 10, ((1000 - DVM.win - DVM.lose) / 10));
    printf("Mastermind (X) vs Mastermind (O) WINS %d%%  LOSES %d%%  DRAWS %d%%\n", MVM.win / 10, MVM.lose / 10, ((1000 - MVM.win - MVM.lose) / 10));
    printf("Dummy (X) vs Dummy (O) WINS %d%%  LOSES %d%%  DRAWS %d%%\n", DVD.win / 10, DVD.lose / 10, ((1000 - DVD.win - DVD.lose) / 10));
}

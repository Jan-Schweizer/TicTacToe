#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void init(void);

void drawBoard(void);

void markBoard(int player);

int checkForWin();

char board[3][3];

int main()
{
    init();
    int player = 1;
    int running = 0;
    drawBoard();
    while (running == 0) {
        markBoard(player);
        player = player == 1 ? 2 : 1;
        running = checkForWin();
        drawBoard();
    }

    switch (running) {
        case 1:
            printf("\nPlayer 1 wins!\n\n");
            break;
        case 2:
            printf("\nPlayer 2 wins!\n\n");
            break;
        case 3:
        default:
            printf("\nDraw!\n\n");
            break;
    }

    return 0;
}

/*
0 No Winner
1 1st Player wins
2 2nd Player wins
3 Draw
*/
int checkForWin()
{
    /* Checking Rows */
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0] == 'X' ? 1 : 2;
        }
    }
    /* Checking Columns */
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i] == 'X' ? 1 : 2;
        }
    }

    /* Checking Diagonals */
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0] == 'X' ? 1 : 2;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2] == 'X' ? 1 : 2;

    /*If any of the chars is still a number it's not a draw yet */
    _Bool draw = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (isdigit(board[i][j]) != 0)
                draw = false;
        }
    }
    if (draw)
        return 3;

    return 0;
}

void markBoard(int player)
{
    int position;
    int i = 0;
    int j = 0;

    _Bool validMove = false;
    while (!validMove) {
        validMove = true;
        printf("\n\nPlayer %d, enter a number: ", player);
        scanf("%d", &position);
        if (position < 1 || position > 9) {
            printf("Invalid move\n");
            validMove = false;
            continue;
        }
        switch (position) {
            case 1:
                i = 2, j = 0;
                break;
            case 2:
                i = 2, j = 1;
                break;
            case 3:
                i = 2, j = 2;
                break;
            case 4:
                i = 1, j = 0;
                break;
            case 5:
                i = 1, j = 1;
                break;
            case 6:
                i = 1, j = 2;
                break;
            case 7:
                i = 0, j = 0;
                break;
            case 8:
                i = 0, j = 1;
                break;
            case 9:
            default:
                i = 0, j = 2;
                break;
        }
        if (board[i][j] == 'X' || board[i][j] == 'O') {
            printf("Invalid move\n");
            validMove = false;
        }
    }

    board[i][j] = (char) (player == 1 ? 'X' : 'O');

}

void drawBoard(void)
{
    system("cls");
    printf("\n\tTic Tac Toe\n");
    printf("\nPlayer 1 (X)  -  Player 2 (O)\n");


    for (int i = 0; i < 3; i++) {
        printf("\n   |   |   \n");
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2)
            printf("___|___|___");
        else
            printf("   |   |   ");
    }
}

/* Initialize the char array with numbers in order of the numpad */
void init()
{
    char number = 1;
    for (int i = 2; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = (char) (number++ + '0');
        }
    }
}
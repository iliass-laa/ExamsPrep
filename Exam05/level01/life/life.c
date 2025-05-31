#include "life.h"


void printBoard(char **board)
{
    int i, j;
    i = 0;
    j = 0;
    if(!board)
        return;
    while (board[i])
    {
        j = 0;
        while (board[i][j])
        {
            putchar(board[i][j]);
            j++;
        }
        putchar('\n');
        i++;
    }
}

void life(char **av)
{
    t_life obj;

    init(&obj, av);
    game (&obj);
    printBoard(obj.map);
    freeBoard(obj.map);
    free(obj.commands);
}
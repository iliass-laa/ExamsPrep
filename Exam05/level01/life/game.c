#include "life.h"
int shouldDie(t_life *obj, int i, int j)
{
    int iTmp, jTmp, liveN;
    liveN = 0;
    if (i > 0)
        iTmp = i - 1;
    else  
        iTmp = i;
    while (iTmp < obj->height && iTmp  <= i + 1 )
    {
         if (j > 0)
            jTmp = j - 1;
        else  
            jTmp = j;
        while (jTmp < obj->width && jTmp <= j+1)
        {
            if (i != iTmp || j != jTmp)
            {
                if (obj->map[iTmp][jTmp] == '0')
                {
                    liveN ++;
                }
            }
            jTmp ++;
        }
        iTmp ++;
    }
    if (liveN < 2 || liveN > 3)
        return 1;
    return 0;
}
int shouldReBorn(t_life *obj, int i, int j)
{
    int iTmp, jTmp, liveN;
    liveN = 0;
    if (i > 0)
        iTmp = i - 1;
    else  
        iTmp = i;
    while (iTmp < obj->height && iTmp  <= i + 1 )
    {
        if (j > 0)
            jTmp = j - 1;
        else  
            jTmp = j;
        while (jTmp < obj->width && jTmp <= j+1)
        {
            if (i != iTmp || j != jTmp)
            {
                if (obj->map[iTmp][jTmp] == '0')
                    liveN ++;
            }
            jTmp ++;
        }
        iTmp ++;
    }
    if (liveN == 3)
        return 1;
    return 0;
}

int checkCell(t_life *obj, int i, int j)
{
    int res = ' ';

    if (obj->map[i][j] == '0' && !shouldDie(obj, i, j))
        res =  '0';
    if (obj->map[i][j] == ' ' && shouldReBorn(obj, i, j))
        res = '0';
    return res;
}

char ** regenrateBoard(t_life *obj)
{
    int i , j;

    i = 0;
    j = 0;
    int x = 0;
    char **newBoard;
    newBoard = (char **)malloc(sizeof (char *) *( obj->height + 1));
    while(x < obj->width)
    {
        newBoard[x] = (char *)malloc( obj->width + 1);
        x++;
    }
    newBoard[x] = NULL;
    i = 0;
    while (i < obj->height)
    {
        j = 0;
        while (j < obj->width)
        {
            newBoard[i][j] = checkCell(obj, i, j);
            j++;
        }
        newBoard[i][j] = '\0';
        i++;
    }
    newBoard[i] = NULL;
    freeBoard(obj->map);
    obj->map = NULL;
    return newBoard;
}

void game(t_life *obj)
{
    int gen;
    gen = 0;
    while (gen < obj->iterations)
    {
        obj->map = regenrateBoard(obj);
        gen++;
    }
}
#include "bsq.h"


int ft_strlen(char *s)
{
    int i=0;
    if (!s)
        return i;
    while (s[i])
        i++;
    return i;
}


int fillPaddingMap(t_bsq *obj)
{
    obj->padMap = (int **)malloc(sizeof(int *) * (obj->mapLen + 2));
    if (!obj->padMap)
        return 1;
    int i , j;
    i = 0;
    while (i <= obj->mapLen)
    {
        j = 0;
        obj->padMap[i] = (int *)malloc(sizeof(int) * (obj->mapWidth + 1));
        while(j<= obj->mapWidth)
        {
            if (i == 0 || j == 0)
                obj->padMap[i][j] = 0;
            else
                obj->padMap[i][j] = -1;
            j++;
        }
        i++;
    }
    obj->padMap[i] = NULL;
    return 0;
}


void printPadMap(t_bsq *obj,int **map)
{
    int i , j;
    i = 0;
    if (!map)
        return;
    while(map[i])
    {
        j = 0;
        while (j <= obj->mapWidth)
        {
            printf(" %d ", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}


void printMap(char **map)
{
    int i = 0;
    if (!map)
        return;

    while (map[i])
        fprintf(stdout, "%s\n", map[i++]);
}
#include "bsq.h"

int getMin(t_bsq *obj, int i ,int j)
{
    int min;
    min = obj->padMap[i - 1][j - 1];
    if (min > obj->padMap[i - 1][j])
        min = obj->padMap[i - 1][j];
    if (min > obj->padMap[i][j - 1])
        min = obj->padMap[i][j - 1];
    return min;
}


void coreBsq(t_bsq *obj)
{
    if (fillPaddingMap(obj))
        return;
    int i, j, min;
    i = 0;
    while (obj->map[i])
    {
        j = 0;
        while (j < obj->mapWidth)
        {
            if (obj->map[i][j] == obj->empty)
            {
                min = getMin(obj, i + 1, j + 1);

                obj->padMap[i+1][j+1] = min + 1;
                if (min + 1 >  obj->biggestSide)
                {
                    obj->biggestSide = min + 1;
                    obj->i = i;
                    obj->j = j;
                }
            }
            else
                obj->padMap[i+1][j+1] = 0;
            // printf(" %d ",obj->padMap[i+1][j+1]);
            j++;
        }
            // printf("\n");
        i++;
    }
}

void Initialize(t_bsq *obj)
{
    obj->biggestSide = 0;
    obj->mapLen = 0;
    obj->mapWidth = 0;
    obj->map = NULL;
    obj->padMap = NULL;
    obj->full = 0;
    obj->empty = 0;
    obj->obstacle = 0;
    obj->obstacleCount = 0;
    obj->j = 0;
    obj->i = 0;
}

void reWriteMap(t_bsq *obj)
{
    int i , j;
    i = 0;
    while (i < obj->biggestSide)
    {
        j = 0;
        while (j < obj->biggestSide)
        {
            obj->map[obj->i - i][obj->j - j] = obj->full;
            j++;
        }
        i++;
    }
}

void findBsq(char *path)
{
    t_bsq obj;
    FILE *fd ;
    if (path)
        fd = fopen(path, "r");
    else
        fd = stdin;
    Initialize(&obj);
    if (!fd || parse(&obj, fd))
        fprintf(stderr, "map error\n");
    else
    {
        coreBsq(&obj);
        
        printf("FindBsq All Good\n");
        // printPadMap(&obj, obj.padMap);
        printf("i :%d, j %d, biggestSideL:%d\n", obj.i, obj.j, obj.biggestSide);
        reWriteMap(&obj);
    }   
    freeMyObj(&obj);
    // printBsq(obj);
}


void bsq(int ac, char **av)
{
    int i =0;
    if (ac)
    {
        while (i < ac)
        {
            findBsq(av[i]);
            i++;
        }
    }
    else
        findBsq(NULL);
}
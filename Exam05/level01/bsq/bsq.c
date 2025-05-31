#include "bsq.h"

void   refillMap(t_maps *obj)
{
    int i,j;
    i = 0;
    while (i< obj->bsq.side)
    {
        j= 0;
        while (j< obj->bsq.side)
        {
            obj->map[obj->bsq.y + i][obj->bsq.x + j] = obj->full;
            j++;
        }
        i++;
    }
}

int findObstacl(char *line, char obstacle)
{
    if (!line)
        return 0;
    int i = 0;
    while (line[i])
    {
        if (line[i] == obstacle)
            return i;
        i++;
    }
    return i;
}

void updateBsq(t_maps *obj, int i, int j)
{
  int currSide , x, y, breaking;
  
    y = 0;
    breaking = 0;
    currSide  = 0;
    if (obj->map[i][j] ==  obj->obstacle)
        return;
    while (i + y < obj->mapLen)
    {
        x = 0;
        if (breaking)
                break;
        while (j + x < obj->mapWidth)
        {
            if (breaking)
                break;
            if (obj->map[i + y] [j + x] == obj->obstacle)
            {
                if (!currSide)
                {
                    currSide = x;
                }
                if (x < currSide)
                {
                    currSide = x;
                }
                if (currSide < x && y > x)
                {
                    breaking = 1;
                }
            }
            x++;
        }
        y++;
    }

}

void findBsq(t_maps *obj)
{
    int i , j;
    i = 0;
    obj->bsq.closeO = 0;
    obj->bsq.side = 0;
    obj->bsq.x = 0;
    obj->bsq.y = 0;
    while (i < obj->mapLen)
    {
        j = 0;
        while (j < obj->mapWidth)
        {
            updateBsq(obj, i, j);
            // if (i == 0 && j == 0)//TMP CONDITION !!
            //     break;
            j++;
        } 
        // break;
        i++;
    }
    printf("S>>%d\n", obj->bsq.side);
    refillMap(obj);
    //Rewrite the Full Char in the Map !!   
}


void bsq(int ac, char **av)
{
    t_infos infos;
    init(&infos, ac, av);

    
    int i = 0;
    while (i < infos.nbrsMaps)
    {
        // findBsq(&infos.pr[i]);
        printMap(&infos.pr[i]);
        i++;
    }
    freeMaps(infos.pr, infos.nbrsMaps);
    free(infos.pr);

}
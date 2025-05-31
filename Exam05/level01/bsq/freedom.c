#include "bsq.h"


void freeMap(void **map, int c)
{
    int i =0;
    (void)c;
    // if (c)
    //     map = (int **)map;
    // else
    //     map = (char **)map;
    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void freeMaps(t_maps *ptr, int nbrMaps)
{
    int i = 0;
    while (i < nbrMaps)
    {
        // free(ptr[i].mapInfo);
        freeMap((void **)ptr[i].map, 0);
        freeMap((void **)ptr[i].tmpMap, 1);
        i++;
    }
}
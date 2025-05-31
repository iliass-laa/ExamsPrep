#include "bsq.h"

void freeDoubleArray(void **array)
{
    if (!array)
        return;
    int i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }   
    free(array);
}

void freeMyObj(t_bsq *obj)
{
    freeDoubleArray((void **)obj->padMap);
    freeDoubleArray((void **)obj->map);
}
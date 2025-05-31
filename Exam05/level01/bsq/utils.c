#include "bsq.h"


void printMap(t_maps *pr)
{
    int i , j;
    i = 0;
    if (!pr || pr->map == NULL)
        return;
    while (pr->map[i])
    {
        j = 0;
        while (pr->map[i][j])
        {
            putchar(' ');
            putchar(pr->map[i][j]);
            j++;
        }
        // printf("%s", pr->map[i]);
        i++;
    }
}
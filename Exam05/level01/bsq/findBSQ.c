#include "bsq.h"


void   reWriteMap(t_maps *obj)
{
    int i,j;
    i = 0;
    while (i< obj->mapLen)
    {
        j= 0;
        while (j< obj->mapWidth)
        {
            if (obj->map[i][j] == obj->full)
                obj->map[i][j] = '1';
            if (obj->map[i][j] == obj->empty)
                obj->map[i][j] = '0';
            // obj->map[i][j] = obj->full;
            j++;
        }
        i++;
    }
}

int min(int **map, int i, int j)
{
    if (i > 0)
        i--;
    if (j > 0)
        j--;
    int min;
    min = map[i][j];
    if (min > map[i + 1][j])
        min = map[i + 1][j];
    if (min > map[i][j + 1])
        min = map[i][j + 1];
    return (min);
}


// void findBSQ(t_maps *pr)
// {
//     int i, j;

//     i = 1;
//     j = 1;
//     char min;
//     // reWriteMap(pr);
//     while (i <= pr->mapLen)
//     {
//         j = 1;
//         while (j <= pr->mapLen)
//         {
//             if (pr->map[i - 1][j - 1] == '0')
//             {
//                 min = min()

//             }
//             else
//             {
//                 // pr->tm
//             }

//             j++;
//         }
//         i++;
//     }
// }

#include "bsq.h"

void mapFaild(t_maps *pr)
{
    if (pr->map)
        freeMap((void **)pr->map, 0);
    pr->map = NULL;
}

void init(t_infos *obj, int ac, char **av)
{
    if (ac)
        obj->nbrsMaps = ac;
    else    
        obj->nbrsMaps = 1;
    obj->pr = (t_maps *)malloc(sizeof(t_maps) * obj->nbrsMaps);
    int i = 0;
    // printf("fill map ac :%d\n", ac);

    while (i < obj->nbrsMaps)
    {
        if (!ac)
        {
            printf("fill map from Stdin\n");
            if (fillMap(NULL, &obj->pr[i]))
                mapFaild(&obj->pr[i]);
        }
        else
        {
            printf("fill map from this:Path: '%s'\n", av[i]);
            if (fillMap(av[i], &obj->pr[i]))
            {
                mapFaild(&obj->pr[i]);
            }
            // obj->pr[i] = NULL;
        }
        i++;
    }
}
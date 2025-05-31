#include "bsq.h"

void smallHandel(t_bsq *obj, int i, char *line)
{
    int j = 0;
    while (j < i)
    {
        free(obj->map[j]);
        j++;
    }
    free(line);
    free(obj->map);
    obj->map= NULL;
}
int checkLine(t_bsq *obj, char *line, int prevLen)
{
    int currLen, i;

    i = 0;
    currLen = ft_strlen(line);

    if (prevLen && prevLen != currLen)
        return printf("PrevLen: %d, currLen: %d\n", prevLen, currLen),1;
    // printf("Full :>%c< | Empty :>%c< | Obstacle :>%c<",obj->full, obj->empty, obj->obstacle );
    while (line[i])
    {
        if (( line[i] != obj->obstacle  && line[i] != obj->empty ))
            return( printf("Here, line[%d]: >%c<\n", i,line[i]), 1);
        i++;
    }
    return 0;
}
int init(t_bsq *obj , FILE *fd)
{
    int i , readed, prevLen;
    size_t n;
    i = 0;
    readed =0;
    prevLen = 0;
    char *line = NULL;
    obj->map = (char **)malloc(sizeof(char *) * (obj->mapLen + 1));
    if (!obj->map)
        return 1;
    while (i < obj->mapLen)
    {
        readed = getline(&line, &n, fd);
        if (readed <= 0)
            return printf("Not enough Lines line Len :%d \n", obj->mapLen),smallHandel(obj, i, line), 1;
        // printf("line : %s\n", line);
        if (line[readed - 1] == '\n')
            line[readed - 1] = '\0';
        if (checkLine(obj, line , prevLen))
        {
            smallHandel(obj, i, line);
            return 2;
        }
        prevLen = ft_strlen(line);
        obj->map[i] = line;
        line = NULL;
        i++;
    }
    obj->mapWidth = prevLen;
    printf("Map WIdth : %d\n", obj->mapWidth);
    obj->map[i] = NULL;
    free(line);
    return 0;
}
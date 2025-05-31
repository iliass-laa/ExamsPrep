#include "bsq.h"

int checkObstacles(t_bsq *pr)
{
    int i , j;
    i = 0;
    pr->obstacleCount = 0;
    while (pr->map[i])
    {
        j = 0;
        while (pr->map[i][j])
        {
            if (pr->map[i][j] == pr->obstacle)
                pr->obstacleCount ++;
            j++;
        }
        i++;
    }
    if (pr->obstacleCount == (i * j))
        return 1;
    return 0;
}

int checkFirstLine(char *line, t_bsq *obj)
{
    if (!line)
        return 1;
    int i, lineLen;

    lineLen = ft_strlen(line);
    i = 0;
    if ( lineLen < 5 ||  (line[i] < 48 && line[i] > 57))
        return 1;
    obj->full = line[lineLen - 2];   
    obj->obstacle = line[lineLen - 3];   
    obj->empty = line[lineLen - 4];   
    line[lineLen - 4] = '\0';   
    obj->mapLen = atoi(line);
    if (obj->mapLen == 0)
        return 1;
    if (obj->full == obj->empty || obj->full == obj->obstacle)
        return 1;
    if (obj->empty == obj->obstacle)
        return 1;
    return 0;
}

int parse(t_bsq *obj, FILE *fd)
{
    char *line ;
    size_t len = 0;
    int readed, initRet;

    readed = getline(&line,&len, fd);
    if (readed <= 0 || checkFirstLine(line, obj))
        return (fprintf(stderr,"First Line Problem\n"), free(line), 1);    
    free(line);
    line = NULL;
    initRet = init(obj, fd);
    if (initRet)
        return (fprintf(stderr, "Init Problem , ret:%d\n", initRet),1);
    int check = checkObstacles(obj); 
    if (check)
        return 1;
    printf("Parse ALL GOOOD, Check Status%d\n", check);
    return 0;
}
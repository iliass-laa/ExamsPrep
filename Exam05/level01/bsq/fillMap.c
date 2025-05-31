#include "bsq.h"

int ft_strlen(char *s)
{
    int i =0;
    if (!s)
        return 0;
    while (s[i])
        i++;
    return i;
}
int checkLine(char *line, t_maps *pr, int prevLen, int lineLen)
{
    if (!line)
    {
        // return 1;
        return printf("\n<<<0\n"),1;

    }
    if (prevLen && lineLen != prevLen)
    {
        // if (line[])
        printf("Lines Not the Same, Prev:%d, LineLen: %d\n", prevLen, ft_strlen(line));
        return 1;
    }
    int i = 0;
    while(line[i])
    {
        if (line[i] != pr->obstacle && line[i] != pr->empty && line[i]!= '\n')
        {

            return printf("\n<<<2\n"),1;
        }
        i++;
    }
    // printf(">> goo Map\n");
    return 0;
}

int     initPart1(char *line,t_maps *pr)
{
    int lLen = ft_strlen(line); 
    if (lLen < 4)
        return 1;
    
    lLen--;
    pr->full = line[--lLen];
    pr->obstacle = line[--lLen];
    pr->empty = line[--lLen ];
    pr->mapLen = atoi(line);
    if (line[0] < 48 && line[0] > 57)
        return 1;
    if (pr->full == pr->obstacle || pr->full == pr->empty)
        return 1;
    if (pr->empty == pr->obstacle)
        return 1;
    printf("%d , empty: >%c<, obstacle >%c<, full : >%c<\n",pr->mapLen, pr->empty, pr->obstacle, pr->full);
    return 0;
}



void fillTmpMap(t_maps *pr)
{
    pr->tmpMap = (int **)malloc(sizeof(char *) * (pr->mapLen + 2));
    int i = 0;
    int j = 0;
    while (i <= pr->mapLen)
    {
        pr->tmpMap[i] = (int *)malloc(pr->mapWidth + 2);
        j = 0;
        while (j <= pr->mapWidth)
        {
            // pr->tmpMap[i][j] = ' ';
            if (i == 0)
                pr->tmpMap[i][j] = 0;
            if (j == 0)
                pr->tmpMap[i][j] = 1;
            j++;
        }
        pr->tmpMap[i][j] = '\0';
        i++;
    }
    pr->tmpMap[i] = NULL;
}

int fillMap(char *path,t_maps *pr)
{
    FILE* fd;

    if (!path)
        fd = stdin;
    else
        fd = fopen(path, "r");
    if (!fd)
        return 1;
    char *line = NULL;
    size_t n = 0;
    if (getline(&line, &n , fd) < 0 || initPart1(line, pr))
        return (fprintf(stderr, "Init Part1 \n"),free(line),1);
    pr->map = (char **)malloc(sizeof(char *) * (pr->mapLen + 1));
    int i = 0;
    int  prevLen , lineLen ;
    prevLen= 0;
    while (i < pr->mapLen)
    {
        // printf("in while : %d, prevLen: %d\n",i,  prevLen);
        
        if (getline(&line, &n, fd) < 0)
            return (free(line), 1);
        
        lineLen = ft_strlen(line);
        if (line[lineLen - 1] == '\n')
            lineLen--;
        if (checkLine(line, pr, prevLen, lineLen))    
            return( printf("\nLine incorrect :: %d\n", i), free(line),1);

        prevLen = lineLen;
        // printf("ftstrlen: %d, lineLen : %d\n", ft_strlen(line), lineLen);
        pr->map[i] = line;
        line = NULL;
        i++;
    }
    pr->map[i] = NULL;
    pr->mapWidth =  lineLen;
    if (pr->mapWidth < pr->mapLen)
        pr->biggestS = pr->mapWidth ;
    else
        pr->biggestS = pr->mapLen ;
    pr->bsq.side = 0;
    pr->bsq.x = 0;
    pr->bsq.y = 0;
    fillTmpMap(pr);
    (void)prevLen;
    return 0;
}
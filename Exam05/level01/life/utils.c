#include "life.h"

int ft_strlen(char *s)
{
    int i = 0;
    if (!s)
        return 0;
    while (s[i])
        i++;
    return i;
}

int ft_putstr (char *msg)
{
    if (!msg)
        return 1;
    int i = 0;
    while (msg[i])
    {
        putchar(msg[i]);
        i++;
    }
    return 0;
}

int find(int needle, char *line)
{
    int i=0;
    if (!line)
        return -2;
    while (line[i])
    {
        if (needle == line[i])
            return i;
        i++;
    }
    return -1;
}

char *ft_strjoin(char *s1, char *s2, int len)
{
    char *res ;
    int i, j,resLen, s1len , s2len;
    if (!len || !s2)
        return s1;
    i = 0;
    j = 0;
    s1len = ft_strlen (s1);
    s2len = ft_strlen (s2);
    resLen = s1len + s2len;
    if (s2len > len)
        resLen = s1len + len;
    res = (char *)malloc(resLen + 1);
    while (i < s1len)
    {
        res[i] = s1[i];
        i++;
    }
    while (i+j < resLen)
    {
        res[i + j] = s2[j];
        j++; 
    }
    res[i+j] = '\0';
    free(s1);
    return res;
}

char *readLine(int fd)
{
    if (fd < 0)
        return NULL;
    char *res, *tmp;
    int readed, pos;
    static char *left=NULL;

    tmp = (char *)malloc(11);
    res = NULL;
    if (left)
    {
        res = ft_strjoin(res, left, ft_strlen(left));
        free(left);
        left = NULL;
    }
    readed = read (fd, tmp, 10);
    tmp[10] = '\0';
    while (readed)
    {
        
        pos = find('\n', tmp);
        if (pos > 0)
        {
            res = ft_strjoin(res, tmp, pos);
            left = ft_strjoin(left, tmp + pos + 1,  ft_strlen(tmp));
            free(tmp);
            tmp = NULL;
            return (res);
        }
        else    
            res = ft_strjoin(res, tmp, ft_strlen(tmp));
        readed = read (fd, tmp, 10);
        tmp[10] = '\0';
    }
    return res;
}



void fillBoard(t_life *obj)
{
    int i,j, x;
    i = 0;
    j = 0;
    x = 0;

    while (i < obj->height)
    {
        j = 0;
        while (j < obj->width)
        {
            obj->map[i][j] = ' ';
            j++;
        }    
        i++;
    }
    i = 0;
    j = 0;
    while (obj->commands[x])
    {
        if (obj->commands[x] == UP && i > 0)
            i--;
        else if (obj->commands[x] == Left && j > 0)
            j--;
        else if (obj->commands[x] == Down && i < obj->height - 1)
            i++;
        else if (obj->commands[x] == Right && j < obj->width - 1)
            j++;
        else if(obj->commands[x] == DRAW && obj->draw)
            obj->draw = false;
        else if (obj->commands[x] == DRAW && !obj->draw)
            obj->draw = true;
        if (obj->draw)
            obj->map[i][j] = '0';
        x++;
    }
}

void init(t_life *obj, char **av)
{
    int i = 0;
    obj->width = atoi(av[0]);
    obj->height = atoi(av[1]);
    obj->iterations = atoi(av[2]);
    obj->map = (char **)malloc((obj->height + 1) * sizeof(char *));
    while (i < obj->height)
    {
        obj->map[i] = (char *)malloc(obj->width);
        i++; 
    }
    obj->map[i] =NULL;
    obj->commands = readLine(0);
    obj->draw = false;
    fillBoard(obj);
}


void freeBoard(char **board)
{
    int i;
    i = 0;
    while (board[i])
    {
        free(board[i]);
        i++;
    }
    free (board);
}
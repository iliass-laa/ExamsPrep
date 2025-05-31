#ifndef BSQ_H
#define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct s_bsq t_bsq;

struct s_bsq
{
    char **map;
    int **padMap;
    int mapLen;
    int mapWidth;
    char full;
    char empty;
    char obstacle;
    int biggestSide;
    int i, j;
    int obstacleCount;
};
//Utils:


int ft_strlen(char *s);
int fillPaddingMap(t_bsq *obj);
void printMap(char **map);
void printPadMap(t_bsq *obj,int **map);

//initialize :
int init(t_bsq *obj , FILE *fd);


//Parse :
int parse(t_bsq *obj, FILE *fd);


//BSQ :
void bsq(int ac, char **av);

//Freedom

void freeMyObj(t_bsq *obj);
#endif
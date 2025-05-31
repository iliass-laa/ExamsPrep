#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_maps t_maps;
typedef struct s_infos t_infos;
typedef struct s_bsq t_bsq;

typedef struct s_cords t_cords;


struct s_cords
{
    int x, y;
};
struct s_bsq
{
    // t_cords Vobstacle;
    // t_cords Hobstacle;
    int x, y, side, closeO;
};

struct s_maps
{
    char **map;
    int **tmpMap;
    char *mapInfo;
    int mapLen;
    int mapWidth;
    int biggestS;
    char full;
    char empty;
    char obstacle;
    t_bsq bsq;
};

struct s_infos
{
    int nbrsMaps;
    t_maps *pr;
};


int ft_strlen(char *s);

int fillMap(char *path,t_maps *pr);
void init(t_infos *obj, int ac, char **av);
void bsq(int , char **);
void printMap(t_maps *pr);


void freeMaps(t_maps *ptr, int nbrMaps);
void freeMap(void **map, int c);
// void    freeInfos(t_infos infos);

#endif
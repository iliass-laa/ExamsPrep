#ifndef LIFE_H
#define LIFE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>


#define DRAW 'x'
#define UP 'w'
#define Left 'a'
#define Right 'd'
#define Down 's'


typedef struct s_life t_life;


struct s_life
{
    char **map;
    char *commands;
    int width;
    int height;
    int iterations;
    bool draw;
};

int ft_strlen(char *s);
int ft_putstr(char *msg);
char *readLine(int fd);
char *ft_strjoin(char *s1,char *s2, int len);
void init(t_life *obj, char **av);
void game(t_life *obj);
void life(char **av);
void game(t_life *obj);
void freeBoard(char **board);

#endif
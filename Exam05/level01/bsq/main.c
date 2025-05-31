#include "bsq.h"

int main(int ac, char **av)
{
    av++;
    ac--;
    bsq(ac, av);
}


// int main()
// {

//     char *str = (char *)malloc(4);

//     str[0] = 'a';
//     str[1] = 'b';
//     str[2] = 'c';
//     str[3] = '\0';
//     printf("%s\n",str);

//     str[1] = '\0';
//     printf("%s\n",str);

//     free(str);
// }
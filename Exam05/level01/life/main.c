#include "life.h"


#include <fcntl.h>
int main(int ac, char **av)
{
    if (ac != 4)
        return (ft_putstr("Need more Args (width , height and iterations)"), 1);
    av++;       
    life(av);
}

















































// void foo(char *s)
// {
//     if (s)
//     {
//         printf("s>>%p\n", &s);        
//     }
//     free(s);
// }

// int main()
// {
//     char *s = malloc(4);
//     char *sTmp = s;
//     printf("s>>%p\n", &s);        

//     // foo(s);
//     free(sTmp);
// }
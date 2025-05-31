CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
CFILES = main.c bsq.c fillMap.c findBSQ.c utils.c init.c\
			freedom.c
OBJ = $(CFILES:.c=.o)
NAME = bsqE

all : $(NAME)


%.o : $.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@


$(NAME) : $(OBJ)	
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -rf $(OBJ)


fclean : clean	
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
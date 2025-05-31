CC=cc
CFLAGS = -Wall -Wextra -Werror  -fsanitize=address -g
CFILES = main.c utils.c life.c game.c
OBJ = $(CFILES:.c=.o)
NAME = life

all : $(NAME)


%.o : $.c
	$(CC) -c $(CFLAGS) $< -o $@


$(NAME) : $(OBJ)	
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -rf $(OBJ)


fclean : clean	
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
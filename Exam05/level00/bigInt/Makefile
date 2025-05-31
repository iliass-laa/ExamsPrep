C++ = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPPFILES = bigint.cpp main.cpp
OBJ = $(CPPFILES:.cpp=.o)
NAME = BigI

all : $(NAME)

%.o : %.cpp
	$(C++) $(CPPFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(C++) $(CPPFLAGS) $^ -o $@ 

clean :	
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
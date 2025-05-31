C++ = c++
CPPFILES = main.cpp vect2.cpp
CPPFLAGS = -Wall -Wextra -Werror 
OBJ= $(CPPFILES:.cpp=.o)
NAME = vec

all : $(NAME)

%.o : $.cpp
	$(C++) $(CPPFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(C++) $(CPPFLAGS) $^ -o $@

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
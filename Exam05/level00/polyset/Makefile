C++ =c++
CPPFLAGS = -Wall -Wextra -Werror 
CPPFILES = array_bag.cpp tree_bag.cpp set.cpp\
		 	searchable_tree_bag.cpp searchable_array_bag.cpp main.cpp
CPPHEADERS = array_bag.hpp tree_bag.hpp set.hpp\
		 	searchable_tree_bag.hpp searchable_array_bag.hpp
OBJ = $(CPPFILES:.cpp = .o)
NAME = poly

all:$(NAME)


%.o : %.cpp $(CPPHEADERS)
	$(C++) $(CPPFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(C++) $(CPPFLAGS) $^ -o $@
	
clean :
	rm -rf $(OBJ)


fclean : clean	
	rm -rf $(NAME)


re : fclean all

.PHONY : all clean fclean re
NAME = FragTrap
C = c++ -Wall -Wextra -Werror -std=c++98

SRC = ./src/main.cpp ./src/ClapTrap.cpp ./src/ScavTrap.cpp ./src/FragTrap.cpp

RM			=	rm -f

OBJS		=	$(SRC:.cpp=.o)

%.o: %.cpp
	@$(C) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME)	: $(OBJS)
	@$(C) $^ -o $(NAME)
	@echo '$(NAME) compiled!'

fclean		: clean
	@$(RM) $(NAME)

clean		:
	@$(RM) $(OBJS)

re			:	fclean all

.PHONY		:	all clean fclean re
NAME = abstractClass
C = c++ -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ./src/AAnimal.cpp ./src/Cat.cpp ./src/Dog.cpp ./src/WrongAnimal.cpp ./src/WrongCat.cpp ./src/Brain.cpp

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
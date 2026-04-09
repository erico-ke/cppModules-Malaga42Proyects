NAME			=	easyfind

CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98
DEBUG			?=	0
CPPFLAGS		=	-DDEBUG=$(DEBUG)

SRC				=	./main.c
OBJS			=	$(SRC:.c=.o)

RM				=	rm -f

all:			$(NAME)

debug:			DEBUG = 1
debug:			re

$(NAME):		$(OBJS)
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled"

%.o:			%.c
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean:			clean
	@$(RM) $(NAME)

re:				fclean all

.PHONY:			all debug clean fclean re
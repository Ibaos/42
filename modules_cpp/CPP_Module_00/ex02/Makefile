NAME				=	account

OBJS_DIR			=	.objs

FILES				=	Account.cpp			\
						tests.cpp

HEADER				=	Account.hpp

OBJS				=	$(FILES:%.cpp=$(OBJS_DIR)/%.o)

CC					=	c++

FLAGS				=	-Wall -Werror -Wextra -std=c++98

all:				$(OBJS_DIR) $(NAME)

$(OBJS_DIR)/%.o:	%.cpp $(HEADER) Makefile
						$(CC) $(FLAGS) -c $< -o $@

$(NAME):			$(OBJS_DIR) $(OBJS) $(HEADER) Makefile
						$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR):
						mkdir -p $(OBJS_DIR)

clean:
						rm -rf $(OBJS_DIR)

fclean:
						$(MAKE) clean
						rm -rf $(NAME)

re:
						$(MAKE) fclean all

.PHONY: all clean fclean re

NAME				=	push_swap

SRCS_DIR			=	sources

OBJS_DIR			=	.objs

HEADER_DIR			=	includes

DLIB				=	Libft

FILES				=	push_swap.c				\
						tools.c					\
						initialize.c			\
						checks.c				\
						sort_all.c				\
						sort_two_and_three.c	\
						rules_rotates.c			\
						rules_push_and_swap.c 	\
						sort_back.c 			\
						free.c

OBJS				=	$(FILES:%.c=$(OBJS_DIR)/%.o)

HEADERS				=	$(HEADER_DIR)/push_swap.h

CC					=	cc

FLAGS				=	-Wall -Werror -Wextra -g3

all:				libft $(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c $(HEADERS)
						$(CC) $(FLAGS) -c $< -o $@

$(NAME):			$(OBJS_DIR) $(OBJS) $(HEADERS) $(DLIB)/libft.a
						$(CC) $(FLAGS) $(OBJS) $(DLIB)/libft.a -o $(NAME)

$(OBJS_DIR):
						mkdir -p $(OBJS_DIR)

libft:
						$(MAKE) -C $(DLIB)

clean:
						rm -rf $(OBJS_DIR)
						$(MAKE) clean -C $(DLIB)

fclean:
						$(MAKE) clean
						rm -rf $(NAME)
						$(MAKE) fclean -C $(DLIB)

re:
						$(MAKE) fclean all

.PHONY: all clean fclean re libft

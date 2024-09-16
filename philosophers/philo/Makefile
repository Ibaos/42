NAME				=	philo

SRCS_DIR			=	sources

OBJS_DIR			=	.objs

HEADER_DIR			=	includes

FILES				=	main.c				\
						initialize.c		\
						observer.c			\
						philosophers.c		\
						philo_utils.c		\
						functions_utils.c	\
						mutex_get_value.c	\
						mutex_set_value.c	\

OBJS				=	$(FILES:%.c=$(OBJS_DIR)/%.o)

HEADERS				=	$(HEADER_DIR)/$(NAME).h			\
						$(HEADER_DIR)/error_messages.h	\

CC					=	cc

FLAGS				=	-Wall -Werror -Wextra

all:				$(OBJS_DIR) $(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c $(HEADERS)
						$(CC) $(FLAGS) -c $< -o $@

$(NAME):			$(OBJS_DIR) $(OBJS) $(HEADERS) Makefile
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

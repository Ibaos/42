NAME_SERVER					=	server

NAME_CLIENT					=	client

SRCS_DIR					=	sources

OBJS_DIR_SERVER				=	.objs_server

OBJS_DIR_CLIENT				=	.objs_client

HEADER_DIR					=	includes

FILES_SERVER				=	server.c	ft_itoa.c	ft_strlen.c	ft_strjoin_50.c	ft_memset.c	message_first_letter.c	end_message.c

FILES_CLIENT				=	client.c	ft_atoi.c	ft_strlen.c

OBJS_SERVER					=	$(FILES_SERVER:%.c=$(OBJS_DIR_SERVER)/%.o)

OBJS_CLIENT					=	$(FILES_CLIENT:%.c=$(OBJS_DIR_CLIENT)/%.o)

HEADERS						=	$(HEADER_DIR)/minitalk.h

CC							=	cc

FLAGS						=	-Wall -Werror -Wextra

NAME_SERVER_BONUS			=	server_bonus

NAME_CLIENT_BONUS			=	client_bonus

SRCS_DIR_BONUS				=	sources_bonus

OBJS_DIR_SERVER_BONUS		=	.objs_server_bonus

OBJS_DIR_CLIENT_BONUS		=	.objs_client_bonus

FILES_SERVER_BONUS			=	server_bonus.c	ft_itoa_bonus.c	ft_strlen_bonus.c	ft_strjoin_50_bonus.c	ft_memset_bonus.c	message_first_letter_bonus.c	end_message_bonus.c

FILES_CLIENT_BONUS			=	client_bonus.c	ft_atoi_bonus.c	ft_strlen_bonus.c

OBJS_SERVER_BONUS			=	$(FILES_SERVER_BONUS:%.c=$(OBJS_DIR_SERVER_BONUS)/%.o)

OBJS_CLIENT_BONUS			=	$(FILES_CLIENT_BONUS:%.c=$(OBJS_DIR_CLIENT_BONUS)/%.o)

HEADERS_BONUS				=	$(HEADER_DIR)/minitalk_bonus.h

all:						$(NAME_SERVER) $(NAME_CLIENT)

$(OBJS_DIR_SERVER)/%.o:			$(SRCS_DIR)/%.c $(HEADERS)
								$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR_CLIENT)/%.o:			$(SRCS_DIR)/%.c $(HEADERS)
								$(CC) $(FLAGS) -c $< -o $@

$(NAME_SERVER):				$(OBJS_DIR_SERVER) $(OBJS_SERVER) $(HEADERS) 
								$(CC) $(FLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT):				$(OBJS_DIR_CLIENT) $(OBJS_CLIENT) $(HEADERS) 
								$(CC) $(FLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

$(OBJS_DIR_SERVER):
								mkdir -p $(OBJS_DIR_SERVER)

$(OBJS_DIR_CLIENT):
								mkdir -p $(OBJS_DIR_CLIENT)

$(OBJS_DIR_SERVER_BONUS)/%.o:		$(SRCS_DIR_BONUS)/%.c $(HEADERS_BONUS)
								$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR_CLIENT_BONUS)/%.o:		$(SRCS_DIR_BONUS)/%.c $(HEADERS_BONUS)
								$(CC) $(FLAGS) -c $< -o $@

$(NAME_SERVER_BONUS):		$(OBJS_DIR_SERVER_BONUS) $(OBJS_SERVER_BONUS) $(HEADERS_BONUS) 
								$(CC) $(FLAGS) $(OBJS_SERVER_BONUS) -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS):		$(OBJS_DIR_CLIENT_BONUS) $(OBJS_CLIENT_BONUS) $(HEADERS_BONUS) 
								$(CC) $(FLAGS) $(OBJS_CLIENT_BONUS) -o $(NAME_CLIENT_BONUS)

$(OBJS_DIR_SERVER_BONUS):
								mkdir -p $(OBJS_DIR_SERVER_BONUS)

$(OBJS_DIR_CLIENT_BONUS):
								mkdir -p $(OBJS_DIR_CLIENT_BONUS) 

bonus:						$(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

clean:
								rm -rf $(OBJS_DIR_SERVER) $(OBJS_DIR_CLIENT) $(OBJS_DIR_SERVER_BONUS) $(OBJS_DIR_CLIENT_BONUS)

fclean:
								$(MAKE) clean
								rm -rf $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re:
								$(MAKE) fclean all

.PHONY: all clean fclean re bonus

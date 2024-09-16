# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 12:56:04 by bhumeau           #+#    #+#              #
#    Updated: 2023/11/20 18:54:30 by bhumeau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

FILES		=	ft_isalnum.c	ft_isprint.c	ft_memcpy.c		ft_putendl_fd.c	ft_strchr.c		\
				ft_strlcat.c	ft_strncmp.c	ft_substr.c		ft_atoi.c		ft_isalpha.c	\
				ft_itoa.c		ft_memmove.c	ft_putnbr_fd.c	ft_strdup.c		ft_strlcpy.c	\
				ft_strnstr.c	ft_tolower.c	ft_bzero.c		ft_isascii.c	ft_memchr.c		\
				ft_memset.c		ft_putstr_fd.c	ft_striteri.c	ft_strlen.c		ft_strrchr.c	\
				ft_toupper.c	ft_calloc.c		ft_isdigit.c	ft_memcmp.c		ft_putchar_fd.c	\
				ft_split.c		ft_strjoin.c	ft_strmapi.c	ft_strtrim.c					\
				ft_lstnew_bonus.c 	ft_lstadd_front_bonus.c 	ft_lstsize_bonus.c 				\
				ft_lstlast_bonus.c 		ft_lstadd_back_bonus.c 		ft_lstdelone_bonus.c 		\
				ft_lstclear_bonus.c 	ft_lstiter_bonus.c

OBJS		= $(FILES:.c=.o)

FLAGS		= -Wall -Werror -Wextra -g3

HEADERS		= libft.h

CC			= cc

all:		$(NAME)

$(NAME): 	$(OBJS)
			ar rcs $@ $(OBJS)

%.o:		%.c $(HEADERS)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean
			$(MAKE) all

.PHONY: all fclean clean re 

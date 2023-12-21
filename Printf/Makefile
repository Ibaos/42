# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhumeau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 12:44:16 by bhumeau           #+#    #+#              #
#    Updated: 2023/11/24 12:50:59 by bhumeau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

FILES	=	ft_printf.c ft_put_csdiux.c ft_put_p.c

OBJS	=	$(FILES:.c=.o)

FLAGS	=	-Wall -Werror -Wextra

HEADERS	=	ft_printf.h

CC		=	cc

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $@ $(OBJS)

%.o:		%.c $(HEADERS)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean
			$(MAKE) all

.PHONY:	all fclean clean re

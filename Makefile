# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 19:39:36 by bordenoy          #+#    #+#              #
#    Updated: 2019/02/28 22:21:03 by bordenoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c \
	  ft_lake.c \
	  ft_ls.c \
	  ft_sl.c \
	  ft_outils.c \
	  ft_memset.c \
	  ft_memalloc.c \
	  ft_strdup.c
O = $(SRC:.c=.o)
	CC = gcc -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(O)
		$(CC) -o $@ $(O)

%.o: %.c
		$(CC) -c $<

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

tilde:
		rm -f *~

re: fclean all

.PHONY: all clean fclean re


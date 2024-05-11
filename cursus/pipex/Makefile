# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 15:15:37 by seonkim           #+#    #+#              #
#    Updated: 2021/06/23 15:22:01 by seonkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

SRC = main.c util.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) -c $(CFLAGS) $(SRC)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

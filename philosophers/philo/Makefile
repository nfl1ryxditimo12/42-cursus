# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 17:37:40 by seonkim           #+#    #+#              #
#    Updated: 2022/03/16 21:51:35 by seonkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = philo

SRC = main.c init.c check.c util.c philo.c time.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
		$(CC) -c $(CFLAGS) $(SRC)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 12:25:55 by seonkim           #+#    #+#              #
#    Updated: 2021/06/29 12:53:30 by seonkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = check.c main.c print.c push_swap.c sort.c valid.c sort_util.c \
	  init.c node.c push.c rotate.c swap.c reverse.c sort_small.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $@

clean :
	rm -r $(OBJ)

fclean : clean
	rm -r $(NAME)

re : fclean all

.PHONY: all clean fclean re

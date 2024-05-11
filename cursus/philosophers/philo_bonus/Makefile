# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 22:43:33 by seonkim           #+#    #+#              #
#    Updated: 2022/03/21 18:37:07 by seonkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_bonus
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

INC_DIR		=	includes/
OBJ_DIR		=	objects/
SRC_DIR		=	sources/

SOURCES		=	main.c\
 				util.c\
				init.c\
				philo.c\
				time.c\
				monitor.c


OBJ_FILES	=	$(SOURCES:.c=.o)
OBJECTS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

MKDIR		=	$(shell mkdir $(OBJ_DIR) 2> /dev/null)

all		:	$(MKDIR) $(NAME)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME)	:	$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean	:
	rm -rf $(OBJ_DIR)

fclean	:	clean
	rm -rf $(NAME)

re		: fclean
	make all

.PHONY: all clean fclean re
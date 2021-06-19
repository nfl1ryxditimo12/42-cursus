# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 03:05:45 by seonkim           #+#    #+#              #
#    Updated: 2021/06/20 06:57:26 by seonkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c read.c util.c draw.c process.c valid.c print.c init.c
SRCB = main_bonus.c read_bonus.c util_bonus.c draw_bonus.c \
       process_bonus.c valid_bonus.c print_bonus.c init_bonus.c loop_bonus.c

FLAGS = -Wall -Wextra -Werror

FLAGSMLX = -lmlx -framework OpenGL -framework AppKit

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

.PHONY : all clean fclean re bonus

all : $(NAME)

%.o : %.c ../inc/so_long.h
	gcc $(FLAGS) -I ../inc -c $< -o $@

${NAME} : $(OBJ) ../inc/so_long.h
	gcc $(FLAGS) $(OBJ) -I ../inc $(FLAGSMLX) -L ../lib -o $(NAME)

clean :
	$(RM) $(OBJ) $(OBJB)

fclean : clean
	$(RM) $(NAME)

bonus : $(OBJB) ../inc/so_long_bonus.h
	gcc $(FLAGS) $(OBJB) -I ../inc $(FLAGSMLX) -L ../lib -o $(NAME)

re : fclean all

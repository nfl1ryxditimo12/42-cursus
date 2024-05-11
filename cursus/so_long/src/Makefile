# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 03:05:45 by seonkim           #+#    #+#              #
#    Updated: 2021/06/21 11:37:13 by seonkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCM = main.c read.c util.c draw.c process.c valid.c print.c init.c
SRCB = main_bonus.c read_bonus.c util_bonus.c draw_bonus.c \
       process_bonus.c valid_bonus.c print_bonus.c init_bonus.c loop_bonus.c

FLAGS = -Wall -Wextra -Werror

FLAGSMLX = -L ../mlx -lmlx -framework OpenGL -framework AppKit

OBJM = $(SRCM:.c=.o)
OBJB = $(SRCB:.c=.o)

all : $(NAME)

%.o : %.c ../inc/so_long.h
	gcc $(FLAGS) -I ../inc -c $< -o $@

${NAME} : $(OBJM) ../inc/so_long.h
	gcc $(FLAGS) $(OBJM) -I ../inc $(FLAGSMLX) -o $(NAME)

clean :
	$(RM) $(OBJM) $(OBJB)

fclean : clean
	$(RM) $(NAME)

bonus : $(OBJB) ../inc/so_long_bonus.h
	gcc $(FLAGS) $(OBJB) -I ../inc $(FLAGSMLX) -o $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus

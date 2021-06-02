# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 14:35:20 by seonkim           #+#    #+#              #
#    Updated: 2021/06/02 11:49:16 by seonkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS = ft_printf.c ft_format_process.c ft_format_util.c \
	   ft_print_int.c ft_print_unsigned_int.c ft_print_char.c \
	   ft_print_string.c ft_print_percent.c ft_print_util.c ft_print_pointer.c

SRCO = ft_printf.o ft_format_process.o ft_format_util.o \
	   ft_print_int.o ft_print_unsigned_int.o ft_print_char.o \
	   ft_print_string.o ft_print_percent.o ft_print_util.o

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

INC = -I./

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(INC) $(SRCS)
	ar -crs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O)
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

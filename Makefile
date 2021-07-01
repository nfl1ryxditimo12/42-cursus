# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 22:28:02 by jeonpark          #+#    #+#              #
#    Updated: 2021/07/02 19:56:05 by jeonpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell

READLINE_DIR	:= /Users/$(value USER)/.brew/opt/readline



SRCS		:= \
			   check.c \
			   command.c \
			   node.c \
			   parse.c \
			   parse_util.c \
			   main.c
OBJS		:= $(SRCS:.c=.o)

CC			:= clang
CFLAG		:= -Wall -Wextra -Werror

ABSTRACT_INCLUDE	:= \
			   $(READLINE_DIR)/include \
			   .
INCLUDE		:= $(addprefix -I ,$(ABSTRACT_INCLUDE))

LIBRARY		:= -L $(READLINE_DIR)/lib -l readline

COMPILE		= $(CC) $(CFLAG) $(INCLUDE) $(DEBUG_OPTION)
LINK		= $(CC) $(CFLAG) $(INCLUDE) $(DEBUG_OPTION) $(LIBRARY)

RM			:= rm -f



.PHONY:	all debug setdebug clean fclean re
all:$(NAME)

debug:		clean setdebug $(NAME)
setdebug:
			$(eval DEBUG_OPTION = -g)

clean:
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME)
re:			fclean all



$(NAME):	$(OBJS)
			$(LINK) -o $@ $^

%.o:		%.c
			$(COMPILE) -o $@ -c $<

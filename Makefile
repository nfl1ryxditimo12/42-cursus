# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 22:28:02 by jeonpark          #+#    #+#              #
#    Updated: 2021/07/14 13:34:49 by jeonpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell

READLINE_DIR	:= /Users/$(value USER)/.brew/opt/readline



SRCS		:= \
			   check.c \
			   init.c \
			   node.c \
			   parse.c \
			   parse_util.c \
			   print.c \
			   builtin_cmd/builtin.c \
			   builtin_cmd/builtin_util.c \
			   builtin_cmd/cd.c \
			   builtin_cmd/echo.c \
			   builtin_cmd/env.c \
			   builtin_cmd/exit.c \
			   builtin_cmd/export.c \
			   builtin_cmd/unset.c \
			   jeonpark/lmt_signal.c \
			   jeonpark/lmt_process_manager/t_lmt_process_list_method.c \
			   jeonpark/lmt_process_manager/t_lmt_process_list_type.c \
			   jeonpark/lmt_process_manager/t_lmt_process_manager_method.c \
			   jeonpark/lmt_process_manager/t_lmt_process_manager_type.c \
			   jeonpark/lmt_process_manager/t_lmt_process_method.c \
			   jeonpark/lmt_process_manager/t_lmt_process_type.c \
			   jeonpark/lmt_process_manager/t_lmt_redirection_method.c \
			   jeonpark/lmt_process_manager/t_lmt_redirection_type.c \
			   jeonpark/lmt_process_manager/t_lmt_redirection_list_method.c \
			   jeonpark/lmt_process_manager/t_lmt_redirection_list_type.c \
			   jeonpark/lmt_tokenization/t_lmt_token.c \
			   jeonpark/lmt_tokenization/t_lmt_token_list_method.c \
			   jeonpark/lmt_tokenization/t_lmt_token_list_type.c \
			   jeonpark/lmt_tokenization/t_lmt_token_sublist.c \
			   jeonpark/lmt_util/lmt_alloc.c \
			   jeonpark/lmt_util/lmt_atoi.c \
			   jeonpark/lmt_util/lmt_check_type.c \
			   jeonpark/lmt_util/lmt_env_path_array.c \
			   jeonpark/lmt_util/lmt_exit.c \
			   jeonpark/lmt_util/lmt_get_exit_code_from_stat_loc.c \
			   jeonpark/lmt_util/lmt_return_error.c \
			   jeonpark/lmt_util/lmt_unsafe_memcmp.c \
			   jeonpark/lmt_util/lmt_unsafe_strcmp.c \
			   jeonpark/lmt_util/lmt_unsafe_strlen.c \
			   jeonpark/lmt_util/t_lmt_string_array.c \
			   main.c
OBJS		:= $(SRCS:.c=.o)

CC			:= clang
CFLAG		:= -Wall -Wextra -Werror

ABSTRACT_INCLUDE	:= \
			   $(READLINE_DIR)/include \
			   jeonpark \
			   jeonpark/lmt_constant \
			   jeonpark/lmt_describer \
			   jeonpark/lmt_process_manager \
			   jeonpark/lmt_util \
			   jeonpark/lmt_tokenization \
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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 22:28:02 by jeonpark          #+#    #+#              #
#    Updated: 2021/10/13 12:10:31 by jeonpark         ###   ########.fr        #
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
			   jeonpark/lmt_c_library/lmt_alloc/lmt_alloc.c \
			   jeonpark/lmt_c_library/lmt_io/lmt_put_ch.c \
			   jeonpark/lmt_c_library/lmt_primitive_type/lmt_atoi.c \
			   jeonpark/lmt_c_library/lmt_primitive_type/lmt_is_digit.c \
			   jeonpark/lmt_c_library/lmt_primitive_type/lmt_is_space.c \
			   jeonpark/lmt_c_library/lmt_primitive_type/lmt_str_equals.c \
			   jeonpark/lmt_c_library/lmt_string/t_lmt_string_method.c \
			   jeonpark/lmt_c_library/lmt_string/t_lmt_string_type.c \
			   jeonpark/lmt_c_library/lmt_unsafe/lmt_unsafe_memcpy.c \
			   jeonpark/lmt_c_library/lmt_unsafe/lmt_unsafe_strchr.c \
			   jeonpark/lmt_c_library/lmt_unsafe/lmt_unsafe_strcpy.c \
			   jeonpark/lmt_c_library/lmt_unsafe/lmt_unsafe_strdup.c \
			   jeonpark/lmt_c_library/lmt_unsafe/lmt_unsafe_string_starts.c \
			   jeonpark/lmt_c_library/lmt_unsafe/lmt_unsafe_strlen.c \
			   jeonpark/lmt_c_library/lmt_unsafe/lmt_unsafe_strrchr.c \
			   jeonpark/lmt_check_syntax_error/lmt_check_syntax_error.c \
			   jeonpark/lmt_extension/lmt_extension_handler_reset_all_size.c \
			   jeonpark/lmt_extension/lmt_extension_token_arrange.c \
			   jeonpark/lmt_extension/lmt_extension_token_is_type.c \
			   jeonpark/lmt_extension/lmt_extension_token_refine_argv_0.c \
			   jeonpark/lmt_extension/lmt_extension_token_method.c \
			   jeonpark/lmt_extension/lmt_extension_token_set_type.c \
			   jeonpark/lmt_process_manager/t_lmt_process_list_method.c \
			   jeonpark/lmt_process_manager/t_lmt_process_list_type.c \
			   jeonpark/lmt_process_manager/t_lmt_process_manager_method.c \
			   jeonpark/lmt_process_manager/t_lmt_process_method.c \
			   jeonpark/lmt_process_manager/t_lmt_process_redirection.c \
			   jeonpark/lmt_process_manager/t_lmt_process_type.c \
			   jeonpark/lmt_redirection/lmt_apply_redirection.c \
			   jeonpark/lmt_token_sublist/t_lmt_token_sublist.c \
			   jeonpark/lmt_helper/check_type.c \
			   jeonpark/lmt_helper/lmt_get_exit_code_from_stat_loc.c \
			   jeonpark/lmt_helper/lmt_open_perror.c \
			   jeonpark/signal/signal.c \
			   main.c

OBJS		:= $(SRCS:.c=.o)

CC			:= clang
CFLAG		:= -Wall -Wextra -Werror

ABSTRACT_INCLUDE	:= \
			   $(READLINE_DIR)/include \
			   jeonpark \
			   jeonpark/lmt_c_library \
			   jeonpark/lmt_c_library/lmt_alloc \
			   jeonpark/lmt_c_library/lmt_io \
			   jeonpark/lmt_c_library/lmt_primitive_type \
			   jeonpark/lmt_c_library/lmt_string \
			   jeonpark/lmt_c_library/lmt_unsafe \
			   jeonpark/lmt_check_syntax_error \
			   jeonpark/lmt_extension \
			   jeonpark/lmt_helper \
			   jeonpark/lmt_process_manager \
			   jeonpark/lmt_redirection \
			   jeonpark/lmt_token_sublist \
			   jeonpark/signal \
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

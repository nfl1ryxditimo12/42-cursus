/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_constant.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:03 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/09 15:47:20 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_CONSTANT_H
# define LMT_CONSTANT_H

# define PARSE_SUCCESS	0
# define PARSE_FAIL		1

# define FD_NONE	-1
# define FD_IN		0
# define FD_OUT		1
# define FD_ERR		2

//	t_lmt_command_list_execute()/fd_pipe/index
# define PIPE_READ	0
# define PIPE_WRITE	1

//	lmt_redirection_free()/option
# define REDIRECTION_FREE_NORMAL	0
# define REDIRECTION_FREE_FD		1

//	lmt_process/type
# define TYPE_PROCESS_NORMAL	0
# define TYPE_PROCESS_SHELL		1

//	lmt_token/type
//	lmt_process/op
# define TYPE_NONE					0x00000001
# define TYPE_COMMAND				0x00000002
# define TYPE_REDIRECTION_IN		0x00000004
# define TYPE_REDIRECTION_WORD		0x00000008
# define TYPE_REDIRECTION_OUT		0x00000010
# define TYPE_REDIRECTION_APPEND	0x00000020
# define TYPE_OPERATOR_PIPE			0x00000040
# define TYPE_OPERATOR_AND			0x00000080
# define TYPE_OPERATOR_OR			0x00000100
# define TYPE_PARENTHESIS_OPEN		0x00000200
# define TYPE_PARENTHESIS_CLOSE		0x00000400

# define TYPE_REDIRECTION			0x0000003c
# define TYPE_DELIMITER				0x000001c0

//	exit status
# define EXIT_STATUS_TRUE	0
# define EXIT_STATUS_FALSE	1

# define LMT_WRONG_PATH	"WRONG PATH \n"

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_constant.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:03 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/07 20:49:33 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H

//	t_token/type
//	lmt_process/op
//	lmt_redirection/type
# define TYPE_NONE					0x00000001
# define TYPE_BUILTIN				0x00000002
# define TYPE_NON_BUILTIN			0x00000004
# define TYPE_REDIRECTION_IN		0x00000008
# define TYPE_REDIRECTION_WORD		0x00000010
# define TYPE_REDIRECTION_OUT		0x00000020
# define TYPE_REDIRECTION_APPEND	0x00000040
# define TYPE_CONTROL_OPERATOR_PIPE	0x00000080
# define TYPE_CONTROL_OPERATOR_AND	0x00000100
# define TYPE_CONTROL_OPERATOR_OR	0x00000200
# define TYPE_OPEN_PARENTHESIS		0x00000400
# define TYPE_CLOSE_PARENTHESIS		0x00000800

//	- 쓰임:
//	if (token->type & TYPE_REDIRECTION != 0)
//	{
//		type 이 4 종류의 redirection 중 하나라는 뜻
//	}
# define TYPE_COMMAND				0X00000006
# define TYPE_REDIRECTION			0x00000078
# define TYPE_CONTROL_OPERATOR		0x00000380

//	lmt_process_manager/t_lmt_redirection_type.c/lmt_redirection_free()
# define REDIRECTION_FREE			0
# define REDIRECTION_FREE_CLOSE_FD	1

//	lmt_process_mananger/t_lmt_process_method.c/lmt_process_excute_child()
# define TYPE_PROCESS_NORMAL	0
# define TYPE_PROCESS_SUBSHELL	1

# define FD_NONE	-1
# define FD_IN		0
# define FD_OUT		1
# define FD_ERR		2

//	t_lmt_command_list_execute()/fd_pipe[]/index
# define PIPE_READ	0
# define PIPE_WRITE	1

#endif

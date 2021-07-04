/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_constant.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:03 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 22:09:08 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef LMT_CONSTANT_H
# define LMT_CONSTANT_H

//# define PARSE		0
//# define PARSE_FAIL	1

//# define ALLOCATION_ERROR		1
//# define READ_ERROR				2
//# define WRITE_ERROR			3

//	Used for:
//		t_lmt_command/redirections/index
# define IN						0
# define OUT					1
# define ERR					2
# define REDIRECTION_TYPE_COUNT	3

//	Used for:
//		t_lmt_command_execute_command()/fd_pipe/index
# define PIPE_READ	0
# define PIPE_WRITE	1

//	Used for:
//		lmt_token/type
# define TYPE_COMMAND		0
# define TYPE_REDIRECTION	1
# define TYPE_PIPE			2

//	Parse error
# define NORMAL				0
# define SYNTAX_ERROR_PIPE	1

#endif

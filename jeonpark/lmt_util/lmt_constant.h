/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_constant.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:03 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 21:01:01 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_CONSTANT_H
# define LMT_CONSTANT_H

# define STANDARD_IN	0
# define STANDARD_OUT	1
# define STANDARD_ERR	2

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
# define TYPE_LIST_DUMMY		-1
# define TYPE_NONE				0
# define TYPE_COMMAND			1
# define TYPE_REDIRECTION_IN	2
# define TYPE_REDIRECTION_OUT	3
# define TYPE_OPERATOR_PIPE		4
# define TYPE_OPERATOR_AND		5
# define TYPE_OPERATOR_OR		6
# define TYPE_PARENTHESIS_OPEN	7
# define TYPE_PARENTHESIS_CLOSE	8

//	exit status
# define EXIT_STATUS_TRUE	0
# define EXIT_STATUS_FALSE	1

# define LMT_WRONG_PATH	"WRONG PATH \n"

#endif

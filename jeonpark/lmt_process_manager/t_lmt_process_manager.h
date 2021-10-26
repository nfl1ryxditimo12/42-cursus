/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:18:20 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/26 16:33:21 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_PROCESS_MANAGER_H
# define T_LMT_PROCESS_MANAGER_H

# include <stdio.h>
# include <sys/wait.h>	// waitpid()
# include <stddef.h>	// NULL
# include "lmt_process_manager_typedef.h"
# include "t_lmt_process.h"
# include "t_lmt_process_list.h"
# include "t_lmt_process_manager.h"
# include "lmt_redirection.h"
# include "t_lmt_token_sublist.h"
# include "lmt_c_library.h"
# include "minishell.h"
# include "constant.h"
# include "lmt_check_syntax_error.h"
# include "lmt_extension_token.h"
# include "lmt_helper.h"
# include "t_lmt_redirection_word_line.h"

//	앞과 뒤 커맨드와 관련된 현재 커맨드의 상태값을 저장한다
//	handler 도 저장한다
//	fd_pipe 는 적용 후 값을 FD_NONE 으로 초기화 한다
//	fd_std 는 stdin 과 stdout 의 fd 를 필요할 때마다 저장해둔다.
typedef struct s_lmt_process_manager
{
	t_handler		*handler;
	int				fd_pipe[3];
	int				fd_std[2];
	t_lmt_process	*process_list;
}	t_lmt_process_manager;

//	type function
t_lmt_process_manager	*lmt_process_manager_new(t_handler *handler, t_lmt_token_sublist *sublist);
void					lmt_process_manager_free(t_lmt_process_manager	*manager);

//	method function
int	lmt_process_manager_execute_token_sublist(t_lmt_process_manager *manager, t_lmt_token_sublist *token_sublist);
void	lmt_process_manager_execute(t_handler *handler);

//	fd function
void	lmt_process_manager_set_pipe(t_lmt_process_manager *manager);
void	lmt_process_manager_dup_std_fd(t_lmt_process_manager *manager, int std_fd);
void	lmt_process_manager_consume_fd_pipe(t_lmt_process_manager *manager);
void	lmt_process_manager_attach_pipe(t_lmt_process_manager *manager);
void	lmt_process_manager_restore_fd_std(t_lmt_process_manager *manager);

#endif

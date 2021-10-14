/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_method.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:41 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/14 11:34:35 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"

//	int	lmt_process_execute_parenthesis()
//	{
//	}

//	(가명) seonkim_builtin_function(t_handler) 를 호출하는 함수이다
//	parent 가 command 를 실행하는 함수를 호출하여
//	parent 상에서 command 가 실행한다
//	앞 lmt_process 의 op 가 '|' 가 아니고,
//	현재 lmt_process 의 op 가 '||' 나 '&&' 이거나 'TYPE_NONE' 인 경우
//	builtin command 는 parent 상에서 실행되어야 한다
//	저번에 zsh 과 bash 에서 'cd ..' 의 차이가 나는 부분은 '|' 뿐이었다
int	lmt_process_execute_in_parent(t_lmt_process *process, t_lmt_process_manager *manager)
{
	int	exit_code;

	exit_code = 0;
	if (lmt_process_attach_io(process, manager) == ERROR)
	{
		lmt_process_manager_restore_std(manager);
		return (ERROR);
	}
	//exit_code = process_builtin_cmd(handler);	// 이렇게 하고 싶었는데 반환값이 int 가 아니다.
	process_builtin_cmd(manager->handler);
	lmt_process_manager_restore_std(manager);
	return (exit_code);
}

//	process_line(handler) 를 호출하는 함수이다
//	lmt_process_list_set_by_token_sublist() 에서 설정한
//	lmt_process 의 type 에 따라 바로 명령을 실행하기도 하고
//	재귀적으로 다시 lmt_process_manager_execute() 를 호출하기도 한다
int	lmt_process_execute_child(t_lmt_process *process, t_lmt_process_manager *manager)
{
	int	exit_code;
	if (process->type == TYPE_PROCESS_PARENTHESIS)
		return (lmt_process_manager_execute_token_sublist(manager, process->token_sublist));
	process->pid = fork();
	if (process->pid == -1)
		lmt_critical_exit();
	if (process->pid > 0)	// 부모
	{
		lmt_process_manager_save_fd_pipe(manager);
		lmt_process_manager_restore_std(manager);
		return (NORMAL);
	}
	// 자식
	if (lmt_process_attach_io(process, manager) == ERROR)
		exit(ERROR);
	manager->handler->line = process->token_sublist->first;
	if (builtin_cmd(manager->handler))
	{
		// 이렇게 하고 싶었는데 아직 인자를 2 개를 받지 않는다.
//				process_builtin_cmd(lmt_count_of_null_terminated_array(process->token_sublist->first->token), process->token_sublist->first);
//				반환값을 설정해줘야 한다
		exit_code = 0;
		process_builtin_cmd(manager->handler);
		exit(exit_code);
	}
	else if (not_builtin_cmd(manager->handler))
	{
		lmt_refine_token_argv_0(process->token_sublist->first);
		// cmd_dir 설정은 어디서 하는가? 바로 내 함수를 호출하면 아마 설정되어 있지 않을 것 같다.
		// 내 코드 안에서 seonkim 의 함수를 호출해서 설정하는 부분을 추가해야 할 것 같다.
		execve(manager->handler->line->cmd_dir, process->token_sublist->first->token, manager->handler->env);
	}
	else
	{
		// 실행 가능한 명령이 아님 -> 에러처리
		perror(process->token_sublist->first->token[0]);
		exit (ERROR);
	}
	exit(ERROR);
}

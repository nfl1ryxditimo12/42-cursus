/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:19:20 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/30 20:21:44 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hand_init(t_handler *hand)
{
	hand->path = lmt_alloc(sizeof(t_path));
	hand->line = 0;
	hand->clear = 0;
	getcwd(hand->path->dir, 1024);
	hand->exit = 0;
	hand->pid = 0;
	hand->cmd_flag = 0;
	hand->token_size = 0;
	hand->path->home_dir = getenv("HOME");
	hand->path->cmd = ft_split(getpath(hand));
}

void	shell_init(t_handler *hand)
{
	pid_t	pid;
	int		status;
	char	*clear[2];

	clear[0] = "clear";
	clear[1] = 0;
	pid = fork();
	if (pid == 0)
		execve("/usr/bin/clear", clear, hand->env);
	else
		waitpid(pid, &status, 0);
}

char	*prompt(t_handler *hand)
{
	if (hand->status == 127)
		return ("😎 \033[0;32m\033[1mminishell \033[0;31m\033[1m▸ \033[0m");
	return ("😎 \033[0;32m\033[1mminishell ▸ \033[0m");
}

void	process_line(t_handler *hand)
{
	int	check;

	hand->cmd_flag = 0;
	while (hand->line)
	{
		check = check_type(hand);
		if (check == 1)
			process_builtin_cmd(hand);
		else if (check == 2)
			process_non_builtin_cmd(hand);
		else if (check == 0)
		{
			lmt_perror(hand->line->token[0]);
			break ;
		}
		hand->line = hand->line->next;
	}
}

int	chk_operator(t_token *ptr)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = -1;
	while (ptr->token[0][++i])
		if (ptr->token[0][i] == '|' || ptr->token[0][i] == '&')
			cnt++;
	if (cnt > 2 || \
		(cnt && \
		(ptr->next->token[0][0] == '|' || \
		ptr->next->token[0][0] == '&' || ptr->next == NULL)))
		return (0);
	return (1);
}

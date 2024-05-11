/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:01:43 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/28 21:55:59 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_non_builtin_cmd(t_handler *hand)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
		execve(hand->line->cmd_dir, &hand->line->token[0], hand->env);
	else
		waitpid(pid, &status, 0);
}

void	path_reset(t_path *path)
{
	char	*ptr;
	char	**cmd_ptr;

	if (path->cmd)
	{
		cmd_ptr = path->cmd;
		while (*path->cmd)
		{
			ptr = *path->cmd;
			path->cmd++;
			free(ptr);
			ptr = NULL;
		}
		free(cmd_ptr);
	}
	path->home_dir = NULL;
	free(path);
	path = NULL;
}

void	hand_reset(t_handler *hand)
{
	int		i;
	t_token	*ptr;

	hand->line = hand->top;
	while (hand->line)
	{
		i = -1;
		while (hand->line->token[++i])
		{
			free(hand->line->token[i]);
			hand->line->token[i] = NULL;
		}
		if (hand->line->cmd_dir)
			free(hand->line->cmd_dir);
		ptr = hand->line;
		hand->line = hand->line->next;
		if (hand->line)
			hand->line->pre = NULL;
		ptr->next = NULL;
		free(ptr);
		ptr = NULL;
	}
	hand->line = NULL;
	path_reset(hand->path);
}

int	main(int ac, char **av, char **env)
{
	t_handler	hand;

	(void)ac;
	(void)av;
	hand.env = env_control(env);
	hand.status = 0;
	shell_init(&hand);
	signal_set_status(STATUS_INIT);
	process_init(&hand);
	if (hand.exit == 1)
		return (hand.status);
	return (hand.status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:30:12 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/23 16:30:48 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *err)
{
	while (*err)
		write(1, err++, 1);
	write(1, "\n", 1);
	exit(-1);
}

void	connect_pipe(int pipe_fd[2], int fd[2], int p)
{
	if (p == 1)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		dup2(fd[0], 0);
		close(pipe_fd[1]);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		dup2(fd[1], 1);
		close(pipe_fd[0]);
	}
}

void	process(t_cmd *cmd, char *command, char **envp)
{
	int	i;

	i = 0;
	cmd->av = ft_split(command);
	cmd->cmd[0] = ft_strjoin("/bin/", cmd->av[0]);
	cmd->cmd[1] = ft_strjoin("/usr/local/bin/", cmd->av[0]);
	cmd->cmd[2] = ft_strjoin("/usr/bin/", cmd->av[0]);
	cmd->cmd[3] = ft_strjoin("/usr/sbin", cmd->av[0]);
	cmd->cmd[4] = ft_strjoin("/sbin/", cmd->av[0]);
	while (i < 5)
		execve(cmd->cmd[i++], cmd->av, envp);
	perror(cmd->av[0]);
}

int main(int ac, char **av, char **envp)
{
	int		pipe_fd[2];
	int		fd[2];
	int		status;
	t_cmd	cmd;
	pid_t	pid;

	if (ac != 5)
		print_error("Usage: ./pipex file1 cmd1 cmd2 file2");
	if (pipe(pipe_fd) == -1)
		print_error("pipex: fail");
	if ((fd[0] = open(FILE1, O_RDONLY)) == -1)
		print_error("open file1: fail");
	if ((fd[1] = open(FILE2, O_RDWR | O_TRUNC | O_CREAT, 0644)) == -1)
		print_error("open file2: fail");
	if ((pid = fork()) < 0)
		print_error("fork: fail");
	if (pid > 0)
		waitpid(pid, &status, 0);
	if (!WIFEXITED(status))
		print_error("Program Error");
	connect_pipe(pipe_fd, fd, pid > 0 ? 2 : 1);
	process(&cmd, pid > 0 ? CMD2 : CMD1, envp);
	return (0);
}

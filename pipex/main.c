/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:30:12 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/23 15:13:08 by seonkim          ###   ########.fr       */
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

int 	file_inout(char *file, int p)
{
	int fd;

	if (p == 1)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		perror(file);
	dup2(fd, p == 1 ? 0 : 1);
	close(fd);
	return (0);
}

void	connect_pipe(int pipe_fd[2], int io)
{
	dup2(pipe_fd[io], io);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
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
	t_cmd	cmd;
	pid_t	pid;

	if (ac != 5)
		print_error("Usage: ./pipex file1 cmd1 cmd2 file2");
	if (pipe(pipe_fd) == -1)
		print_error("pipex: fail");
	if ((pid = fork()) < 0)
		print_error("fork: fail");
	file_inout(pid > 0 ? FILE2 : FILE1, pid > 0 ? 2 : 1);
	connect_pipe(pipe_fd, pid > 0 ? 0 : 1);
	process(&cmd, pid > 0 ? CMD2 : CMD1, envp);
	return (0);
}

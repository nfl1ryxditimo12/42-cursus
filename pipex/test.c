/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:01:17 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/21 17:52:32 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	redirect_in(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, 0);
	close(fd);
	return (0);
}

int	redirect_out(char *file)
{
	int fd;

	fd = open(file, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, 1);
	close(fd);
	return (0);
}

int main(int ac, char **av)
{
	pid_t pid;

	pid = fork();
	if (pid > 0)
		printf("parent PID : %d, PID : %d\n", getpid(), pid);
	else if (pid == 0)
		printf("child PID : %d, PID : %d\n", getpid(), pid);
	execve("/bin/cat", 0, 0);
	printf("stdout test\n");
	return (0);
}

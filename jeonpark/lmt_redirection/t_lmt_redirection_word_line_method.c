/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_word_line_method.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:59:38 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 10:51:28 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	// readline.h
#include <readline/readline.h>	// readline()
#include "t_lmt_redirection_word_line.h"
#include "lmt_c_library.h"
#include "constant.h"
#include "lmt_helper.h"

static int	read_and_should_end(char **line, const char *delimiter)
{
	*line = readline("> ");
	return (lmt_str_equals(*line, delimiter));
}

static void	append_line(t_lmt_redirection_word_line *dummy, char *line)
{
	t_lmt_redirection_word_line	*word_line;

	word_line = lmt_redirection_word_line_new(line);
	word_line->prev = dummy->prev;
	word_line->next = dummy;
	word_line->prev->next = word_line;
	word_line->next->prev = word_line;
}

static void	dup_dup2_to_std_fd(int std_in, int std_out,
		int *old_fd_in, int *old_fd_out)
{
	if (std_in != FD_IN)
	{
		*old_fd_in = lmt_dup_perror(FD_IN);
		lmt_dup2_perror(std_in, FD_IN);
	}
	if (std_out != FD_OUT)
	{
		*old_fd_out = lmt_dup_perror(FD_OUT);
		lmt_dup2_perror(std_out, FD_OUT);
	}
}

t_lmt_redirection_word_line	*lmt_redirection_word_line_new_from_stdin(
		int std_in, int std_out, const char *delimiter)
{
	t_lmt_redirection_word_line	*dummy;
	int							old_fd_in;
	int							old_fd_out;
	char						*line;

	dummy = lmt_redirection_word_line_new_dummy();
	old_fd_in = FD_NONE;
	old_fd_out = FD_NONE;
	dup_dup2_to_std_fd(std_in, std_out, &old_fd_in, &old_fd_out);
	while (!read_and_should_end(&line, delimiter))
		append_line(dummy, line);
	free(line);
	if (old_fd_in != FD_NONE)
	{
		lmt_dup2_perror(old_fd_in, FD_IN);
		lmt_close(old_fd_in);
	}
	if (old_fd_out != FD_NONE)
	{
		lmt_dup2_perror(old_fd_out, FD_OUT);
		lmt_close(old_fd_out);
	}
	return (dummy);
}

void	lmt_redirection_word_line_attach(t_lmt_redirection_word_line *dummy)
{
	t_lmt_redirection_word_line	*element;
	int							fd_pipe[2];

	if (pipe(fd_pipe) == FD_ERROR)
	{
		lmt_perror("pipe");
		exit(EXIT_CODE_FALSE);
	}
	lmt_dup2_perror(fd_pipe[PIPE_READ], FD_IN);
	lmt_close(fd_pipe[PIPE_READ]);
	element = dummy->next;
	while (element != dummy)
	{
		if (write(fd_pipe[PIPE_WRITE], element->value,
				lmt_unsafe_strlen(element->value)) == -1)
			lmt_critical_exit();
		if (write(fd_pipe[PIPE_WRITE], "\n", 1) == -1)
			lmt_critical_exit();
		element = element->next;
	}
	lmt_close(fd_pipe[PIPE_WRITE]);
}

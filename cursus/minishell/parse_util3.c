/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:24:12 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/30 20:25:47 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	chk_symbol(char *line)
{
	int	cnt;

	cnt = 0;
	if (*line == '|')
	{
		while (*line == '|')
		{
			line++;
			cnt++;
		}
	}
	else if (*line == '&')
	{
		while (*line == '&')
		{
			line++;
			cnt++;
		}
	}
	else if (*line == '(')
		return (1);
	else if (*line == ')')
		return (1);
	return (cnt);
}

int	chk_redirect(char *line)
{
	int	cnt;

	cnt = 0;
	if (*line == '<')
	{
		while (*line == '<')
		{
			line++;
			cnt++;
		}
	}
	else if (*line == '>')
	{
		while (*line == '>')
		{
			line++;
			cnt++;
		}
	}
	return (cnt);
}

int	count_fd(char *line)
{
	int	cnt;

	cnt = 0;
	while ('0' <= *line && *line <= '9')
	{
		line++;
		cnt++;
	}
	if (cnt && (*line == '<' || *line == '>'))
		return (cnt + 1);
	return (0);
}

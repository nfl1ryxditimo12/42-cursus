/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:24:43 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/30 20:24:54 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	chk_quotes(char *str, char quotes)
{
	int	cnt;
	int	quote_cnt;

	cnt = 0;
	quote_cnt = 0;
	while (quote_cnt != 2 && *str)
	{
		if (*str == quotes)
			quote_cnt++;
		cnt++;
		str++;
	}
	return (cnt);
}

int	token_len(char *str, char quotes)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (chk_symbol(str))
		return (chk_symbol(str));
	if (count_fd(str))
		return (count_fd(str));
	if (chk_redirect(str))
		return (chk_redirect(str));
	if (quotes == 34 || quotes == 39)
		return (chk_quotes(str, quotes));
	while (*str && !(*str == 32 || *str == 9) && !chk_symbol(str) && \
			!chk_redirect(str) && !count_fd(str))
	{
		if (*str == '\'' || *str == '\"')
			break ;
		str++;
		i++;
	}
	return (i);
}

int	check_dollar(char *line, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (line[i] == '$' && (line[i + 1] != 32 || line[i + 1] != 9))
			return (1);
	return (0);
}

int	get_arr_size(char *line, int size, int quotes)
{
	int	i;
	int	token;

	i = 0;
	token = 0;
	while (i < size)
	{
		if (line[i] == '$')
		{
			i++;
			while (line[i] && line[i] != quotes && line[i] != 32 && \
				line[i] != 9 && line[i] != '$')
				i++;
			token++;
		}
		else
		{
			while (line[i] && line[i] != '$')
				i++;
			token++;
		}
	}
	return (token);
}

char	*get_line(char *line, int size)
{
	int		i;
	char	*ret;

	i = -1;
	ret = lmt_alloc(size + 1);
	while (++i < size)
		ret[i] = line[i];
	ret[i] = 0;
	return (ret);
}

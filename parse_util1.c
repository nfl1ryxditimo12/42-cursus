/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:26:51 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/30 20:25:58 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*split_to_join(char **split)
{
	char	*ptr;
	int		len;

	len = 0;
	ptr = NULL;
	while (*split)
	{
		ptr = ft_strjoin(ptr, *split);
		free(*split);
		split++;
	}
	return (ptr);
}

char	*switch_line_to_environ(char *line, int size, char **env, int quotes)
{
	char	**split;
	char	**arr;
	char	*ret;

	split = split_line(line, size, quotes);
	arr = split;
	while (*arr)
	{
		if (**arr == '$' && !ft_strcmp(*arr, "$?"))
			*arr = line_to_environ(*arr, env);
		arr++;
	}
	ret = split_to_join(split);
	free(split);
	return (ret);
}

char	*dup_line(char *line, int size, int quotes, char **env)
{
	char	*ret;
	int		i;

	if (check_dollar(line, size) && quotes != '\'')
		return (switch_line_to_environ(line, size, env, quotes));
	ret = lmt_alloc(size + 1);
	i = -1;
	while (++i < size)
		ret[i] = line[i];
	ret[i] = 0;
	return (ret);
}

int	line_cpy(t_token *ptr, char *line, char **env)
{
	int		i;
	int		size;
	char	quotes;

	i = 0;
	quotes = 0;
	while (ptr->token[i])
		i++;
	if (i == 100)
		return (-1);
	if (*line == '\'' || *line == '\"')
		quotes = *line;
	size = token_len(line, quotes);
	if (line[size] == 32 || line[size] == 9)
		ptr->space[i] = 1;
	ptr->token[i] = dup_line(line, size, quotes, env);
	ptr->size++;
	ptr->token[++i] = 0;
	return (size);
}

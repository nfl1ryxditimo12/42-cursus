/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:25:31 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/30 20:38:13 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*split_line2(int *i, int *token, int size, char *line)
{
	(*token)++;
	(*i)++;
	while (*i < size && line[*i] && line[*i] != '\'' && line[*i] != '\"' && \
				line[*i] != 32 && line[*i] != 9 && line[*i] != '$')
	{
		(*i)++;
		(*token)++;
	}
	return (get_line(&line[*i - *token], *token));
}

char	**split_line(char *line, int size, int quotes)
{
	char	**arr;
	int		i;
	int		j;
	int		token;

	i = 0;
	j = 0;
	arr = lmt_alloc(sizeof(char *) * get_arr_size(line, size, quotes) + 1);
	while (i < size)
	{
		token = 0;
		if (line[i] == '$')
			arr[j++] = split_line2(&i, &token, size, line);
		else
		{
			while (i < size && line[i] && line[i] != '$')
			{
				i++;
				token++;
			}
			arr[j++] = get_line(&line[i - token], token);
		}
	}
	arr[j] = NULL;
	return (arr);
}

char	*get_token_key(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = -1;
	j = -1;
	str++;
	while (str[++i])
		if (str[i] == '\'' || str[i] == '\"' || str[i] == 32 || str[i] == 9)
			break ;
	ret = lmt_alloc(i + 1);
	while (++j < i)
		ret[j] = str[j];
	ret[j] = 0;
	return (ret);
}

char	*line_to_environ(char *key, char **env)
{
	int		i;
	int		size;
	char	*env_key;
	char	*ptr;

	i = 0;
	ptr = get_token_key(key);
	size = cmd_len(ptr);
	while (env[i])
	{
		env_key = get_env_key(env[i]);
		if (ft_strcmp(ptr, env_key))
		{
			free(ptr);
			free(key);
			free(env_key);
			return (ft_strdup(env[i] + size + 1));
		}
		i++;
		free(env_key);
	}
	free(key);
	return (ft_strdup(""));
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*ret;
	char	*p;

	if (!s1 && !s2)
		return (0);
	s1_len = cmd_len(s1);
	s2_len = cmd_len(s2);
	ret = (char *)lmt_alloc(s1_len + s2_len + 1);
	if (!ret)
		return (0);
	p = ret;
	while (s1 && *s1)
		*(p++) = *(s1++);
	while (*s2)
		*(p++) = *(s2++);
	*p = 0;
	if (s1)
		free(s1 - s1_len);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:18:52 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/30 20:21:19 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	path_len(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == ':' && *(str + 1) != 0)
			cnt++;
		str++;
	}
	return (cnt + 1);
}

int	cmd_path_len(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] && str[cnt] != ':')
		cnt++;
	return (cnt);
}

char	*ft_strldup(char *str, int size)
{
	char	*ret;
	int		i;

	i = -1;
	if (!str || !*str)
		return (0);
	ret = lmt_alloc(size + 1);
	while (++i < size)
		ret[i] = str[i];
	ret[i] = 0;
	return (ret);
}

char	**ft_split(char *str)
{
	char	**ret;
	char	*ptr;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	ptr = str;
	ret = (char **)lmt_alloc(sizeof(char *) * (path_len(str) + 1));
	i = 0;
	while (*str)
	{
		j = 0;
		if (*str == ':')
			str++;
		else
		{
			ret[i++] = ft_strldup(str, cmd_path_len(str));
			str += cmd_path_len(str);
		}
	}
	ret[i] = 0;
	free(ptr);
	return (ret);
}

char	*getpath(t_handler *hand)
{
	char	*key;
	int		i;

	i = -1;
	while (hand->env[++i])
	{
		key = get_env_key(hand->env[i]);
		if (ft_strcmp2(key, "PATH"))
		{
			free(key);
			break ;
		}
		free(key);
	}
	if (hand->env[i] == NULL)
		return (NULL);
	return (get_env_value(hand->env[i]));
}

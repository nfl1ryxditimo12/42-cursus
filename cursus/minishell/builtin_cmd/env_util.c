/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:59:22 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/30 20:11:46 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(char *env)
{
	int		i;
	int		j;
	int		size;
	char	*ret;

	i = 0;
	size = cmd_len(env);
	while (env[i] && env[i] != '=')
		i++;
	i++;
	if (size == i)
		return (ft_strdup(""));
	ret = lmt_alloc(size - i + 1);
	j = 0;
	while (i < size)
		ret[j++] = env[i++];
	ret[j] = 0;
	return (ret);
}

char	*get_env_key(char *env)
{
	int		i;
	int		size;
	char	*ret;

	size = 0;
	while (env[size] && env[size] != '=')
		size++;
	if (!env[size])
		return (ft_strdup(""));
	ret = lmt_alloc(size + 1);
	i = -1;
	while (++i < size)
		ret[i] = env[i];
	ret[i] = 0;
	return (ret);
}

char	*ft_envdup(char *str, int flag)
{
	int		size;
	int		i;
	char	*ret;

	i = -1;
	size = cmd_len(str);
	ret = lmt_alloc(size + 1);
	while (++i < size)
		ret[i] = str[i];
	ret[i] = 0;
	if (flag)
		free(str);
	return (ret);
}

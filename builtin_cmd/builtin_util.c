/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:04:21 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/30 19:14:38 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cmd_len(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = lmt_alloc(cmd_len(str) + 1);
	while (*str)
		ret[i++] = *str++;
	ret[i] = 0;
	return (ret);
}

char	*dir_cpy(char *str)
{
	char	*ret_dir;
	int		i;

	ret_dir = lmt_alloc(cmd_len(str) + 1);
	i = -1;
	while (++i < cmd_len(str))
		ret_dir[i] = str[i];
	ret_dir[i] = 0;
	return (ret_dir);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:40:14 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/19 16:45:59 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int			is_newline(char c)
{
	return (c == '\n');
}

int			wd_len(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (!is_newline(*str))
		{
			++count;
			while (*str && !is_newline(*str))
				++str;
		}
		++str;
	}
	return (count);
}

static void	ft_strcpy(char *dest, char *from, char *to)
{
	while (from < to)
		*(dest++) = *(from++);
	*dest = 0;
}

int			ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

char		**ft_split(t_game *game, char *str, int i)
{
	char	**arr;
	char	*from;
	int		len;

	if (!(arr = (char **)malloc(sizeof(char *) * wd_len(str) + 1)))
		print_err(0, MEM_ERR, str);
	game->map.row = wd_len(str);
	while (*str)
	{
		if (!is_newline(*str))
		{
			from = str;
			while (!is_newline(*str) && *str)
				str++;
			if (!(arr[i] = (char *)malloc(str - from + 1)))
				print_err(game, MEM_ERR, str);
			ft_strcpy(arr[i], from, str);
			len = ft_strlen(arr[i++]);
			check_col(game, len);
		}
		str++;
	}
	arr[i] = 0;
	return (arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:27:22 by hyeojung          #+#    #+#             */
/*   Updated: 2021/03/18 12:09:59 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		is_newline(char c)
{
	return (c == '\n');
}

int		wd_len(char *str)
{
	int	count;

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

void	ftt_strcpy(char *dest, char *from, char *to)
{
	while (from < to)
		*(dest++) = *(from++);
	*dest = 0;
}

int		line_check(char *str)
{
	int	line_check;

	line_check = 0;
	while (*str)
		if (*(str++) == '\n')
			line_check++;
	if (line_check == g_row_size)
		return (1);
	return (0);
}

char	**ft_split(char *str)
{
	char	**arr;
	char	*from;
	int		i;

	if (!line_check(str))
		return (0);
	arr = (char **)malloc(sizeof(char *) * wd_len(str) + 1);
	i = 0;
	while (*str)
	{
		if (!is_newline(*str))
		{
			from = str;
			while (!is_newline(*str) && *str)
				str++;
			arr[i] = (char *)malloc(str - from + 1);
			ftt_strcpy(arr[i++], from, str);
		}
		str++;
	}
	arr[i] = 0;
	return (arr);
}

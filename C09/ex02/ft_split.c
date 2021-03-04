/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:15:52 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/04 12:33:50 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	string_sep(char *str, char *charset)
{
	while (*charset)
			if (*str == *charset++)
					return (1);
	return (0);
}

int string_len(char *str, char *charset)
{
	int len;

	len = 0;
	while (str[len])
	{
		while (str[len] && !string_sep(str, charset))
				len++;
	}
	return (len);
}

int	total_size(char *str, char *charset)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*str)
	{
		while (*str && string_sep(str, charset))
			str++;
		i = string_len(str, charset);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

void	string_cpy(char *str, int len)
{
	
}

char	**ft_split(char *str, char *charset)
{
	char **arr;
	int size;
	int i;
	int j;
	
	arr = malloc(sizeof(
}

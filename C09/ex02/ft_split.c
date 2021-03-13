/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:15:52 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/13 22:54:42 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		string_sep(char *str, char *charset)
{
	while (*charset)
		if (*str == *charset++)
			return (1);
	return (0);
}

int		string_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !string_sep(str + len, charset))
		len++;
	return (len);
}

int		total_size(char *str, char *charset)
{
	int	i;
	int	j;

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

char	*string_cpy(char *str, int len)
{
	char	*dest;

	dest = malloc(sizeof(char) * (len + 1));
	dest[len] = '\0';
	while (len--)
		dest[len] = str[len];
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		size;
	int		i;
	int		j;

	size = total_size(str, charset);
	arr = malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size)
	{
		while (*str && string_sep(str, charset))
			str++;
		j = string_len(str, charset);
		arr[i] = string_cpy(str, j);
		str += j;
		i++;
	}
	arr[size] = 0;
	return (arr);
}

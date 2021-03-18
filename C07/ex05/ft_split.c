/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:59:46 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/18 20:19:03 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_charset(char *charset, char c)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	total_size(char *str, char *charset)
{
	int cnt;
	int i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_charset(charset, str[i]))
			i++;
		if (str[i] && !is_charset(charset, str[i]))
		{
			while (str[i] && !is_charset(charset, str[i]))
				i++;
			cnt++;
		}
	}
	return (cnt);
}

char	*ft_strcpy(char *str, char *charset, int len)
{
	char *dest;
	int i;

	i = 0;
	while (str[len] && !is_charset(charset, str[len]))
	{
		len++;
		i++;
	}
	dest = (char *)malloc(i + 1);
	len -= i;
	i = 0;
	while (str[len] && !is_charset(charset, str[len]))
		dest[i++] = str[len++];
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char **arr;
	int	size;
	int i;
	int j;
	
	i = 0;
	j = 0;
	size = total_size(str, charset);
	if (!(arr = (char **)malloc(sizeof(char *) * (size + 1))))
		return (0);
	while (str[i])
	{
		while (str[i] && is_charset(charset, str[i]))
			i++;
		if (str[i] && ! is_charset(charset, str[i]))
		{
			arr[j] = ft_strcpy(str, charset, i);
			while (str[i] && !is_charset(charset, str[i]))
				i++;
			j++;
		}
	}
	arr[j] = 0;
	return (arr);
}

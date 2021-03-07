/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 23:58:48 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/07 11:34:39 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		total_strlen(int size, char **strs, char *sep)
{
	int		total_size;
	int		i;
	int		j;

	total_size = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		total_size += j;
		i++;
	}
	i = 0;
	while (sep[i])
		i++;
	total_size += (i * (size - 1));
	return (total_size);
}

char	*ft_strcat(char *dst, char *src)
{
	while (*src)
		*(dst++) = *(src++);
	return (dst);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*arr;
	char	*tmp;

	i = 1;
	if (size == 0)
	{
		arr = (char *)malloc(1);
		arr[0] = 0;
		return (arr);
	}
	arr = (char *)malloc(sizeof(char) * total_strlen(size, strs, sep));
	tmp = ft_strcat(arr, strs[0]);
	while (i < size)
	{
		tmp = ft_strcat(tmp, sep);
		tmp = ft_strcat(tmp, strs[i]);
		i++;
	}
	arr[total_strlen(size, strs, sep)] = 0;
	return (arr);
}

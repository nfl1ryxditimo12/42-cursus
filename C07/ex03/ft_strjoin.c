/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 23:58:48 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/03 12:43:16 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	total_strlen(int size, char **strs, char *sep)
{
	int total_size;
	int i;
	int j;

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
	return (total_size + 1);
}

char	*ft_strcat(char *dst, char *src)
{
	char *ptr;

	ptr = dst;
	while (*dst)
		dst++;
	while (*src)
		*(dst++) = *(src++);
	*dst = '\0';
	return (ptr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	char *arr;

	i = 1;
	arr = (char *)malloc(sizeof(char) * total_strlen(size, strs, sep));
	ft_strcat(arr,strs[0]);
	while(i < size)
	{
		ft_strcat(arr, sep);
		ft_strcat(arr, strs[i]);
		i++;
	}
	arr[total_strlen(size, strs, sep)] = 0;
	return (arr);
}

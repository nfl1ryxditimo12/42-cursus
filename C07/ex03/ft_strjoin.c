/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 23:58:48 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/03 01:31:51 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_strlen(int size, char *strs, char *sep)
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
	total_size += i * (size - 1);
	return (total_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	int total_size;
	char *arr;

	i = 0;
	total_size = 0;
	while(i < size)
	{
		total_size = ft_strlen(char *strs, char *sep);
	}
	
	
	return (0);
}

int main()
{
	char arr[3][30] = {"hello", "abc", "world"};
	char **ptr;

	ptr = (char **)arr;
}

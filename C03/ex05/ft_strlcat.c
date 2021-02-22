/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:54:53 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/23 00:24:51 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned int	str_len(char *arr)
{
	unsigned int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int d_len;
	unsigned int s_len;
	int k = 0;

	i = 0;
	j = 0;
	d_len = str_len(dest);
	s_len = str_len(src);
	while (i < size && dest[i])
		i++;
	while (j < s_len && d_len + j + 1 < size)
	{
		dest[d_len + j] = src[j];
		j++;
	}
	dest[d_len + j] = '\0';
	while (k < dest[k])
	{
		write(1, &dest[k], 1);
		k++;
	}
	return (i + s_len);
}

int main()
{
	char dest[20] = "12345";
	char src[3] = "abc";
	unsigned int size = 8;
	unsigned int result;
	result = ft_strlcat(dest, src, size);
	printf("%d", result);
}

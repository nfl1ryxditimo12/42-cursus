/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:54:53 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/24 18:45:05 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

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
	
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (i + j + 1 < size && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	while (src[j])
		j++;
	if (i > size)
		return (size + j);
	return (i + j);
}

int main()
{
	char dest[20] = "12345";
	char src[3] = "abc";
	printf("%u\n", ft_strlcat(dest, src, 5));
}

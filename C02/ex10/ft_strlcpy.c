/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:39:55 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/24 01:06:04 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[size - 1] = '\0';
	return (size - 1);
}

int main()
{
	char dest[20];
	char src[6] = "12345";
	int a;
	ft_strlcpy(dest, src, 4);
	a = ft_strlcpy(dest, src, 4);

	for(int i = 0; dest[i]; i++)
		printf("%c", dest[i]);
	printf("\n%d\n", a);
}

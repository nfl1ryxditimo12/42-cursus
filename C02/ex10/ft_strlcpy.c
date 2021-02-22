/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:39:55 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/22 15:42:07 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int i;
	int j;
	
	i = 0; // 문자열의 길이를 구하기 위한 변수
	j = 0; // 0 부터 쓰레기값 까지 복사를 위한 함수
	while (src[i] != '\0')
		i++;
	if (size < i + 1)
	{
		while (j < size)
		{
			dest[j] = src[j];
			j++;
		}
		dest[size - 1] = '\0';
		j = 0;
	}
	else if (size >= i)
	{
		while (j <= i)
		{
			dest[j] = src[j];
			j++;
		}
		dest[i + 1] = '\0';
	}
	return (size - 1);
}

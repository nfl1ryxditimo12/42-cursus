/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:37:31 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/24 16:38:16 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	char *temp;

	i = 0;
	temp = dest;
	while (1)
	{
		if (*dest == '\0')
		{
			if (*src != '\0' && i < nb)
			{
				*dest = *src;
				src++;
				i++;
			}
			else if (i == nb || *src == '\0')
			{
				dest++;
				*dest = '\0';
				break ;
			}
		}
		dest++;
	}
	return (temp);
}

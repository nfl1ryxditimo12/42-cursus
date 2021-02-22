/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:37:31 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/22 20:45:34 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int i;
	unsigned int j;
	
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (j < nb || src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}

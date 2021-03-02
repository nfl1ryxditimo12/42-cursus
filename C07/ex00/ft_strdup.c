/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:43:46 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/02 21:17:11 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (src[i])
		i++;
	ptr = (char *)malloc(sizeof(char) * i);
	while (j < i)
	{
		ptr[j] = src[j];
		j++;
	}
	return (ptr);
}

int main()
{
	char str[11] = "abcdefghij";
	printf("%s", ft_strdup(str));
}

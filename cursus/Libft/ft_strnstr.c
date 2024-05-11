/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 12:27:00 by seonkim           #+#    #+#             */
/*   Updated: 2021/05/10 21:43:05 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = ft_strlen((char *)s2);
	if (*s2)
	{
		if (len == 0)
			return (0);
		while (len-- && ft_strncmp(s1, s2, i) != 0)
		{
			if (len < i)
				return (0);
			if (*s1 == '\0')
				return (0);
			s1++;
		}
	}
	return ((char *)s1);
}

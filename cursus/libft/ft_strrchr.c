/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:07:30 by seonkim           #+#    #+#             */
/*   Updated: 2021/05/10 21:46:36 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *s;

	s = (char *)str;
	while (*str)
		str++;
	while (str != s && *str != (char)c)
		str--;
	if (*str == (char)c)
		return ((char *)str);
	return (0);
}

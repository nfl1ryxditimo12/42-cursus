/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:47:29 by seonkim           #+#    #+#             */
/*   Updated: 2021/05/11 14:56:32 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	i = -1;
	if (!s || !f)
		return (0);
	len = ft_strlen((char *)s);
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	while (++i < len)
		str[i] = f(i, s[i]);
	str[i] = 0;
	return (str);
}

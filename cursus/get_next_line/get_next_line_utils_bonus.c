/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:42:21 by seonkim           #+#    #+#             */
/*   Updated: 2021/05/20 01:56:38 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (!dst && !src)
		return (0);
	if (s2 < s1)
	{
		while (len--)
			*(s1 + len) = *(s2 + len);
		return (dst);
	}
	while (len--)
		*(s1++) = *(s2++);
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	if (!s1 && !s2)
		return (0);
	if (!(ret = malloc(s1_len + s2_len + 1)))
		return (0);
	ft_memmove(ret, s1, s1_len);
	ft_memmove(ret + s1_len, s2, s2_len);
	ret[s1_len + s2_len] = 0;
	free((char *)s1);
	return (ret);
}

int		ft_newline(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

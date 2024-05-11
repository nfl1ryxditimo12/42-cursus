/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:14:20 by seonkim           #+#    #+#             */
/*   Updated: 2021/05/16 18:45:42 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_start(char *str, char *set)
{
	size_t len;
	size_t i;

	len = ft_strlen(str);
	i = -1;
	while (++i < len)
		if (!ft_strchr(set, str[i]))
			break ;
	return (i);
}

int		get_end(char *str, char *set)
{
	size_t len;
	size_t i;

	len = ft_strlen(str);
	i = -1;
	while (++i < len)
		if (!ft_strchr(set, str[len - i - 1]))
			break ;
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ret;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup((char *)s1));
	start = get_start((char *)s1, (char *)set);
	end = get_end((char *)s1, (char *)set);
	if (start >= end)
		return (ft_strdup(""));
	if (!(ret = (char *)malloc(end - start + 1)))
		return (NULL);
	ft_strlcpy(ret, s1 + start, end - start + 1);
	return (ret);
}

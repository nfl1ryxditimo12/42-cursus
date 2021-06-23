/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:16:16 by seonkim           #+#    #+#             */
/*   Updated: 2021/05/16 19:08:51 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	total_size(char *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			cnt++;
		}
	}
	return (cnt);
}

static	char	**ft_free(char **ret)
{
	size_t	i;

	i = -1;
	while (ret[++i])
		free(ret[i]);
	free(ret);
	return (ret);
}

static	int		ft_process(char **ret, char *s, char c)
{
	size_t	i;
	char	*ptr;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			ptr = s;
			while (*s && *s != c)
				s++;
			if (!(ret[i] = (char *)malloc(s - ptr + 1)))
			{
				ft_free(ret);
				return (0);
			}
			ft_strlcpy(ret[i], ptr, s - ptr + 1);
			i++;
		}
	}
	ret[i] = 0;
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	size;

	size = total_size((char *)s, c);
	if (!s)
		return (0);
	if (!(ret = (char **)malloc(sizeof(char *) * (size + 1))))
		return (0);
	if (!(ft_process(ret, (char *)s, c)))
		return (0);
	return (ret);
}

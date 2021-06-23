/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:03:57 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/23 17:13:18 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		check_str(char *str)
{
	int cnt;

	cnt = 0;
	while (*str)
	{
		while (*str == ' ' && *str)
			str++;
		if (*str != ' ' && *str)
		{
			while (*str != ' ' && *str)
			{
				if (!((65 <= *str && *str <= 90) ||
							(97 <= *str && *str <= 122) || *str == 45 ||
							(48 <= *str && *str <= 57)))
					print_error("Invalid Command");
				str++;
			}
			cnt++;
		}
	}
	return (cnt);
}

char	*ft_strcpy(char *src)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = -1;
	while (src[i] != ' ' && src[i])
		i++;
	if (!(dst = malloc(i + 1)))
		print_error("Memory Error");
	while (++j < i)
		dst[j] = src[j];
	dst[j] = 0;
	return (dst);
}

char	**ft_split(char *str)
{
	char	**ret;
	int		i;

	if (!str)
		return (0);
	i = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * check_str(str) + 1)))
		print_error("Memory Error");
	while (*str)
	{
		while (*str == ' ' && *str)
			str++;
		ret[i] = ft_strcpy(str);
		while (*str != ' ' && *str)
			str++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;

	if (!s1 || !s2)
		print_error("Invalid Command");
	i = 0;
	if (!(ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		print_error("Memory Error");
	while (*s1)
		ret[i++] = *s1++;
	while (*s2)
		ret[i++] = *s2++;
	ret[i] = 0;
	return (ret);
}

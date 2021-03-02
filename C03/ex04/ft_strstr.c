/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:47:15 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/24 17:20:37 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	find_len(char *str_len)
{
	int i;

	i = 0;
	while (*str_len)
	{
		i++;
		str_len++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	char *temp;

	i = 0;
	temp = to_find;
	while (*str)
	{
		if (*str == *to_find)
		{
			i++;
			str++;
			to_find++;
			if (!*to_find)
				return (str - find_len(temp));
		}
		else
		{
			str++;
			to_find = temp;
		}
	}
	return (0);
}

int	main()
{
	char	s1[100] = "A Garden Diary A Garden Diary A Garden Diary";
	char	*ptr = ft_strstr(s1, "den");
	while (ptr != NULL)
	{
    		printf("%s\n", ptr);
    		ptr = ft_strstr(ptr + 1, "den");
	}
}

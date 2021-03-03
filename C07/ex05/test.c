/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:11:00 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/03 17:30:33 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	string_sep(char *str, char *charset)
{
	while (*charset)
		if (*str == *charset++)
			return (1);
	return (0);
}

int	string_len(char *str, char *charset)
{
	int i;

	i = 0;
	while (str[i] && !string_sep(str + i, charset))
		i++;
	return (i);
}

int	total_size(char *str, char *charset)
{
	int i;
	int w;

	w = 0;
	while (*str)
	{
		while (*str && string_sep(str, charset))
			str++;
		i = string_len(str, charset);
		str += i;
		if (i)
			w++;
	}
	return (w);
}

char	*string_cpy(char *str, int len)
{
	char *dest;

	dest = malloc(len + 1);
	dest[len] = '\0';
	while (len--)
		dest[len] = str[len];
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char **arr;
	int size;
	int i;
	int n;

	i = 0;
	size = total_size(str, charset);
	arr = malloc((size + 1) * sizeof(char *));
	while (i < size)
	{
		while (*str && string_sep(str, charset))
			str++;
		n = string_len(str, charset);
		arr[i] = string_cpy(str, n);
		str += n;
		i++;
	}
	arr[size] = 0;
	return (arr);
}

int main()
{
	int i = 0;
	char **arr = ft_split("Hello--world---hihi", "--");
	while (i < 3)
		printf("%s\n", arr[i++]);
}

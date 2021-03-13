/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:04:02 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/13 22:45:52 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void				ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			i;

	i = -1;
	if (!(arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (0);
	while (++i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = (char *)malloc(arr[i].size + 1);
		arr[i].copy = (char *)malloc(arr[i].size + 1);
		ft_strcpy(arr[i].str, av[i]);
		ft_strcpy(arr[i].copy, av[i]);
	}
	arr[i].str = 0;
	arr[i].copy = 0;
	return (arr);
}

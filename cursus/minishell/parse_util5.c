/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:26:04 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/30 20:26:09 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*s1 && *s2)
	{
		if (*s1++ != *s2++)
			return (0);
		i++;
	}
	if (!i)
		return (0);
	return (1);
}

int	ft_strcmp2(char *s1, char *s2)
{
	if (!s1)
		return (0);
	while (*s1 || *s2)
		if (*s1++ != *s2++)
			return (0);
	if (*s1 || *s2)
		return (0);
	return (1);
}

int	ft_strcmp3(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	if (!size)
		return (0);
	while (*s1 && *s2 && i < size)
	{
		if (*s1++ != *s2++)
			return (0);
		i++;
	}
	return (1);
}

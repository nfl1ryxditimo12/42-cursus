/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:26:51 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/01 19:01:24 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_strlen(char  *str)
{
    int i;

    i = 0;
	if (!str)
		return (0);
    if (chk_symbol(str))
        return (chk_symbol(str));
    while (*str && !(*str == 32 || *str == 9) && !chk_symbol(str))
	{
		str++;
        i++;
	}
    return (i);
}

void    ft_strjoin(t_token *ptr, char *line)
{
    int     s1_len;
    int     s2_len;
    int     i;
    char    *tmp;
    char    *tmp2;

    if (!line)
        return ;
    s1_len = ft_strlen(ptr->token);
    s2_len = ft_strlen(line);
    tmp = malloc(s1_len + s2_len + 1 + (*line == 45));
    i = 0;
    while (i < s1_len)
        tmp[i++] = *ptr->token++;
    if (*line == 45)
        tmp[i++] = ' ';
	if (*line == 45)
		s2_len++;
    while (i < s1_len + s2_len)
        tmp[i++] = *(line++);
    tmp[i] = 0;
    ptr->token = tmp;
}

int     ft_strcmp(char *s1, char *s2)
{
    while (*s1 || *s2)
        if (*s1++ != *s2++)
            return (0);
    return (1);
}
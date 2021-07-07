/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:26:51 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/07 18:34:33 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     token_len(char  *str)
{
    int i;

    i = 0;
	if (!str)
		return (0);
    if (chk_symbol(str))
        return (chk_symbol(str));
    if (count_fd(str))
        return (count_fd(str));
    if (chk_redirect(str))
        return (chk_redirect(str));
    while (*str && !(*str == 32 || *str == 9) && !chk_symbol(str) &&
            !chk_redirect(str) && !count_fd(str))
	{
		str++;
        i++;
	}
    return (i);
}

int    line_cpy(t_token *ptr, char *line)
{
    int i;
    int j;
    int size;

    i = 0;
    j = 0;
    while (ptr->token[i])
        i++;
    size = token_len(line);
    ptr->token[i] = malloc(size + 1);
    while (j < size)
        ptr->token[i][j++] = *line++;
    ptr->size++;
    ptr->token[i][j] = 0;
    ptr->token[i + 1] = 0;
    return (j);
}

int     ft_strcmp(char *s1, char *s2)
{
    int i;

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

int     ft_strcmp2(char *s1, char *s2)
{
    while (*s1 || *s2)
        if (*s1++ != *s2++)
            return (0);
    if (*s1 || *s2)
        return (0);
    return (1);
}
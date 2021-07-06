/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:26:51 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/06 12:35:08 by seonkim          ###   ########seoul.kr  */
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
    while (*str && !(*str == 32 || *str == 9) && !chk_symbol(str))
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

    i = 0;
    j = 0;
    while (ptr->token[i])
        i++;
    ptr->token[i] = malloc(ft_strlen(line) + 1);
    if (!chk_symbol(line) && !check_num(line) && !chk_redirect(line))
        while (*line && !(*line == 32 || *line == 9) && !chk_symbol(line) && !check_num(line) && !chk_redirect(line))
            ptr->token[i][j++] = *line++;
    else if (check_num(line))
        while (j < check_num(line))
            ptr->token[i][j++] = *line++;
    else if (chk_redirect(line))
        while (j < chk_redirect(line))
            ptr->token[i][j++] + *line++;
    else if (chk_symbol(line))
        while (j < chk_symbol(line))
            ptr->token[i][j++] = *line++;
    ptr->size++;
    ptr->token[i][j] = 0;
    ptr->token[i + 1] = 0;
    return (j);
}

int     ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
        if (*s1++ != *s2++)
            return (0);
    return (1);
}
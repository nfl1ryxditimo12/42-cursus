/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:26:51 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/06 15:03:27 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int chk_quotes(char *str, char quotes)
{
    int cnt;
    int quote_cnt;

    cnt = 0;
    quote_cnt = 0;
    while (quote_cnt != 2 && *str)
    {
        if (*str == quotes)
            quote_cnt++;
        cnt++;
        str++;
    }
    return (cnt);
}

int     token_len(char  *str, char quotes)
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
    if (quotes == 34 || quotes == 39)
        return(chk_quotes(str, quotes));
    while (*str && !(*str == 32 || *str == 9) && !chk_symbol(str) &&
            !chk_redirect(str) && !count_fd(str))
	{
        if (*str == '\'' || *str == '\"')
            break ;
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
    char quotes;

    i = 0;
    j = 0;
    quotes = 0;
    while (ptr->token[i])
        i++;
    if (*line == '\'' || *line == '\"')
        quotes = *line;
    size = token_len(line, quotes);
    ptr->token[i] = malloc(size + 1);
    while (j < size)
        ptr->token[i][j++] = *line++;
    ptr->size++;
    ptr->token[i][j] = 0;
    ptr->token[++i] = 0;
    return (size);
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

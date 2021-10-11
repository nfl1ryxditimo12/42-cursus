/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:26:51 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/11 16:23:26 by seonkim          ###   ########seoul.kr  */
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

int     check_env_len(char *line)
{
    int size;

    size = 0;
    while (line[size] && (line[size] != 32 || line[size] != 9))
        size++;
    return (size);
}

char    *line_join(char *str, char *line)
{
    
}

// ptr->token[1] = "asdfasd $USER asdf" || command1 || command2
// "asdfasd $USER asdf" => "asdfasd seonkim asdf"

char    *dup_line(char *line, int size, int quotes, char **env)
{
    char *ret;
    int i;

    i = -1;
    while (++i < size)
    {
        // ret = 
    }
    
    return (ret);
}

int    line_cpy(t_token *ptr, char *line, char **env)
{
    int i;
    int size;
    char quotes;

    i = 0;
    quotes = 0;
    while (ptr->token[i])
        i++;
    if (*line == '\'' || *line == '\"')
        quotes = *line;
    size = token_len(line, quotes);
    ptr->token[i] = dup_line(line, size, quotes, env);
    ptr->size++;
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

int     ft_strcmp3(char *s1, char *s2, int size)
{
    int i;

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
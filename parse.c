/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:41:25 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/01 19:01:24 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     chk_symbol(char *line)
{
    if (*line == '<')
        if (*(line + 1) == '<')
            return (2);
    if (*line == '>')
        if (*(line + 1) == '>')
            return (2);
    if (*line == '|')
        if (*(line + 1) == '|')
            return (2);
    if (*line == '&')
        if (*(line + 1) == '&')
            return (2);
    if (*line == '<' || *line == '>' || *line == '|' || *line == '\'' ||
        *line == '\"' || *line == '$' || *line == '?' || *line == '\\')
        return (1);
    return (0);
}

int     get_token_cnt(char *line)
{
    int cnt;

    cnt = 0;
    while (*line)
    {
        while (*line && (*line == 32 || *line == 9 || *line == 45))
            line++;
        if (chk_symbol(line))
        {
            if (chk_symbol(line) > 1)
                line += 2;
            else if (chk_symbol(line) == 1)
                line++;
            cnt++;
        }
        if (*line && !(*line == 32 || *line == 9) && !chk_symbol(line))
        {
            if (*(line - 1) == 45)
                cnt--;
            while (*line && !(*line == 32 || *line == 9) && !chk_symbol(line))
                line++;
            cnt++;
        }
    }
    return (cnt);
}

void    process_split(t_token *ptr, char *line)
{
    while (*line)
    {
        while (*line && (*line == 32 || *line == 9))
            line++;
        if (chk_symbol(line))
        {
            ft_strjoin(ptr, line);
			ptr = ptr->next;
            line += chk_symbol(line);
        }
        if (*line && !(*line == 32 || *line == 9) && !chk_symbol(line))
        {
            if (*line == '-')
                ptr = ptr->pre;
            ft_strjoin(ptr, line);
			ptr = ptr->next;
            while (*line && !(*line == 32 || *line == 9) && !chk_symbol(line))
                line++;
        }
    }
}

void    line_split(t_handler *hand, char *line)
{
    int     size;
    int     i;

    if (!line)
        return ;
    size = get_token_cnt(line);
    hand->top = hand->line;
    i = 0;
    while (++i < size)
        node_push(hand, i + 1);
	hand->line = hand->top;
    process_split(hand->line, line);
}
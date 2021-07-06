/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:41:25 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/06 12:27:21 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     chk_symbol(char *line)
{
    if (*line == '|')
        if (*(line + 1) == '|')
            return (2);
    if (*line == '&')
        if (*(line + 1) == '&')
            return (2);
    if (*line == '|')
        return (1);
    return (0);
}

int     is_num(char c)
{
    if ('0' <= c && c <= '9')
        return (1);
    return (0);
}

int     chk_redirect(char *line)
{
    int cnt;

    cnt = 0;
    if (*line == '<' && *(line + 1) == '<')
        return (2);
    if (*line == '>' && *(line + 1) == '>')
        return (2);
    if (*line == '<' || *line == '>')
        return (1);
    return (0);
}

int     check_num(char *line)
{
    int cnt;

    cnt = 0;
    while (is_num(*line))
    {
        line++;
        cnt++;
    }
    if (*line == '<' || *line == '>')
        return (cnt + 1);
    return (0);
}

int     get_token_cnt(char *line)
{
    int cnt;
    int flag;

    cnt = 0;
    flag = 0;
    while (*line)
    {
        while (*line && (*line == 32 || *line == 9 || *line == 45))
            line++;
        if (chk_symbol(line))
        {
            line += chk_symbol(line);
            flag = 0;
            cnt++;
        }
        if (*line && !(*line == 32 || *line == 9) && !chk_symbol(line))
        {
            if (!flag)
                cnt++;
            while (*line && !(*line == 32 || *line == 9) && !chk_symbol(line))
                line++;
            flag = 1;
        }
    }
    return (cnt);
}

void    process_split(t_token *ptr, char *line)
{
    int flag;

    flag = 0;
    while (*line)
    {
        while (*line && (*line == 32 || *line == 9))
            line++;
        if (chk_symbol(line))
        {
            if (flag == 1 || flag == 2)
			    ptr = ptr->next;
            line_cpy(ptr, line);
            line += chk_symbol(line);
            flag = 2;
        }
        if (check_num(line) || chk_redirect(line))
        {
            if (flag == 1 || flag == 2 || flag == 3)
                ptr = ptr->next;
            line += line_cpy(ptr, line);
            flag = 3;
        }
        if (*line && !(*line == 32 || *line == 9) && !chk_symbol(line))
        {
            if (flag == 2 || flag == 3)
                ptr = ptr->next;
            line += line_cpy(ptr, line);
            while (*line && !(*line == 32 || *line == 9) && !chk_symbol(line))
                line++;
            flag = 1;
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
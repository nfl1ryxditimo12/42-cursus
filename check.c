/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:31:26 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/06 19:37:41 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    builtin_cmd(t_handler *hand)
{
    if (ft_strcmp2(hand->line->token[0], "echo") ||
    ft_strcmp2(hand->line->token[0], "cd") ||
    ft_strcmp2(hand->line->token[0], "pwd") ||
    ft_strcmp2(hand->line->token[0], "export") ||
    ft_strcmp2(hand->line->token[0], "unset") ||
    ft_strcmp2(hand->line->token[0], "env") ||
    ft_strcmp2(hand->line->token[0], "exit"))
    {
        hand->cmd_flag = 1;
        return (1);
    }
    return (0);
}

char    *connect_dir(char *path, char *token)
{
    char    *connect;
    int     i;
    
    if (*token == '~')
        token++;
    connect = malloc(cmd_len(path) + cmd_len(token) + 1);
    i = 0;
    while (path && *path)
        connect[i++] = *path++;
    while (token && *token)
        connect[i++] = *token++;
    connect[i] = 0;
    return (connect);
}

int    not_builtin_cmd(t_handler *hand)
{
    int i;
    char    *cmd[5];

    i = -1;
    while (++i < 5)
        cmd[i] = connect_dir(hand->cmd[i], hand->line->token[0]);
    i = -1;
    while (++i < 5)
    {
        if (!stat(cmd[i], hand->buf))
            hand->line->cmd_dir = cmd[i];
        else
            free(cmd[i]);
    }
    if (hand->line->cmd_dir)
    {
        hand->cmd_flag = 1;
        return (1);
    }
    return (0);
}

int    check_type(t_handler *hand)
{
    if (builtin_cmd(hand) && !hand->cmd_flag)
        return (1);
    if (not_builtin_cmd(hand) && !hand->cmd_flag)
        return (2);
    if (chk_symbol(hand->line->token[0]))
    {
        hand->cmd_flag = 0;
        return (3);
    }
    return (0);
}
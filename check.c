/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:31:26 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/05 16:27:29 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    builtin_cmd(t_handler *hand)
{
    if (ft_strcmp(hand->line->token[0], "echo") ||
    ft_strcmp(hand->line->token[0], "cd") ||
    ft_strcmp(hand->line->token[0], "pwd") ||
    ft_strcmp(hand->line->token[0], "export") ||
    ft_strcmp(hand->line->token[0], "unset") ||
    ft_strcmp(hand->line->token[0], "env") ||
    ft_strcmp(hand->line->token[0], "exit"))
    {
        hand->cmd_flag = 1;
        return (1);
    }
    return (0);
}

int    not_builtin_cmd(t_handler *hand)
{
    int i;
    char    *cmd[5];

    cmd[0] = connect_dir(hand->cmd[0], hand->line->token[0]);
	cmd[1] = connect_dir(hand->cmd[1], hand->line->token[0]);
	cmd[2] = connect_dir(hand->cmd[2], hand->line->token[0]);
	cmd[3] = connect_dir(hand->cmd[3], hand->line->token[0]);
	cmd[4] = connect_dir(hand->cmd[4], hand->line->token[0]);
    i = -1;
    while (++i < 5)
        if (opendir(cmd[i]))
            hand->line->cmd_dir = cmd[i];
    if (hand->line->cmd_dir)
    {
        hand->cmd_flag = 1;
        closedir(cmd[i]);
        return (1);
    }
    closedir(cmd[i]);
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
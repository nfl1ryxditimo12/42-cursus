/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:31:26 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/01 20:39:37 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    builtin_cmd(t_handler *hand)
{
    if (ft_strcmp(hand->line->token, "echo") ||
    ft_strcmp(hand->line->token, "cd") ||
    ft_strcmp(hand->line->token, "pwd") ||
    ft_strcmp(hand->line->token, "export") ||
    ft_strcmp(hand->line->token, "unset") ||
    ft_strcmp(hand->line->token, "env") ||
    ft_strcmp(hand->line->token, "exit"))
    {
        hand->line->type = 0;
        hand->cmd_flag = 1;
    }
    if (hand->line->type == -1)
        return (0);
    return (1);
}

int    not_builtin_cmd(t_handler *hand)
{
    int i;

    hand->cmd[0] = connect_dir("/bin/", hand->line->token[0]);
	hand->cmd[1] = connect_dir("/usr/local/bin/", hand->line->token[0]);
	hand->cmd[2] = connect_dir("/usr/bin/", hand->line->token[0]);
	hand->cmd[3] = connect_dir("/usr/sbin", hand->line->token[0]);
	hand->cmd[4] = connect_dir("/sbin/", hand->line->token[0]);
    i = -1;
    while (++i < 5)
    {
        if (opendir(hand->cmd[i]) != 0)

    }
}

void    check_type(t_handler *hand)
{
    if (builtin_cmd(hand) && !hand->cmd_flag)
        return ;
    if (not_builtin_cmd(hand) && !hand->cmd_flag)
        return ;
    if (chk_symbol(hand->line->token))
        hand->line->type = 1;
    else
        file_or_dir(hand);
}
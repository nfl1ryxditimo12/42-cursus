/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:29:39 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/07 19:06:25 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    process_builtin_cmd(t_handler *hand)
{
    if (ft_strcmp2(hand->line->token[0], "echo"))
        process_echo(hand);
    else if (ft_strcmp2(hand->line->token[0], "cd"))
        process_cd(hand);
    else if (ft_strcmp2(hand->line->token[0], "pwd"))
        printf("%s\n", hand->dir);
    else if (ft_strcmp2(hand->line->token[0], "export"))
        process_export(hand);
    else if (ft_strcmp2(hand->line->token[0], "unset"))
        process_unset(hand);
    else if (ft_strcmp2(hand->line->token[0], "env"))
        process_env(hand);
    else if (ft_strcmp2(hand->line->token[0], "exit"))
        process_exit(hand);
}
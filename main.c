/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:01:43 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/01 19:03:52 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    hand_init(t_handler *hand, char **env)
{
    hand->env = env;
    hand->line = 0;
    node_push(hand, 1);
    hand->top = hand->line;
    hand->clear = 0;
    hand->dir = getcwd(hand->dir, BUFFER_SIZE);
    hand->exit = 0;
    hand->status = 1;
    hand->pid = 0;
    hand->cmd_flag = 0;
}

void    shell_init(t_handler *hand)
{
    int     pid;
    char    *clear;

    pid = fork();
    if (pid == 0)
        execve("/usr/bin/clear", "clear", hand->env);
}

char    *prompt(t_handler *hand)
{
    if (!hand->status)
        return ("😎 \033[0;32m\033[1mminishell \033[0;31m\033[1m▸ \033[0m");
    return ("😎 \033[0;32m\033[1mminishell ▸ \033[0m");
}

void    process(t_handler *hand)
{
    while (hand->line != NULL)
    {
        check_type();
        if (hand->line->type == 0)
            process_command(hand);
        else if (hand->line->type == 1)
            process_file(hand);
        else if (hand->line->type == 2)
            process_symbol(hand);
    }
}

void    process_init(t_handler *hand)
{
    char    *line;

    while (hand->exit == 0)
    {
        line = readline(prompt(hand));
        if (!line)
        {
            hand->status = 0;
            continue ;
        }
        hand->status = 1;
        add_history(line);
        line_split(hand, line);
        hand->line = hand->top;
        hand->pid = fork();
        if (hand->pid == 0)
            process(hand);
    }
}

int main(int ac, char **av, char **env)
{
    t_handler hand;

    (void)ac;
    (void)av;
    hand_init(&hand, env);
    shell_init(&hand);
    process_init(&hand);
}
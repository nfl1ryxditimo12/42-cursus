/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:23:08 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/09 17:30:15 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    hand_init(t_handler *hand, char **env)
{
    hand->line = 0;
    hand->clear = 0;
    getcwd(hand->path->dir, 1024);
    hand->exit = 0;
    hand->status = 1;
    hand->pid = 0;
    hand->cmd_flag = 0;
    hand->token_size = 0;
    hand->path->cmd[0] = "/bin";
    hand->path->cmd[1] = "/usr/local/bin";
    hand->path->cmd[2] = "/usr/bin";
    hand->path->cmd[3] = "/usr/sbin";
    hand->path->cmd[4] = "/sbin";
}

void    shell_init(t_handler *hand, char **env)
{
    pid_t   pid;
    int     status;
    char    *clear[2];

    clear[0] = "clear";
    clear[1] = 0;
    pid = fork();
    if (pid == 0)
        execve("/usr/bin/clear", clear, env);
    else
        waitpid(pid, &status, 0);
}

char    *prompt(t_handler *hand)
{
    if (!hand->status)
        return ("😎 \033[0;32m\033[1mminishell \033[0;31m\033[1m▸ \033[0m");
    return ("😎 \033[0;32m\033[1mminishell ▸ \033[0m");
}

void    process_line(t_handler *hand, char **env)
{
    int check;

    hand->cmd_flag = 0;
    while (hand->line)
    {
        check = check_type(hand);
        if (check == 1)
            process_builtin_cmd(hand);
        else if (check == 2)
            process_non_builtin_cmd(hand, env);
        //else if (check == 3)
        //    process_symbol(hand);
        else if (check == 0)
        {
            perror(hand->line->token[0]);
            break ;
        }
        hand->line = hand->line->next;
    }
}

void    process_init(t_handler *hand, char **env)
{
    char    *line;
    int     status;

    while (hand->exit == 0)
    {
        line = readline(prompt(hand));
        if (!line || !*line)
            hand->status = 0;
        else
        {
            hand_init(hand, env);
            add_history(line);
            line_split(hand, line);
            hand->line = hand->top;
            process_line(hand, env);
            hand_reset(hand);
        }
        free(line);
    }
}
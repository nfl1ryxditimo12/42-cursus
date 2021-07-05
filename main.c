/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:01:43 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/05 16:27:29 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    cmd_init(t_handler *hand)
{
    int i;

    i = -1;
    while (++i < 5)
    {
        if (hand->cmd[i])
            free(hand->cmd[i]);
        hand->cmd[i] = 0;
    }
}

void    print_err(char *err, char *arr)
{
    (void)err;
    (void)arr;
}

void    hand_init(t_handler *hand, char **env)
{
    hand->env = env;
    hand->line = 0;
    node_push(hand, 1);
    hand->top = hand->line;
    hand->clear = 0;
    hand->dir = getcwd(hand->dir, BUFFER_SIZE);
    hand->home_dir = home_dir(env);
    hand->exit = 0;
    hand->status = 1;
    hand->pid = 0;
    hand->cmd_flag = 0;
    hand->cmd[0] = "/bin/";
    hand->cmd[1] = "/usr/local/bin/";
    hand->cmd[2] = "/usr/bin/";
    hand->cmd[3] = "/usr/sbin";
    hand->cmd[4] = "/sbin/";
}

void    shell_init(t_handler *hand, char **env)
{
    int     pid;
    char    *clear[2];

    clear[0] = "clear";
    clear[1] = 0;
    pid = fork();
    if (pid == 0)
        execve("/usr/bin/clear", clear, env);
}

char    *prompt(t_handler *hand)
{
    if (!hand->status)
        return ("😎 \033[0;32m\033[1mminishell \033[0;31m\033[1m▸ \033[0m");
    return ("😎 \033[0;32m\033[1mminishell ▸ \033[0m");
}

void    process_line(t_handler *hand)
{
    int check;

    hand->cmd_flag = 0;
    while (hand->line)
    {
        check = check_type(hand);
        if (check == 1)
            process_builtin_cmd(hand);
        else if (check == 2)
            process_non_builtin_cmd(hand);
        else if (check == 3)
            process_symbol(hand);
        else if (check == 0)
            perror(hand->line->token[0]);
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
        if (!line)
        {
            hand->status = 0;
            continue ;
        }
        hand_init(hand, env);
        add_history(line);
        line_split(hand, line);
        hand->line = hand->top;
        hand->pid = fork();
        if (hand->pid > 0)
            waitpid(hand->pid, &status, 0);
        else if (hand->pid == 0)
            process_line(hand);
    }
}

int main(int ac, char **av, char **env)
{
    t_handler hand;

    (void)ac;
    (void)av;
    hand.status = 1;
    shell_init(&hand, env);
    process_init(&hand, env);
}
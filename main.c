/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:01:43 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/09 17:36:27 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    process_non_builtin_cmd(t_handler *hand, char **env)
{
    int i;
    pid_t pid;
    int status;
    
    pid = fork();
    if (pid == 0)
        execve(hand->line->cmd_dir, &hand->line->token[0], env);
    else
        waitpid(pid, &status, 0);
}

void    hand_reset(t_handler *hand)
{
    int i;
    t_token *ptr;

    i = -1;
    hand->line = hand->top;
    while (hand->line)
    {
        while (hand->line->token[++i])
            if (hand->line->token[i])
            {
                free(hand->line->token[i]);
                hand->line->token[i] = NULL;
            }
        if (hand->line->cmd_dir)
            free(hand->line->cmd_dir);
        ptr = hand->line;
        hand->line = hand->line->next;
        if (hand->line)
            hand->line->pre = NULL;
        ptr->next = NULL;
        free(ptr);
        ptr = NULL;
    }
    hand->line = NULL;
}

int main(int ac, char **av, char **env)
{
    t_handler hand;

    (void)ac;
    (void)av;
    hand.env = env_control(env);
    hand.status = 1;
    hand.path->home_dir = getenv("HOME");
    shell_init(&hand, env);
    process_init(&hand, env);
}
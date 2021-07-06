/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:36:19 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/06 19:30:07 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     env_len(char **env)
{
    int i;

    i = 0;
    if (!env || !env[i])
        return (0);
    while(env[i])
        i++;
    return (0);
}

void    free_env(char **env)
{
    int i;

    i = -1;
    while (env[++i])
        free(env[i]);
    free(env);
}

char    **dup_env(t_handler *hand, char **env, int flag)
{
    int     size;
    int     i;
    int     j;
    char    **ret;
    
    size = env_len(env);
    if (flag)
        size++;
    ret = (char **)malloc(sizeof(char *) * size + 1);
    i = -1;
    while (env[++i])
    {
        j = -1;
        ret[i] = malloc(cmd_len(env[i]) + 1);
        while (env[i][++j])
            ret[i][j] = env[i][j];
        ret[i][j] = 0;
    }
    if (flag)
        ret[i++] = dir_cpy(hand->line->token[1]);
    ret[i] = 0;
    return (ret);
}

void    process_export(t_handler *hand)
{
    int i;
    int flag;
    char **tmp;

    if (hand->line->token[2])
        perror(hand->line->token[2]);
    tmp = dup_env(hand, hand->env, 1);
    free_env(hand->env);
    hand->env = tmp;
}
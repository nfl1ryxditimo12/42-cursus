/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:16:43 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/23 20:39:40 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int     env_len(char **env)
{
    int i;

    i = 0;
    if (!env || !env[0] || !env[0][0])
        return (0);
    while(env[i])
        i++;
    return (i);
}

void    free_env(char **env)
{
    int i;

    i = -1;
    while (++i < 50)
    {
        free(env[i]);
        env[i] = NULL;
    }
    free(env);
    env = NULL;
}

char    **env_control(char **env)
{
    int size;
    int i;
    char **ret;

    size = env_len(env);
    ret = (char **)lmt_alloc(sizeof(char *) * 50 + 1);
    i = -1;
    while (++i < size)
    {
        ret[i] = ft_strdup(env[i]);
        ret[i][cmd_len(env[i])] = 0;
    }
    while (i < 50)
        ret[i++] = 0;
    return (ret);
}

void    process_env(t_handler *hand)
{
    int i;
    int size;

    i = -1;
    size = env_len(hand->env);
    if (hand->line->size > 1)
    {
        hand->status = 127;
        while (++i < hand->line->size)
            printf("env: %s: No such file or directory\n", hand->line->token[i + 1]);
    }
    else
    {
        hand->status = 0;
        while (++i < size)
            printf("%s\n", hand->env[i]);
    }
}
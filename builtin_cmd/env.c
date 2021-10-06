/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:16:43 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/05 13:40:37 by seonkim          ###   ########seoul.kr  */
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
    ret = (char **)malloc(sizeof(char *) * 50 + 1);
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
    while (++i < size)
        printf("%s\n", hand->env[i]);
}
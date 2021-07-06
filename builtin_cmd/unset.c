/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:19:02 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/06 19:29:06 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *home_dir(char **env)
{
    int i;
    int j;
    char    *home;

    i = -1;
    while (env[++i])
        if (ft_strcmp(env[i], "HOME="))
            break ;
    home = malloc(cmd_len(env[i]) - 3);
    j = 0;
    while (env[i][j + 5])
    {
        home[j] = env[i][j + 5];
        j++;
    }
    home[j] = '/';
    home[j + 1] = 0;
    return (home);
}

char    **sub_env(t_handler *hand, char **env)
{
    int     size;
    int     i;
    int     j;
    char    **ret;
    
    size = env_len(env);
    ret = (char **)malloc(sizeof(char *) * size);
    i = -1;
    while (env[++i])
    {
        j = -1;
        if (ft_strcmp(env[i], hand->line->token[1]))
            continue ;
        ret[i] = malloc(cmd_len(env[i]) + 1);
        while (env[i][++j])
            ret[i][j] = env[i][j];
        ret[i][j] = 0;
    }
    ret[i] = 0;
    return (ret);
}

void    process_unset(t_handler *hand)
{
    int i;
    int flag;
    char    *tmp;

    if (hand->line->token[2])
        perror(hand->line->token[2]);
    i = -1;
    flag = 0;
    while (hand->env[++i])
        if (ft_strcmp(hand->env[i], hand->line->token[1]))
            flag++;
    if (flag == 1)
    {
        tmp = sub_env(hand, hand->env);
        free_env(hand->env);
        hand->env = tmp;
    }
}
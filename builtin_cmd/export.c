/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:36:19 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/23 20:09:51 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char    *get_env_value2(char *env)
{
    int     i;
    int     j;
    int     size;
    char    *ret;

    i = 0;
    size = cmd_len(env);
    while (env[i] != '=')
        i++;
    i++;
    ret = lmt_alloc(size - i + 1);
    j = 0;
    while (i < size)
        ret[j++] = env[i++];
    ret[j] = 0;
    return (ret);
}

static char    *get_env_value(char *env)
{
    int i;
    int size;
    char    *ret;

    size = 0;
    while (env[size] && env[size] != '=')
        size++;
    if (!env[size])
        perror(env);
    size++;
    ret = lmt_alloc(size + 1);
    i = -1;
    while (++i < size)
        ret[i] = env[i];
    ret[i] = 0;
    return (ret);
}

void    declare_env(t_handler *hand)
{
    int i;
    char    *tmp1;
    char    *tmp2;

    i = -1;
    while (hand->env[++i])
    {
        tmp1 = get_env_value(hand->env[i]);
        tmp2 = get_env_value2(hand->env[i]);
        printf("declare -x %s\"%s\"\n", tmp1, tmp2);
        free(tmp1);
        free(tmp2);
    }
}

void    dup_env(t_handler *hand)
{
    int     i;
    int     flag;
    char    *arg;

    arg = get_env_value(hand->line->token[1]);
    i = -1;
    flag = 0;
    while (hand->env[++i])
        if (ft_strcmp(hand->env[i], arg))
        {
            flag = 1;
            break ;
        }
    if (flag)
        free(hand->env[i]);
    hand->env[i] = ft_strdup(hand->line->token[1]);
    free(arg);
}

void    process_export(t_handler *hand)
{
    if (hand->line->token[2])
        perror(hand->line->token[2]);
    else if (!hand->line->token[1])
    {
        declare_env(hand);
        return ;
    }
    dup_env(hand);
}

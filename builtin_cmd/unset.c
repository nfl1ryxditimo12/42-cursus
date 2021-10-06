/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:19:02 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/06 15:58:35 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char *get_env_value(char *env)
{
    int i;
    int size;
    char    *ret;

    size = 0;
    while (env[size])
        size++;
    size++;
    ret = malloc(size + 1);
    i = -1;
    while (++i < size)
        ret[i] = env[i];
    ret[i] = '=';
    ret[i + 1] = 0;
    return (ret);
}

char    **sub_env(t_handler *hand)
{
    int     size;
    int     i;
    char    **ret;
    char    *arg;
    
    size = env_len(hand->env);
    arg = get_env_value(hand->line->token[1]);
    ret = (char **)malloc(sizeof(char *) * 50 + 1);
    i = -1;
    while (hand->env[++i])
        if (!ft_strcmp(hand->env[i], arg))
            ret[i] = ft_strdup(hand->env[i]);
    while (i < 50)
        ret[i++] = 0;
    free(arg);
    return (ret);
}

void    process_unset(t_handler *hand)
{
    int i;
    int flag;
    char    **tmp;

    if (hand->line->token[2])
        perror(hand->line->token[2]);
    else if (!hand->line->token[1])
        return ;
    i = -1;
    flag = 0;
    while (hand->env[++i])
        if (ft_strcmp(hand->env[i], hand->line->token[1]))
            flag = 1;
    if (flag == 1)
    {
        tmp = sub_env(hand);
        free_env(hand->env);
        hand->env = tmp;
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:19:02 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/24 17:39:42 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    sub_env(t_handler *hand)
{
    int     i;
    int     j;
    char    **ptr;
    char    **ret;
    char    *key;
    
    ptr = hand->line->token + 1;
    while (*ptr)
    {
        j = 0;
        ret = (char **)lmt_alloc(sizeof(char *) * 50 + 1);
        i = -1;
        while (hand->env[++i])
        {
            key = get_env_key(hand->env[i]);
            if (!ft_strcmp2(key, *ptr))
                ret[j++] = ft_strdup(hand->env[i]);
            free(key);
        }
        while (i < 50)
            ret[i++] = 0;
        free_env(hand->env);
        hand->env = ret;
        ret = NULL;
        ptr++;
    }
}

void    process_unset(t_handler *hand)
{
    if (!is_right_environ(hand->line) && !hand->line->token[1])
    {
        hand->status = 1;
        printf("Unset Error!!\n");
    }
    else
    {
        hand->status = 0;
        sub_env(hand);
    }
}

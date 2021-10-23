/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:35:06 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/23 20:47:28 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    process_exit(t_handler *hand)
{
    int i;

    i = 0;
    printf("exit\n");
    if (hand->line->size > 1)
    {
        while(++i < hand->line->size)
            printf("exit: %s: numeric argument required\n", hand->line->token[i]);
        hand->status = 255;
    }
    hand->exit = 1;
}
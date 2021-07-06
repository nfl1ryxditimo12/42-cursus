/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:16:43 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/06 19:18:41 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    process_env(t_handler *hand)
{
    int i;

    i = -1;
    while (hand->env[++i])
        printf("%s\n", hand->env[i]);
}
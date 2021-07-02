/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:29:39 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/02 18:03:37 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    process_echo(t_handler *hand)
{
    int     option;
    int     i;
    char    *echo;
	char	*tmp;

    option = 0;
    if (hand->line->token[1][0] == '-' && hand->line->token[1][1] == 'n')
        option = 1;
    i = 1 + option;
    while (i < hand->line->size)
    {
		tmp = ft_strjoin(echo, token[i], hand->line->size - (i + 1), option);
		if (echo)
			free(echo);
		echo = tmp;
		i++;
    }
    printf("%s", echo);
    free(echo);
}




void    process_builtin_cmd(t_handler *hand)
{
    if (ft_strcmp(hand->line->token[0], "echo"))
        process_echo(hand);
    else if (ft_strcmp(hand->line->token[0], "cd"))
        process_cd(hand);
    else if (ft_strcmp(hand->line->token[0], "pwd"))
        process_pwd(hand);
    else if (ft_strcmp(hand->line->token[0], "export"))
        process_export(hand);
    else if (ft_strcmp(hand->line->token[0], "unset"))
        process_unset(hand);
    else if (ft_strcmp(hand->line->token[0], "env"))
        process_env(hand);
    else if (ft_strcmp(hand->line->token[0], "exit"))
        process_env(hand);
}
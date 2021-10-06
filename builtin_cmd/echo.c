/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:05:45 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/06 15:33:02 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char    *echo_connect(char *s1, char *s2, int size, int option)
{
    char    *ret;
    int     i;

    i = 0;
    ret = malloc(cmd_len(s1) + cmd_len(s2) + 2);
    while (s1 && *s1)
        ret[i++] = *s1++;
    while (s2 && *s2)
        ret[i++] = *s2++;
    if (size)
        ret[i] = ' ';
    else if (!size && !option)
        ret[i] = '\n';
    else if (!size && option)
        ret[i] = 0;
    ret[i + 1] = 0;
    return (ret);
}

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
		tmp = echo_connect(echo, hand->line->token[i],
                            hand->line->size - (i + 1), option);
		if (*echo)
			free(echo);
		echo = tmp;
		i++;
    }
    printf("%s", echo);
    free(echo);
}

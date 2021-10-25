/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:05:45 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/25 14:48:18 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_echo_option(char *str)
{
	if (*str++ != '-')
		return (0);
	while (*str)
		if (*str++ != 'n')
			return (0);
	return (1);
}

void	print_echo(t_token *line, int i, int option)
{
	while (line->token[++i])
	{
		printf("%s", line->token[i]);
		if (line->token[i + 1])
			printf(" ");
	}
	if (!option)
		printf("\n");
}

void	process_echo(t_handler *hand)
{
	int	option;
	int	i;

	option = 0;
	i = 0;
	while (hand->line->token[++i])
	{
		if (is_echo_option(hand->line->token[i]))
			option = 1;
		else
			break ;
	}
	print_echo(hand->line, i - 1, option);
	hand->status = 0;
}

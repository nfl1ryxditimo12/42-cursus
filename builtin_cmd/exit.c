/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:35:06 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/28 21:20:00 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_number(char *str)
{
	while (*str)
	{
		if (!(48 <= *str && *str <= 57))
			return (0);
		str++;
	}
	return (1);
}

void	process_exit(t_handler *hand)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	hand->status = 1;
	printf("exit\n");
	if (hand->line->size == 2)
	{
		if (!is_number(hand->line->token[1]))
		{
			printf("exit: %s: numeric argument required\n", \
				hand->line->token[1]);
			hand->status = 255;
		}
		else
		{
			while (hand->line->token[1][j])
				i = i * 10 + hand->line->token[1][j++] - 48;
			hand->status = i;
		}
	}
	else if (hand->line->size > 2)
		printf("exit: too many arguments\n");
	hand->exit = 1;
}

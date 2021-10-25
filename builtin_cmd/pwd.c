/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:21:19 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/25 14:44:52 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_pwd(t_handler *hand)
{
	int	i;

	i = 0;
	if (hand->line->size > 1 && *hand->line->token[1] == '-')
	{
		hand->status = 1;
		while (++i < hand->line->size)
			printf("pwd: %s: invalid option\n", hand->line->token[i]);
	}
	else
	{
		hand->status = 0;
		printf("%s\n", hand->path->dir);
	}
}

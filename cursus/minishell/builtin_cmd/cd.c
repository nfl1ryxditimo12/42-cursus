/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:02:11 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/30 19:02:04 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	process_cd(t_handler *hand)
{
	char	*dir;

	if (!hand->line->token[1] || ft_strcmp2(hand->line->token[1], "~"))
		dir = ft_strdup(hand->path->home_dir);
	else if (ft_strcmp(hand->line->token[1], "~/"))
		dir = connect_dir(hand->path->home_dir, hand->line->token[1]);
	else if (hand->line->token[1][0] == '/')
		dir = ft_strdup(hand->line->token[1]);
	else
		dir = connect_dir(hand->path->dir, hand->line->token[1]);
	hand->status = 0;
	if (chdir(dir))
	{
		lmt_perror(dir);
		hand->status = 1;
	}
	else
		getcwd(hand->path->dir, 1024);
	free(dir);
}

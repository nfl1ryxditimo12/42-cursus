/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:57 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 15:50:26 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_REDIRECTION_H
# define T_LMT_REDIRECTION_H

# include "lmt_util.h"

typedef struct s_lmt_redirection
{
	int	fd;
	char	*path;
}	t_lmt_redirection;

//	type function
t_lmt_redirection	*lmt_redirection_new();
void	lmt_redirection_free(t_lmt_redirection *p_lmt_redirection);

#endif

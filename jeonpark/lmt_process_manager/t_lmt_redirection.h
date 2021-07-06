/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:57 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 18:38:02 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_REDIRECTION_H
# define T_LMT_REDIRECTION_H

typedef struct s_lmt_redirection
{
	int	fd;
	int	type;
	int	fd2;
	char	*path;
	struct s_lmt_redirection	*next;
}	t_lmt_redirection;

//	type function
t_lmt_redirection	*lmt_redirection_new(int fd, char *path, int fd2);
void	lmt_redirection_free(t_lmt_redirection *p_lmt_redirection, int option);

//	meethod function
void	lmt_redirection_apply(t_lmt_redirection *p_redirection);

#endif

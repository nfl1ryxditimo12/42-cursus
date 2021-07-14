/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:57 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/14 11:20:39 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_REDIRECTION_H
# define T_LMT_REDIRECTION_H

typedef struct s_lmt_redirection
{
	int	fd_old;
	int	type;
	int	fd_new;
	const char	*path_new;
	struct s_lmt_redirection	*next;
}	t_lmt_redirection;

//	type function
t_lmt_redirection	*lmt_redirection_new(int fd_old, int type, int fd_new, const char *path_new);
void	lmt_redirection_free(t_lmt_redirection *p_lmt_redirection, int option);

//	meethod function
void	lmt_redirection_apply(t_lmt_redirection *p_redirection);
t_lmt_redirection	*lmt_redirection_new_by_string_array(t_lmt_string_array *array);
int	lmt_redirection_backup(t_lmt_redirection *p_redirection);

#endif

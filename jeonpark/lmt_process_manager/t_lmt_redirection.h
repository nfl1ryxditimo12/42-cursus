/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:57 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/08 19:04:59 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_REDIRECTION_H
# define T_LMT_REDIRECTION_H

typedef struct s_lmt_redirection
{
	int	fd;
	char	*path;
	int	type;
	int	fd2;
	struct s_lmt_redirection	*next;
}	t_lmt_redirection;

//	type function
t_lmt_redirection	*lmt_redirection_new(int fd, char *path, int type, int fd2);
void	lmt_redirection_free(t_lmt_redirection *p_lmt_redirection, int option);

//	meethod function
void	lmt_redirection_apply(t_lmt_redirection *p_redirection);
t_lmt_redirection	*lmt_redirection_new_by_string_array(t_lmt_string_array *array);
int	lmt_redirection_backup(t_lmt_redirection *p_redirection);

#endif

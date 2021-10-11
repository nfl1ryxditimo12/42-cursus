/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:57 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/11 19:36:32 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_REDIRECTION_H
# define T_LMT_REDIRECTION_H

#include "minishell.h"	// t_token
#include "lmt_c_library.h"
#include "constant.h"
#include "lmt_extension_token.h"

//	redirection 을 처리하기 위한 정보를 담고 있는 구조체
typedef struct s_lmt_redirection
{
	int							type;
	const char					*path;
	struct s_lmt_redirection	*next;
}	t_lmt_redirection;

//	type function
t_lmt_redirection	*lmt_redirection_new(int type, const char *path);
void	lmt_redirection_free(t_lmt_redirection *p_lmt_redirection, int option);

//	meethod function
void	lmt_redirection_apply(t_lmt_redirection *p_redirection);
t_lmt_redirection	*lmt_redirection_new_by_token(t_token *p_token);
int	lmt_redirection_backup(t_lmt_redirection *p_redirection);

#endif

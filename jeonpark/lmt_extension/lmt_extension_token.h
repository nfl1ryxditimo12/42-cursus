/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_extension_token.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:30:06 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/10 13:06:56 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_EXTENSION_TOKEN_H
# define LMT_EXTENSION_TOKEN_H

# include "minishell.h"	// t_token
# include "lmt_c_library.h"	// t_lmt_string
# include "lmt_util.h"	// is_type_()
# include "constant.h"	// TYPE_

void	lmt_arrange_token(t_handler *handler);

int		lmt_is_token_type_control_operator(t_token *token);
int		lmt_is_token_type_redirection(t_token *token);
int		lmt_is_token_type_open_parenthesis(t_token *token);
int		lmt_is_token_type_close_parenthesis(t_token *token);
int		lmt_is_token_type_command(t_token *token);

void	lmt_refine_token_argv_0(t_token *p_command_token);

void	lmt_insert_token_first(t_token *first_token, t_token *element);
t_token	*lmt_remove_token(t_token *token);

void	lmt_set_token_type(t_token *p_first_token);

#endif

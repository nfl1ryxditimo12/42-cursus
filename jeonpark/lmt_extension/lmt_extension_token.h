/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_tokenize.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:15:27 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/07 19:50:25 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_EXTENSION_TOKEN_H
# define LMT_EXTENSION_TOKEN_H

# include "minishell.h"
# include "lmt_c_library.h"
# include "lmt_util.h"

int	lmt_is_token_type_control_operator(t_token *p_token);
int	lmt_is_token_type_redirection(t_token *p_token);
int	lmt_is_token_type_open_parenthesis(t_token *p_token);
int	lmt_is_token_type_close_parenthesis(t_token *p_token);
int	lmt_is_token_type_command(t_token *p_token);

#endif

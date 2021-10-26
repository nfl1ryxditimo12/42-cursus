/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_redirection.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:43:58 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/26 17:02:04 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_REDIRECTION_H
# define LMT_REDIRECTION_H

# include "t_lmt_process_manager.h"
# include "minishell.h"	// t_token
# include "lmt_c_library.h"
# include "constant.h"

int	lmt_attach_redirection(t_token *token, t_lmt_redirection_word_line **word_line, int std_in, int std_out);

#endif

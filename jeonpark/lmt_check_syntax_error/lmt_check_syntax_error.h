/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_check_syntax_error.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:10:00 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/07 16:14:13 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_CHECK_SYNTAX_ERROR_H
# define LMT_CHECK_SYNTAX_ERROR_H

# include "minishell.h"
# include "lmt_extension_token.h"
# include "lmt_c_library.h"

int	lmt_check_syntax_error(t_token *p_first_token);

#endif

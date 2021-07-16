/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_tokenize.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:15:27 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/16 18:15:29 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_TOKENIZE_H
# define LMT_TOKENIZE_H

# include "minishell.h"

int	lmt_is_token_type_operator(t_token *p_token);
int	lmt_is_token_type_redirection(t_token *p_token);
void	lmt_tokenize_parse(t_token *iterator);

#endif

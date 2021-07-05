/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:54:16 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/05 11:45:45 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_TOKEN_H
# define T_LMT_TOKEN_H

typedef struct s_lmt_token
{
	int	type;
	char	*string;
	struct s_lmt_token	*next;
}	t_lmt_token;

//	type function
t_lmt_token	*lmt_token_new(int type, char *string);
void	lmt_token_free(t_lmt_token *p_token);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_extension_token_remove.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:23:11 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/10 13:15:48 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// free()
#include "lmt_extension_token.h"

void	lmt_insert_token_first(t_token *first_token, t_token *element)
{
	element->pre = first_token->pre;
	element->next = first_token;
	if (element->pre != NULL)
		element->pre->next = element;
	element->next->pre = element;
}

t_token	*lmt_remove_token(t_token *token)
{
	if (token->pre != NULL)
		token->pre->next = token->next;
	if (token->next != NULL)
		token->next->pre = token->pre;
	return (token);
}

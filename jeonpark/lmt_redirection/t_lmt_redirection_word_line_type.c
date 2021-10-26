/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_word_line.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:39:42 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/26 15:53:15 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// free()
#include "t_lmt_redirection_word_line.h"
#include "lmt_c_library.h"	// lmt_alloc()

static t_lmt_redirection_word_line	*lmt_redirection_word_line_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_redirection_word_line)));
}

static void	lmt_redirection_word_line_init(t_lmt_redirection_word_line *word_line, char *value)
{
	word_line->value = value;
}

t_lmt_redirection_word_line	*lmt_redirection_word_line_new(char *value)
{
	t_lmt_redirection_word_line	*word_line;

	word_line = lmt_redirection_word_line_alloc();
	lmt_redirection_word_line_init(word_line, value);
	return (word_line);
}

void	lmt_redirection_word_line_free(t_lmt_redirection_word_line *dummy)
{
	t_lmt_redirection_word_line	*element;
	t_lmt_redirection_word_line	*next;

	if (dummy == NULL)
		return ;
	element = dummy->next;
	next = element->next;
	while (element != dummy)
	{
		free(element->value);
		free(element);
		element = next;
		next = element->next;
	}
	free(element);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_convert_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:30:53 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 09:45:05 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lmt_c_library.h"
#include "lmt_unsafe.h"
#include "lmt_helper.h"

static char	**new_str_init(void)
{
	char	**ret;
	int		i;

	ret = (char **)lmt_alloc(sizeof(char *) * 101);
	i = -1;
	while (++i < 101)
		ret[i] = NULL;
	return (ret);
}

static void	lmt_rebuild_token(t_token *element)
{
	t_lmt_string	*tmp;
	char			**new_str;
	int				i;
	int				j;

	i = -1;
	j = 0;
	new_str = new_str_init();
	while (element->token[++i])
	{
		tmp = lmt_string_new(new_str[j]);
		free(new_str[j]);
		lmt_string_append_string(tmp, element->token[i]);
		free(element->token[i]);
		element->token[i] = NULL;
		new_str[j] = tmp->value;
		if (element->space[i] == 1)
			j++;
		free(tmp);
	}
	i = -1;
	while (new_str[++i])
		element->token[i] = new_str[i];
	free(new_str);
}

void	lmt_convert_list(t_handler *handler)
{
	t_token	*element;

	element = handler->top;
	while (element != NULL)
	{
		lmt_convert_token(element, handler->status);
		lmt_rebuild_token(element);
		if (is_type_control_operator(element->type))
			handler->status = 0;
		element = element->next;
	}
}

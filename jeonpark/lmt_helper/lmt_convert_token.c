/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_convert_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:42:56 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 09:44:54 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_helper.h"

static int	is_question(char *str)
{
	while (*str)
		if (*str++ == '$')
			if (*str && *str == '?')
				return (1);
	return (0);
}

static void	lmt_convert_question(char **element, int status)
{
	char	*status_str;
	char	*converted;
	char	*question;
	char	*ptr;

	while (is_question(*element) && **element != '\'')
	{
		status_str = lmt_itoa(status);
		question = *element;
		while (*question && (*question != '$' && *(question + 1) != '?'))
			++question;
		converted = lmt_alloc(lmt_unsafe_strlen(*element) - 1 + \
					lmt_unsafe_strlen(status_str));
		*question = '\0';
		ptr = lmt_unsafe_strcpy(converted, *element);
		ptr = lmt_unsafe_strcpy(ptr, status_str);
		ptr = lmt_unsafe_strcpy(ptr, question + 2);
		*ptr = '\0';
		free(*element);
		*element = converted;
		free(status_str);
	}
}

static char	*lmt_strldup(char *str, int size)
{
	char	*ret;
	int		i;

	i = -1;
	if (!str || !*str)
		return (0);
	ret = lmt_alloc(size + 1);
	while (++i < size)
		ret[i] = str[i];
	ret[i] = 0;
	return (ret);
}

static void	lmt_remove_quotes(char **element)
{
	char	*ptr;

	if (**element == '\"' || **element == '\'')
	{
		ptr = *element;
		*element = lmt_strldup((*element) + 1, \
					lmt_unsafe_strlen((*element) + 1) - 1);
		free(ptr);
	}
}

void	lmt_convert_token(t_token *token, int status)
{
	char	**element;

	element = token->token;
	while (*element != NULL)
	{
		lmt_convert_question(element, status);
		lmt_remove_quotes(element);
		element++;
	}
}

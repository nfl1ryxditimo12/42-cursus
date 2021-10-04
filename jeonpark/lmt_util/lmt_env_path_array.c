/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_env_path_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:05:45 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/05 11:11:04 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lmt_util.h"

static int	lmt_get_env_path_element_count(char *path_string)
{
	int	count;

	if (path_string == NULL)
		return (0);
	count = 1;
	while (*path_string != '\0')
	{
		if (*path_string == ':')
			++count;
		++path_string;
	}
	return (count);
}

static char	**lmt_env_path_array_alloc(int count)
{
	return (lmt_alloc(sizeof(char *) * count + 1));
}

//	Before:	element1:element2:element3
//	After:	element1 element2 element3
//	array:  ^        ^        ^        NULL

static void	lmt_env_path_array_init(char **env_path_array, char *env_path_string)
{
	*env_path_array = env_path_string;
	if (env_path_string == NULL)
		return ;
	++env_path_array;
	while (*env_path_string != '\0')
	{
		if (*env_path_string == ':')
		{
			*env_path_string = '\0';
			++env_path_string;
			*env_path_array = env_path_string;
			++env_path_array;
		}
		else
			++env_path_string;
	}
	*env_path_array = NULL;
}

char	**lmt_env_path_array_new(void)
{
	char	*env_path_string;
	int		element_count;
	char	**env_path_array;

	env_path_string = getenv("PATH");
	element_count = lmt_get_env_path_element_count(env_path_string);
	env_path_array = lmt_env_path_array_alloc(element_count);
	lmt_env_path_array_init(env_path_array, env_path_string);
	return (env_path_array);
}

void	lmt_env_path_array_free(char **array)
{
	if (*array != NULL)
		free(*array);
	free(array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_array.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:32:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 15:38:32 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_redirection_array.h"
#include "lmt_util.h"

static t_lmt_redirection	*lmt_redirection_array_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_redirection) * REDIRECTION_TYPE_COUNT));
}

static void	lmt_redirection_array_init(t_lmt_redidrection *array)
{
	lmt_redirection_init(array[IN], IN, NULL);
	lmt_redirection_init(array[OUT], OUT, NULL);
	lmt_redirection_init(array[ERR], ERR, NULL);
}

t_lmt_redidrection	*lmt_redirection_array_new(void)
{
	t_lmt_redidrection	*array;

	array = lmt_redirection_array_alloc();
	lmt_redirection_array_init(array);
	return (array);
}

void	lmt_redirection_array_free(t_lmt_redidrection *array)
{
	lmt_redirection_free(array[IN]);
	lmt_redirection_free(array[OUT]);
	lmt_redirection_free(array[ERR]);
	free(array);
}

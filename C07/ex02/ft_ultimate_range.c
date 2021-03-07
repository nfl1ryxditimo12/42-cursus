/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 23:41:30 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/07 11:12:58 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *ptr;
	int ret;

	ret = max - min;
	if (min >= max)
		return (0);
	*range = (int *)malloc(sizeof(int) * ret);
	if (!*range)
		return (-1);
	ptr = *range;
	while (min < max)
	{
		*ptr = min;
		min++;
		ptr++;
	}
	return (ret);
}

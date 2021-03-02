/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 23:41:30 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/02 23:58:15 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *ptr;

	if (min >= max)
		return (0);
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (!*range)
		return (-1);
	ptr = *range;
	while (min < max)
	{
		*ptr = min;
		min++;
		ptr++;
	}
	return (max - min);
}

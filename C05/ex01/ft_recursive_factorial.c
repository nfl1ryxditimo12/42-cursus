/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:12:24 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/02 17:17:25 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	factorial(int nb)
{
	int num;

	num = nb;
	if (nb == 0)
		return (1);
	num *= factorial(nb - 1);
	return (num);
}

int	ft_recursive_factorial(int nb)
{
	if (nb <= 0)
		return (0);
	return (factorial(nb));
}


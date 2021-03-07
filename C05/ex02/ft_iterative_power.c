/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:17:41 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/08 01:55:17 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int num;

	num = 1;
	if (nb < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		num *= nb;
		power--;
	}
	return (num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:17:41 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/08 04:19:34 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int num;

	num = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (--power)
		num *= nb;
	return (num);
}

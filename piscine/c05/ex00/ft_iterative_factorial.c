/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:07:58 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/06 15:22:55 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int num;

	num = nb;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	while (nb - 1 != 0)
	{
		num *= nb - 1;
		nb--;
	}
	return (num);
}

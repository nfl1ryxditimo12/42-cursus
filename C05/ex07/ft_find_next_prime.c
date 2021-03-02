/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:59:40 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/03 01:28:15 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int i;
	int check;
	
	if (nb < 3)
		return (2);
	while (nb)
	{
		i = 2;
		check = 0;
		while (i < nb)
		{
			if (nb % i == 0)
				check++;
			i++;
		}
		if (check == 0)
			break ;
		nb++;
	}
	return (nb);
}

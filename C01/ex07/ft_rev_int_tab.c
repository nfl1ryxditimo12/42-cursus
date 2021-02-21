/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:09:45 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/21 23:26:56 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int reverse_tab[1000000];
	int i;
	int j;
	
	size--;
	i = 0;
	j = size;
	while (i <= size)
	{
		reverse_tab[i] = tab[j];
		i++;
		j--;
	}
	i = 0;
	while (i <= size)
	{
		tab[i] = reverse_tab[i];
		i++;
	}
}

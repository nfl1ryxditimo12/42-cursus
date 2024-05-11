/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:03:50 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/16 18:22:45 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int j;
	int compare;

	i = -1;
	j = 0;
	while (++i < length - 1)
	{
		compare = f(tab[i], tab[i + 1]);
		if (compare == 0)
			continue ;
		if (j == 0)
			j = compare;
		else if ((j < 0 && compare > 0) || (j > 0 && compare < 0))
			return (0);
	}
	return (1);
}

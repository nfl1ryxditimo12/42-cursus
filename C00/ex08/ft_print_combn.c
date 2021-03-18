/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:54:44 by seonkim           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/16 15:40:43 by seonkim          ###   ########.fr       */
=======
/*   Updated: 2021/03/14 15:41:34 by seonkim          ###   ########.fr       */
>>>>>>> 5a1bcf3de2bb113a5eb48ed378a3f1b87b1c33d7
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

<<<<<<< HEAD
void	print_combn(int n, int *comb)
{
	int		i;
	char	c;

	i = -1;
	while (++i < n)
	{
		c = comb[i] + '0';
		write(1, &c, 1);
	}
	if (!(comb[0] == 10 - n && comb[n - 1] == 9))
		write(1, ", ", 2);
}

void	process(int depth, int n, int *comb)
{
	int i;

	if (depth == n)
	{
		print_combn(n, comb);
		return ;
	}
	if (depth == 0)
		i = 0;
	else
		i = comb[depth - 1] + 1;
	while (i < 10)
	{
		comb[depth] = i;
		process(depth + 1, n, comb);
		i++;
=======
int	g_len;
char	g_nbr[10];

void	rec(int prev, int n)
{
	int i;

	if (n == glen)
	{
		
	}
}

void	print_last(int i)
{
	
}

void	ft_print_combn(int n)
{
	int i;

	i = 0;
	while (i < 10 - n)
	{
		g_nbr[0] = '0' + i;
		rev(i++, 1);
>>>>>>> 5a1bcf3de2bb113a5eb48ed378a3f1b87b1c33d7
	}
	print_last(i);
}

void	ft_print_combn(int n)
{
	int	comb[10];

	process(0, n, comb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:20:38 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/11 11:26:19 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	if (nb == 0)
		return (0);
	ft_putnbr(nb / 10);
	write(1, nb % 10 + '0', 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = -1;
	while (par[++i])
	{
		ft_putstr(par[i].str);
		if (par[i].size == 0)
			write(1, "0", 1);
		else
			ft_putnbr(par[i].size);
		ft_putstr(par[i].copy);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:57:09 by seonkim           #+#    #+#             */
/*   Updated: 2021/05/11 16:09:02 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_nbr(int n, int fd)
{
	char	ch_nb;

	if (n == 0)
		return ;
	print_nbr(n / 10, fd);
	if (n > 0)
		ch_nb = n % 10 + 48;
	else if (n < 0)
		ch_nb = -(n % 10) + 48;
	write(fd, &ch_nb, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
		write(fd, "-", 1);
	print_nbr(n, fd);
}

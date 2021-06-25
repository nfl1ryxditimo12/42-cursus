/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:42:52 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/25 16:36:34 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		str_to_nbr(char *str)
{
	long long	num;
	long long	check;

	num = 0;
	check = 1;
	if (*str == '-')
	{
		str++;
		check = -1;
	}
	while (*str && (48 <= *str && *str <= 57))
		num = num * 10 + *(str++) - 48;
	num *= check;
	if (num < -2147483648 || num > 2147483647 || *str != 0)
		print_nbr_err("Invalid Argument", str);
	return (num);
}

void	check_arg(char **arr, int len)
{
	int *arrn;
	int i;
	int j;
	int tmp;

	if (!(arrn = malloc(sizeof(int) * len)))
		print_err(MEM_ERR);
	i = -1;
	while (++i < len)
		arrn[i] = str_to_nbr(arr[i]);
	i = -1;
	while (arrn[++i])
	{
		j = i;
		while (arrn[++j])
			if (arrn[i] == arrn[j])
				print_nbr_err("Duplicate Argument", arrn);
	}
	free(arrn);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:26:53 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/04 15:19:00 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;

	i = 0;
	
	if (argc <= 0)
		return (-1);

	while (argv[0][i])
	{
		write(1, &argv[0][i], 1);
		i++;
	}
	return (0);
}

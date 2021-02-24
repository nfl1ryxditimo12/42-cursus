/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:34:35 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/24 04:15:22 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int i;
	int j;
	int check_numeric;

	i = 0;
	j = 0;
	check_numeric = 0;
	while (str[i] != '\0')
		i++;
	while (j <= i)
	{
		if ('0' <= str[j] && str[j] <= '9')
			check_numeric++;
		j++;
	}
	if (check_numeric == i)
		return (1);
	else if (str[0] == '\0')
		return (1);
	return (0);
}

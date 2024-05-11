/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:12:21 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/18 21:15:35 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	return (c == 32 || (9 <= c && c <= 13));
}

int	is_valid(char *base)
{
	int i;
	int j;

	i = -1;
	if (base[0] == 0 || base[1] == 0)
		return (0);
	while (base[++i])
	{
		if (base[i] == 45 || base[i] == 43 || is_space(base[i]))
			return (0);
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (0);
	}
	return (i);
}

int	nbr_size(int nbr, int base_len)
{
	int ret;

	if (!nbr)
		return(1);
	ret = 0;
	if (nbr < 0)
		ret++;
	while (nbr)
	{
		nbr /= base_len;
		ret++;
	}
	return (ret);
}

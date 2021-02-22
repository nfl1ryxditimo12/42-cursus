/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:13:03 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/22 13:47:20 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int 	ft_str_is_alpha(char *str)
{
	int i;
	int j;
	int check_alphabet;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	while (j <= i)
	{
		if (('a' <= str[j] && str[j] <= 'z') || ('A' <= str[j] && str[j] <= 'Z'))
			check_alphabet++;
	}
	if (check_alphabet == i)
		return (1);
	else if (str[0] == '\0')
		return (1);
	return (0);
}

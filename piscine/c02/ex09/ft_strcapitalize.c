/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongsu <seongsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:08:09 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/24 15:00:05 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	s;

	i = 1;
	if ('a' <= str[0] && str[0] <= 'z')
		str[0] -= 32;
	while (str[i])
	{
		s = str[i - 1];
		if (!(('a' <= s && s <= 'z') || ('A' <= s && s <= 'Z')))
		{
			if ('a' <= str[i] && str[i] <= 'z')
				if (!('0' <= s && s <= '9'))
					str[i] -= 32;
		}
		if ('A' <= str[i] && str[i] <= 'Z')
			if ('0' <= s && s <= '9')
				str[i] += 32;
		if (('A' <= s && s <= 'Z') && ('A' <= str[i] && str[i] <= 'Z'))
			str[i] = str[i] + 32;
		if (('a' <= s && s <= 'z') && ('A' <= str[i] && str[i] <= 'Z'))
			str[i] += 32;
		i++;
	}
	return (str);
}

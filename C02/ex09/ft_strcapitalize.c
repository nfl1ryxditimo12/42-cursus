/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:08:09 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/24 00:11:55 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strcapitalize(char *str)
{
	int		i;
	char	s;

	i = 1;
	if ('a' <= str[0] && str[0] <= 'z')
		str[0] = str[0] - 32;
	while (str[i] != '\0')
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

int main()
{
	char str[200] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(str);
	for (int i = 0; str[i]; i++)
		printf("%c", str[i]);
}

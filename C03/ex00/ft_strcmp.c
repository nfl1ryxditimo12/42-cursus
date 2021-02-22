/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:48:22 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/22 19:21:12 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int i;
	int compare;

	i = 0;
	compare = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			compare = s1[i] - s2[i];
			return (compare);
		}
		i++;
	}
	return (compare);
}

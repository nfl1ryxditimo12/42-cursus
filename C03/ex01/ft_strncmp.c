/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:21:45 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/24 15:27:56 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while ((*s1 && *s2) && i < n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		++s1;
		++s2;
		++i;
	}
	if (i == n)
	{
		--s1;
		--s2;
	}
	return (*s1 - *s2);
}

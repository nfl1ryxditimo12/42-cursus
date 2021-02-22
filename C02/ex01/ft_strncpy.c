/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:01:38 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/22 13:12:42 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
		if (src[i] == '\0')
			j = i;
	}
	i = 0;
	while (j < n)
		dest[j] = '\0';
}

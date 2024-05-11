/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:24:10 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/24 16:38:44 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcat(char *dest, char *src)
{
	char *temp;

	temp = dest;
	while (1)
	{
		if (*dest == '\0')
		{
			if (*src != '\0')
			{
				*dest = *src;
				src++;
			}
			else
			{
				dest++;
				*dest = '\0';
				break ;
			}
		}
		dest++;
	}
	return (temp);
}

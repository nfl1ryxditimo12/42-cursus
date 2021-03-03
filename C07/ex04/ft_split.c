/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:54:43 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/03 14:46:59 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	string_sep(char check_ch, char *charset)
{
	while (*charset)
	{
		if (check_ch == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	string_len(char *str, char *charset

char	**ft_split(char *str, char *charset)
{

}

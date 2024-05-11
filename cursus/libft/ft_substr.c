/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:09:02 by seonkim           #+#    #+#             */
/*   Updated: 2021/05/11 15:47:04 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	ret[len + 1];

	if (!s)
		return (0);
	if (ft_strlen((char *)s) < start)
		return (ft_strdup(""));
	ft_strlcpy(ret, s + start, len + 1);
	return (ft_strdup(ret));
}

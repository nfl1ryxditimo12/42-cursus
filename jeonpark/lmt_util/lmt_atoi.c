/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:43:14 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/08 17:24:59 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lmt_util.h"

//	limits: INT_MAX

static int lmt_is_space(const char ch)
{
	return ((9 <= ch && ch <= 13) || ch == 32);
}

int lmt_is_digit(const char ch)
{
	return ('0' <= ch && ch <= '9');
}

int	lmt_atoi(char *string, int *p_result)
{
	int		sign;
	long	result;

	if (*string == '\0')
		return (PARSE_FAIL);
	while (lmt_is_space(*string))
		++string;
	sign = 1 - (*string == '-') * 2;
	if (sign == -1 || *string == '+')
		++string;
	while (*string == '0')
		++string;
	result = 0;
	while (lmt_is_digit(*string))
	{
		result = result * 10 + (*string - '0');
		if (result > INT_MAX)
			return (PARSE_FAIL);
		++string;
	}
	*p_result = sign * result;
	if (*string == '\0')
		return (PARSE_SUCCESS);
	return (PARSE_FAIL);
}

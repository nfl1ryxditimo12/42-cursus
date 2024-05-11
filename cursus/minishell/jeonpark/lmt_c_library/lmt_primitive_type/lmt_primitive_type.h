/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_primitive_type.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:36:41 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/26 21:41:23 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_PRIMITIVE_TYPE_H
# define LMT_PRIMITIVE_TYPE_H

int		lmt_is_space(const char ch);
int		lmt_is_digit(const char ch);

int		lmt_atoi(char *string, int *p_result);
char	*lmt_itoa(int number);

int		lmt_str_equals(const char *lhs, const char *rhs);

#endif

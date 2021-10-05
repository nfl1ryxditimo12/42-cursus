/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_primitive.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:36:41 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/06 15:43:48 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_PRIMITIVE_TYPE
# define LMT_PRIMITIVE_TYPE

int		lmt_is_space(const char ch);
int		lmt_is_digit(const char ch);

int		lmt_atoi(char *string, int *p_result);
int		lmt_atol(char *string, long *p_result);
int		lmt_atoui(char *string, unsigned int *p_result);
char	*lmt_itoa(int number);
char	*lmt_ltoa(long number);

#endif

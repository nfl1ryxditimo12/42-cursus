/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:58:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/17 22:21:50 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_UTIL_H
# define LMT_UTIL_H

# include <stddef.h>
# include "lmt_constant.h"
# include "lmt_check_type.h"

void	*lmt_alloc(size_t size);
int	lmt_return_error(int exit_status, char *string);
void	lmt_exit(int exit_code, char *string);
int	lmt_atoi(char *string, int *p_result);
size_t	lmt_unsafe_strlen(const char *p_string);
int	lmt_unsafe_memcmp(char *lhs, char *rhs, size_t size);
int	lmt_unsafe_strcmp(char *lhs, char *rhs);
int	lmt_get_exit_code_from_stat_loc(int stat_loc);

#endif

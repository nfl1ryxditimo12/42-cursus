/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_alloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 13:55:06 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/21 13:53:28 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_ALLOC_H
# define LMT_ALLOC_H

# include <stddef.h>

//	malloc(), exit()

void	*lmt_alloc(size_t size);

#endif

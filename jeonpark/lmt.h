/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:50 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/08 20:27:25 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_H
# define LMT_H

typedef void	(*t_sigaction_handler)(int);

// Init signal

void	lmt_signal_init(void);

#endif

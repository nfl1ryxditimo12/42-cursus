/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:53:32 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/06 17:50:34 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

# define STATUS_INIT		1
# define STATUS_READING		2
# define STATUS_PARSING		3
# define STATUS_CHILD		4

void	signal_set_status(int status);

#endif

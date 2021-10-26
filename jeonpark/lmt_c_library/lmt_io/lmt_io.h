/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:58:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/13 15:27:20 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_IO_H
# define LMT_IO_H

# include <stddef.h>
# include <sys/types.h>

void	lmt_close(int fd);
ssize_t	lmt_read(int fd, void *buffer, size_t size);
void	lmt_put_ch(const char ch);
ssize_t	lmt_write(const char *string);

#endif

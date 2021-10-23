/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_unsafe.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:22:05 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/19 20:19:39 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_UNSAFE_H
# define LMT_UNSAFE_H

# include <stddef.h>

size_t	lmt_unsafe_strlen(const char *string);
int		lmt_unsafe_string_starts(char *string, char *word);
void	*lmt_unsafe_memcpy(void *p_write, const void *p_read, size_t size);
void	*lmt_unsafe_strcpy(char *p_write, const char *p_read);
void	*lmt_unsafe_strdup(const char *string);
char	*lmt_unsafe_strchr(char *string, char *word);
char	*lmt_unsafe_strrchr(char *string, char *word);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:13:05 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/01 14:22:50 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int					ft_isdigit(int c);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);

char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *s);

void				ft_putchar_fd(char c, int fd);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:53:34 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/02 11:46:48 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_format
{
	int			minus;
	int			zero;
	int			width;
	int			pre;
	int			chk_pre;
	int			l_size;
	int			h_size;
	char		**ptr;
}				t_format;

int				ft_printf(const char *input, ...);
int				ft_format_init(char **input, va_list ap);
int				ft_format_process(va_list ap, t_format *fmt);

int				ft_format_flag(va_list ap, t_format *fmt);
int				ft_format_width(va_list ap, t_format *fmt);
int				ft_format_precision(va_list ap, t_format *fmt);
int				ft_format_type(va_list ap, t_format *fmt);

int				ft_print_integer(va_list ap, t_format *fmt);
int				ft_print_unsigned_integer(va_list ap, t_format *fmt);
int				ft_print_char(va_list ap, t_format *fmt);
int				ft_print_string(va_list ap, t_format *fmt);
int				ft_print_pointer(va_list ap, t_format *fmt);
int				ft_print_percent(t_format *fmt);

size_t			ft_nbr_size(unsigned long long n, int b_len);
char			*ft_convert_base(unsigned long long n, \
		char *base, int b_len, t_format *fmt);
void			ft_frees(int cnt, ...);
#endif

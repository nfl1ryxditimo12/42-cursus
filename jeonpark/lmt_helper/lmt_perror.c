/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_perror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:00:00 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/26 16:44:08 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// write()
#include <stdio.h>	// strerror(), printf()
#include <errno.h>	// errno
#include <stdlib.h>	// exit()
#include "lmt_c_library.h"
#include "lmt_helper.h"

void	lmt_perror(const char *str)
{
	t_lmt_string	*string;

	string = lmt_string_new("minishell: ");
	lmt_string_append_string(string, str);
	lmt_string_append_string(string, ": ");
	lmt_string_append_string(string, strerror(errno));
	lmt_string_append_string(string, "\n");
	if (write(2, string->value, string->count) == -1)
		exit(1);
	lmt_string_free(string);
}

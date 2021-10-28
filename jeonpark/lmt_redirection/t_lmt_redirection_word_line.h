/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_word_line.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:39:40 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 10:28:13 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_REDIRECTION_WORD_LINE_H
# define T_LMT_REDIRECTION_WORD_LINE_H

typedef struct s_lmt_redirection_word_line
{
	char								*value;
	struct s_lmt_redirection_word_line	*prev;
	struct s_lmt_redirection_word_line	*next;
}	t_lmt_redirection_word_line;

// type
t_lmt_redirection_word_line	*lmt_redirection_word_line_new(char *value);
t_lmt_redirection_word_line	*lmt_redirection_word_line_new_dummy(void);
void						lmt_redirection_word_line_free(
								t_lmt_redirection_word_line *dummy);

// method
t_lmt_redirection_word_line	*lmt_redirection_word_line_new_from_stdin(
								int std_in, int std_out, const char *delimiter);
void						lmt_redirection_word_line_attach(
								t_lmt_redirection_word_line *dummy);

#endif

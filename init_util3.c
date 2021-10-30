/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:19:59 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/30 20:22:11 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	chk_quotes_cnt(t_token *ptr)
{
	int		i;
	int		j;
	int		err;
	char	quote;

	i = 0;
	err = 0;
	while (ptr->token[++i])
	{
		quote = 0;
		j = 0;
		if (ptr->token[i][0] == '\'' || ptr->token[i][0] == '\"')
			quote = ptr->token[i][0];
		while (ptr->token[i][j])
			j++;
		if ((quote != 0 && ptr->token[i][j - 1] != quote) ||
			(quote != 0 && j == 1))
			err = 1;
	}
	if (err == 1)
		return (0);
	return (1);
}

int	chk_redirect_cnt(t_token *ptr)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = -1;
	while (ptr->token[0][++i])
		if (ptr->token[0][i] == '>' || ptr->token[0][i] == '<')
			cnt++;
	if (cnt > 2 || (cnt && ptr->next == NULL))
		return (0);
	return (1);
}

int	chk_token_valid(t_handler *hand)
{
	int		l_parentheses;
	int		r_parentheses;
	char	token;

	l_parentheses = 0;
	r_parentheses = 0;
	while (hand->line)
	{
		token = hand->line->token[0][0];
		if (token == '(')
			l_parentheses++;
		else if (token == ')')
			r_parentheses++;
		else if ((token == '|' || token == '&') && !chk_operator(hand->line))
			return (0);
		else if (!chk_redirect_cnt(hand->line) || !chk_quotes_cnt(hand->line))
			return (0);
		hand->line = hand->line->next;
	}
	if (l_parentheses != r_parentheses)
		return (0);
	hand->line = hand->top;
	return (1);
}

int	is_space(char *line)
{
	while (*line)
	{
		if (*line != 32 && *line != 9)
			return (0);
		line++;
	}
	return (1);
}

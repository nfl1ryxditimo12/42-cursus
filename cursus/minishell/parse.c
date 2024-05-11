/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:41:25 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/30 20:32:09 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_token_cnt2(char *line, int *flag, int *cnt)
{
	*flag = 0;
	(*cnt)++;
	return (token_len(line, 0));
}

int	get_token_cnt(char *line)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 0;
	while (*line)
	{
		while (*line && (*line == 32 || *line == 9 || *line == 45))
			line++;
		if (chk_symbol(line) || chk_redirect(line) || count_fd(line))
			line += get_token_cnt2(line, &flag, &cnt);
		else if (*line && !(*line == 32 || *line == 9) && !chk_symbol(line) && \
					!chk_redirect(line) && !count_fd(line))
		{
			if (!flag)
				cnt++;
			if (*line == '\'' || *line == '\"')
				flag = *line;
			line += token_len(line, flag);
			flag = 1;
		}
	}
	return (cnt);
}

void	process_split(t_token *ptr, char *line, char **env)
{
	int	flag;

	flag = 0;
	while (*line)
	{
		while (*line && (*line == 32 || *line == 9))
			line++;
		if (chk_symbol(line) || chk_redirect(line) || count_fd(line))
		{
			if (flag == 1 || flag == 2)
				ptr = ptr->next;
			line += line_cpy(ptr, line, env);
			flag = 2;
		}
		if (*line && !(*line == 32 || *line == 9) && !chk_symbol(line) && \
			!chk_redirect(line) && !count_fd(line))
		{
			if (flag == 2)
				ptr = ptr->next;
			line += line_cpy(ptr, line, env);
			flag = 1;
		}
		if (ptr->size == 100)
			return ;
	}
}

void	print_parse(t_handler *hand)
{
	int	i;

	hand->line = hand->top;
	while (hand->line)
	{
		i = 0;
		while (hand->line->token[i])
			printf("\x1b[35m|\x1b[0m %s \x1b[35m|\x1b[0m", hand->line->token[i++]);
		printf("\n");
		hand->line = hand->line->next;
	}
	hand->line = hand->top;
}

void	line_split(t_handler *hand, char *line)
{
	int	size;
	int	i;

	size = get_token_cnt(line);
	hand->top = hand->line;
	i = -1;
	while (++i < size)
		node_push(hand);
	hand->line = hand->top;
	process_split(hand->line, line, hand->env);
	print_parse(hand);
}

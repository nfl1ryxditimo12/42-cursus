/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:23:08 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/28 18:08:35 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "t_lmt_process_manager.h"

int		path_len(char *str)
{
	int cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == ':' && *(str + 1) != 0)
			cnt++;
		str++;
	}
	return (cnt + 1);
}

int	cmd_path_len(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] && str[cnt] != ':')
		cnt++;
	return (cnt);
}

char *ft_strldup(char *str, int size)
{
    char *ret;
    int i;

    i = -1;
    if (!str || !*str)
        return (0);
    ret = lmt_alloc(size + 1);
    while (++i < size)
        ret[i] = str[i];
    ret[i] = 0;
    return (ret);
}

char	**ft_split(char *str)
{
	char	**ret;
	char	*ptr;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	ptr = str;
	ret = (char **)lmt_alloc(sizeof(char *) * (path_len(str) + 1));
	i = 0;
	while (*str)
	{
		j = 0;
		if (*str == ':')
			str++;
		else
		{
			ret[i++] = ft_strldup(str, cmd_path_len(str));
			str += cmd_path_len(str);
		}
	}
	ret[i] = 0;
	free(ptr);
	return (ret);
}

char	*getpath(t_handler *hand)
{
	char	*key;
	int		i;

	i = -1;
	while (hand->env[++i])
	{
		key = get_env_key(hand->env[i]);
		if (ft_strcmp2(key, "PATH"))
		{
			free(key);
			break ;
		}
		free(key);
	}
	if (hand->env[i] == NULL)
		return (NULL);
	return (get_env_value(hand->env[i]));
}

void    hand_init(t_handler *hand)
{
	hand->path = lmt_alloc(sizeof(t_path));
	hand->line = 0;
	hand->clear = 0;
	getcwd(hand->path->dir, 1024);
	hand->exit = 0;
	hand->pid = 0;
	hand->cmd_flag = 0;
	hand->token_size = 0;
	hand->path->home_dir = getenv("HOME");
	hand->path->cmd = ft_split(getpath(hand));
}

void    shell_init(t_handler *hand)
{
	pid_t   pid;
	int     status;
	char    *clear[2];

	clear[0] = "clear";
	clear[1] = 0;
	pid = fork();
	if (pid == 0)
		execve("/usr/bin/clear", clear, hand->env);
	else
		waitpid(pid, &status, 0);
}

char    *prompt(t_handler *hand)
{
	if (hand->status == 127)
		return ("😎 \033[0;32m\033[1mminishell \033[0;31m\033[1m▸ \033[0m");
	return ("😎 \033[0;32m\033[1mminishell ▸ \033[0m");
}

void    process_line(t_handler *hand)
{
	int check;

	hand->cmd_flag = 0;
	while (hand->line)
	{
		check = check_type(hand);
		if (check == 1)
			process_builtin_cmd(hand);
		else if (check == 2)
			process_non_builtin_cmd(hand);
		else if (check == 0)
		{
			perror(hand->line->token[0]);
			break ;
		}
		hand->line = hand->line->next;
	}
}

// 따옴표, 괄호 닫히는지, 꺽쇠가 2개 이하인지, 연산자 뒤 명령어가 있는지

int     chk_operator(t_token *ptr)
{
	int cnt;
	int i;

	cnt = 0;
	i = -1;
	while (ptr->token[0][++i])
		if (ptr->token[0][i] == '|' || ptr->token[0][i] == '&')
			cnt++;
	if (cnt > 2 ||
		(cnt &&
		(ptr->next->token[0][0] == '|' ||
		ptr->next->token[0][0] == '&' || ptr->next == NULL)))
		return (0);
	return (1);
}

int     chk_quotes_cnt(t_token *ptr)
{
	int i;
	int j;
	int err;
	char quote;

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

int     chk_redirect_cnt(t_token *ptr)
{
	int cnt;
	int i;

	cnt = 0;
	i = -1;
	while (ptr->token[0][++i])
		if (ptr->token[0][i] == '>' || ptr->token[0][i] == '<')
			cnt++;
	if (cnt > 2 || (cnt && ptr->next == NULL))
		return (0);
	return (1);
}

int     chk_token_valid(t_handler *hand)
{
	int l_parentheses;
	int r_parentheses;
	char token;

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

int     is_space(char *line)
{
	while (*line)
	{
		if (*line != 32 && *line != 9)
			return (0);
		line++;
	}
	return (1);
}

void    process_init(t_handler *hand)
{
	char    *line;

	while (hand->exit == 0)
	{
		signal_set_status(STATUS_READING);
		line = readline(prompt(hand));
		if (!line)
		{
			hand->status = 1;
			printf("exit\n");
			hand->exit = 1;
		}
		else if (!*line || is_space(line))
			hand->status = 0;
		else
		{
			hand_init(hand);
			add_history(line);
			printf("\n\x1b[33m========\x1b[0m Parse \x1b[33m====================================\x1b[0m\n\n");
			signal_set_status(STATUS_PARSING);
			line_split(hand, line);
			printf("\n\x1b[33m===================================================\x1b[0m\n\n");
			hand->line = hand->top;
			if (chk_token_valid(hand))
				lmt_process_manager_execute(hand);
			else
				printf("Token Error!!\n");
			printf("\n\x1b[31m===================================================\x1b[0m\n\n");
			hand_reset(hand);
		}
		free(line);
	}
}

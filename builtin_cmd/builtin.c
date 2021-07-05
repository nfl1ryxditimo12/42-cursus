/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:29:39 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/05 16:27:29 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int  cmd_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strjoin(char *s1, char *s2, int size, int option)
{
    char    *ret;
    int     i;

    i = 0;
    ret = malloc(cmd_len(s1) + cmd_len(s2) + 2);
    while (s1 && *s1)
        ret[i++] = *s1++;
    while (s2 && *s2)
        ret[i++] = *s2++;
    if (size)
        ret[i] = ' ';
    else if (!size && !option)
        ret[i] = '\n';
    else if (!size && option)
        ret[i] = 0;
    ret[i + 1] = 0;
    return (ret);
}

void    process_echo(t_handler *hand)
{
    int     option;
    int     i;
    char    *echo;
	char	*tmp;

    option = 0;
    if (hand->line->token[1][0] == '-' && hand->line->token[1][1] == 'n')
        option = 1;
    i = 1 + option;
    while (i < hand->line->size)
    {
		tmp = ft_strjoin(echo, hand->line->token[i], hand->line->size - (i + 1), option);
		if (echo)
			free(echo);
		echo = tmp;
		i++;
    }
    printf("%s", echo);
    free(echo);
}

char    *pre_dir(t_handler *hand)
{
    int end;
    int start;
    char    *ret_dir;

    start = 0;
    while (hand->dir[start])
        start++;
    start--;
    if (hand->dir[start] == '/')
        start--;
    while (hand->dir[start] != '/')
        start--;
    end = start;
    start = -1;
    ret_dir = malloc(end);
    ret_dir[end] = 0;
    while (++start < end)
        ret_dir[start] = hand->dir[start];
    return (ret_dir);
}

char    *home_dir(char **env)
{
    int i;
    int j;
    char    *home;

    i = -1;
    while (env[++i])
        if (ft_strcmp(env[i], "HOME="))
            break ;
    home = malloc(cmd_len(env[i] - 4));
    j = 0;
    while (env[i][j + 5])
    {
        home[j] = env[i][j + 5];
        j++;
    }
    home[j] = 0;
    return (home);
}

char    *dir_cpy(char *str)
{
    char    *ret_dir;
    int     i;

    ret_dir = malloc(cmd_len(str) + 1);
    i = -1;
    while (++i < cmd_len)
        ret_dir[i] = str[i];
    ret_dir[i] = 0;
    return (ret_dir);
}

void    process_cd(t_handler *hand)
{
    char    *dir;

    if (hand->line->token[2])
        perror(hand->line->token[0]);
    if (ft_strcmp(hand->line->token[1], ".."))
        dir = pre_dir(hand);
    else if (!hand->line->token[1][0])
        dir = hand->home_dir;
    else
        hand->dir = getcwd(dir, 100000);
}

void    process_builtin_cmd(t_handler *hand)
{
    if (ft_strcmp(hand->line->token[0], "echo"))
        process_echo(hand);
    else if (ft_strcmp(hand->line->token[0], "cd"))
        process_cd(hand);
    else if (ft_strcmp(hand->line->token[0], "pwd"))
        process_pwd(hand);
    else if (ft_strcmp(hand->line->token[0], "export"))
        process_export(hand);
    else if (ft_strcmp(hand->line->token[0], "unset"))
        process_unset(hand);
    else if (ft_strcmp(hand->line->token[0], "env"))
        process_env(hand);
    else if (ft_strcmp(hand->line->token[0], "exit"))
        process_env(hand);
}
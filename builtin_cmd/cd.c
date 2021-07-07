/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:02:11 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/07 17:39:37 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
    while (++start < end)
        ret_dir[start] = hand->dir[start];
    ret_dir[start] = 0;
    return (ret_dir);
}

char    *dir_cpy(char *str)
{
    char    *ret_dir;
    int     i;

    ret_dir = malloc(cmd_len(str) + 1);
    i = -1;
    while (++i < cmd_len(str))
        ret_dir[i] = str[i];
    ret_dir[i] = 0;
    return (ret_dir);
}

char    *process_comma(t_handler *hand)
{
    int comma;

    comma = -1;
    while (hand->line->token[1][++comma])
        if (hand->line->token[1][comma] != '.')
            return (0);
    if (hand->dir[0] == '/' && hand->dir[1] == 0)
        return (ft_strdup("/"));
    if (comma == 1)
        return (ft_strdup("."));
    else if (comma == 2)
        return (pre_dir(hand));
    else
        return (ft_strdup(""));
}

void    process_cd(t_handler *hand)
{
    char    *dir;
    int     comma;

    getcwd(hand->dir, 1024);
    if (hand->line->token[2])
        perror(hand->line->token[2]);
    if (ft_strcmp(hand->line->token[1], "~/"))
        dir = connect_dir(hand->home_dir, hand->line->token[1]);
    else if (!hand->line->token[1][0] || ft_strcmp2(hand->line->token[1], "~"))
        dir = ft_strdup(hand->home_dir);
    else if (hand->line->token[1][0] == '.')
        dir = process_comma(hand);
    else if (hand->line->token[1][0] == '/')
        dir = ft_strdup(hand->line->token[1]);
    else
        dir = connect_dir(hand->home_dir, hand->line->token[1]);
    if (chdir(dir))
        perror(dir);
    else
        getcwd(hand->dir, 1024);
    free(dir);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:02:11 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/05 13:40:34 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char    *process_slash(t_handler *hand)
{
    int i;
    int comma;
    char *ret;

    i = -1;
    comma = 0;
    ret = ft_strdup(hand->path->dir);
    while (hand->line->token[1][++i])
    {
        if (hand->line->token[1][i] == '.')
            comma++;
        if (comma > 2)
        {
            free(ret);
            return (ft_strdup(""));
        }
        if (hand->line->token[1][i + 1] == '/' || !hand->line->token[1][i + 1])
        {
            if (comma == 2)
                ret = pree_dir(ret);
            comma = 0;
        }
    }
    return (ret);
}

char    *process_comma(t_handler *hand)
{
    int comma;
    int slash;

    comma = -1;
    slash = 0;
    while (hand->line->token[1][++comma])
    {
        if (hand->line->token[1][comma] != '.' &&
            hand->line->token[1][comma] != '/')
            return (0);
        if (hand->line->token[1][comma] == '/')
            slash++;
    }
    if (hand->path->dir[0] == '/' && hand->path->dir[1] == 0)
        return (ft_strdup("/"));
    if (comma == 1 && !slash)
        return (ft_strdup("."));
    else if (comma == 2 && !slash)
        return (pre_dir(hand->path->dir));
    else if (slash)
        return (process_slash(hand));
    else
        return (ft_strdup(""));
}

void    process_cd(t_handler *hand)
{
    char    *dir;
    int     comma;

    if (hand->line->token[2])
        perror(hand->line->token[2]);
    if (!hand->line->token[1] || ft_strcmp2(hand->line->token[1], "~"))
        dir = ft_strdup(hand->path->home_dir);
    else if (ft_strcmp(hand->line->token[1], "~/"))
        dir = connect_dir(hand->path->home_dir, hand->line->token[1]);
    else if (hand->line->token[1][0] == '.')
        dir = process_comma(hand);
    else if (hand->line->token[1][0] == '/')
        dir = ft_strdup(hand->line->token[1]);
    else
        dir = connect_dir(hand->path->dir, hand->line->token[1]);
    if (chdir(dir))
        perror(dir);
    else
        getcwd(hand->path->dir, 1024);
    free(dir);
}
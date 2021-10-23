/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:04:21 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/23 20:10:15 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int  cmd_len(char *str)
{
    int i;

    i = 0;
    if (!str || !*str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *str)
{
    int i;
    char    *ret;

    i = 0;
    ret = lmt_alloc(cmd_len(str) + 1);
    while (*str)
        ret[i++] = *str++;
    ret[i] = 0;
    return (ret);
}

char    *pre_dir(char *dir)
{
    int end;
    int start;
    char    *ret_dir;

    start = 0;
    while (dir[start])
        start++;
    while (dir[start] != '/')
        start--;
    if (!start)
        return (ft_strdup("/"));
    end = start;
    start = -1;
    ret_dir = lmt_alloc(end);
    while (++start < end)
        ret_dir[start] = dir[start];
    ret_dir[start] = 0;
    return (ret_dir);
}

char    *pree_dir(char *dir)
{
    int end;
    int start;
    char    *ret_dir;

    start = 0;
    while (dir[start])
        start++;
    while (dir[start] != '/')
        start--;
    if (!start)
    {
        free(dir);
        return (ft_strdup("/"));
    }
    end = start;
    start = -1;
    ret_dir = lmt_alloc(end);
    while (++start < end)
         ret_dir[start] = dir[start];
    ret_dir[start] = 0;
    free(dir);
    return (ret_dir);
}

char    *dir_cpy(char *str)
{
    char    *ret_dir;
    int     i;

    ret_dir = lmt_alloc(cmd_len(str) + 1);
    i = -1;
    while (++i < cmd_len(str))
        ret_dir[i] = str[i];
    ret_dir[i] = 0;
    return (ret_dir);
}

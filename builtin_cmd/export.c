/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:36:19 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/24 17:21:13 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char    *get_env_value(char *env)
{
    int     i;
    int     j;
    int     size;
    char    *ret;

    i = 0;
    size = cmd_len(env);
    while (env[i] && env[i] != '=')
        i++;
    i++;
    if (size == i)
        return (ft_strdup(""));
    ret = lmt_alloc(size - i + 1);
    j = 0;
    while (i < size)
        ret[j++] = env[i++];
    ret[j] = 0;
    return (ret);
}

char    *get_env_key(char *env)
{
    int i;
    int size;
    char    *ret;

    size = 0;
    while (env[size] && env[size] != '=')
        size++;
    if (!env[size])
        return (ft_strdup(""));
    ret = lmt_alloc(size + 1);
    i = -1;
    while (++i < size)
        ret[i] = env[i];
    ret[i] = 0;
    return (ret);
}

void    declare_env(t_handler *hand)
{
    int i;
    char    *key;
    char    *value;

    i = -1;
    while (hand->env[++i])
    {
        key = get_env_key(hand->env[i]);
        value = get_env_value(hand->env[i]);
        printf("declare -x %s=\"%s\"\n", key, value);
        free(key);
        free(value);
    }
}

void    dup_env(t_handler *hand)
{
    int     i;
    int     flag;
    char    *key;
    char    *arg;
    char    **ptr;
    
    ptr = hand->line->token + 1;
    while (*ptr)
    {
        key = get_env_key(*ptr);
        i = -1;
        flag = 0;
        while (hand->env[++i])
        {
            arg = get_env_key(hand->env[i]);
            if (ft_strcmp2(arg, key))
                flag = 1;
            free(arg);
            if (flag)
                break ;
        }
        if (flag)
            free(hand->env[i]);
        hand->env[i] = ft_strdup(*ptr);
        free(key);
        ptr++;
    }
}

int     is_valid_items(char *key, char *value)
{
    if (!(97 <= *key && *key <= 122) && !(65 <= *key && *key <= 90))
        return (0);
    while (*key)
    {
        if (!(97 <= *key && *key <= 122) && !(65 <= *key && *key <= 90) && !(48 <= *key && *key <= 57) && *key != '_')
            return (0);
        key++;
    }
    while (*value)
        if (*value++ == '!')
            return (0);
    return (1);
}

int     is_right_environ(t_token *element)
{
    char **ptr;
    char *key;
    char *value;
    int status;

    ptr = element->token + 1;
    status = 1;
    while (*ptr && status == 1)
    {
        key = get_env_key(*ptr);
        value = get_env_value(*ptr);
        if (cmd_len(key) == 0 || !is_valid_items(key, value))
            status = 0;
        free(key);
        free(value);
        ptr++;
    }
    return (status);
}

void    process_export(t_handler *hand)
{
    if (!is_right_environ(hand->line))
    {
        hand->status = 1;
        printf("Export Error!!\n");
    }
    else
    {
        hand->status = 0;
        if (!hand->line->token[1])
            declare_env(hand);
        else
            dup_env(hand);
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:01:59 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/05 16:27:29 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

# define BUFFER_SIZE 10000
# define MEM_ERR "Memory Allocation Error"

typedef struct  s_token
{
    char            *token[100];
    char            *cmd_dir;
    int             type;
    int             index;
    int             size;
    struct s_token  *pre;
    struct s_token  *next;
}               t_token;

typedef struct  s_handler
{
    t_token *line;
    t_token *top;
    char    *cmd[5];
    char    **env;
    char    *clear;
    char    *dir;
    char    *home_dir;
    int     exit;
    int     status;
    int     pid;
    int     cmd_flag;
}               t_handler;

void	node_push(t_handler *hand, int index);

int     chk_symbol(char *line);

int     ft_strlen(char  *str);
int     ft_strcmp(char *s1, char *s2);

void    line_split(t_handler *hand, char *line);
void    line_cpy(t_token *ptr, char *line);

void    print_err(char *err, char *arr);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:01:59 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/06 19:30:07 by seonkim          ###   ########seoul.kr  */
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
    struct stat *buf;
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
int     chk_redirect(char *line);
int     count_fd(char *line);

int     ft_strlen(char  *str);
int     ft_strcmp(char *s1, char *s2);
int     ft_strcmp2(char *s1, char *s2);

void    line_split(t_handler *hand, char *line);
int    line_cpy(t_token *ptr, char *line);

char    *connect_dir(char *path, char *token);
int     cmd_len(char *str);

char    **dup_env(t_handler *hand, char **env, int flag);

void    print_err(char *err, char *arr);

#endif
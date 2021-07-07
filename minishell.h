/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:01:59 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/07 19:08:57 by seonkim          ###   ########seoul.kr  */
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
# include <sys/stat.h>

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
    char    dir[1024];
    char    *home_dir;
    int     exit;
    int     status;
    int     pid;
    int     cmd_flag;
}               t_handler;

// node
void	node_push(t_handler *hand, int index);

// parse
int     chk_symbol(char *line);
int     chk_redirect(char *line);
int     count_fd(char *line);
void    line_split(t_handler *hand, char *line);

// parse util
int     ft_strlen(char  *str);
int     ft_strcmp(char *s1, char *s2);
int     ft_strcmp2(char *s1, char *s2);
int     line_cpy(t_token *ptr, char *line);
int     token_len(char  *str);

// cd

// check
int    check_type(t_handler *hand);

// process
void    process_builtin_cmd(t_handler *hand);
void    process_non_builtin_cmd(t_handler *hand);
void    process_symbol(t_handler *hand);

// builtin_cmd
void    process_echo(t_handler *hand);
void    process_cd(t_handler *hand);
void    process_export(t_handler *hand);
void    process_unset(t_handler *hand);
void    process_exit(t_handler *hand);
void    process_env(t_handler *hand);

// builtin_util
int     cmd_len(char *str);
char    *ft_strdup(char *str);
char    *connect_dir(char *path, char *token);

// env
int     env_len(char **env);
void    free_env(char **env);
char    **env_control(char **env);

// print
void    print_err(char *err, char *arr);

#endif
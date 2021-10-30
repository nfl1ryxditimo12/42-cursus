/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:01:59 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/30 19:15:08 by jeonpark         ###   ########.fr       */
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
# include "lmt_c_library.h"
# include "lmt_helper.h"
# include "signal.h"

# define BUFFER_SIZE 10000
# define MEM_ERR "Memory Allocation Error"

# define STATUS_INIT		1
# define STATUS_READING		2
# define STATUS_PARSING		3
# define STATUS_CHILD		4

typedef struct s_token
{
	char			*token[101];
	int				space[100];
	char			*cmd_dir;
	int				type;
	int				size;
	struct s_token	*pre;
	struct s_token	*next;
}	t_token;

typedef struct s_path
{
	struct stat	buf;
	char		**cmd;
	char		dir[1024];
	char		*home_dir;
}	t_path;

typedef struct s_handler
{
	t_token	*line;
	t_token	*top;
	t_path	*path;
	char	**env;
	char	*clear;
	int		token_size;
	int		exit;
	int		status;
	int		pid;
	int		cmd_flag;
}	t_handler;

// init
void	process_init(t_handler *hand);
void	shell_init(t_handler *hand);
int		path_len(char *str);

// node
void	node_push(t_handler *hand);

// parse
int		chk_symbol(char *line);
int		chk_redirect(char *line);
int		count_fd(char *line);
void	line_split(t_handler *hand, char *line);
int		get_token_cnt(char *line);

// 삭제 필요
void	print_parse(t_handler *hand);

// parse util
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strcmp2(char *s1, char *s2);
int		line_cpy(t_token *ptr, char *line, char **env);
int		token_len(char *str, char quotes);

// cd

// check
int		check_type(t_handler *hand);
int		builtin_cmd(t_handler *hand);
int		not_builtin_cmd(t_handler *hand);

// process
void	process_builtin_cmd(t_handler *hand);
void	process_non_builtin_cmd(t_handler *hand);
void	process_symbol(t_handler *hand);

// builtin_cmd
void	process_echo(t_handler *hand);
void	process_cd(t_handler *hand);
void	process_pwd(t_handler *hand);
void	process_export(t_handler *hand);
void	process_unset(t_handler *hand);
void	process_exit(t_handler *hand);
void	process_env(t_handler *hand);

// builtin_util
int		cmd_len(char *str);
char	*ft_strdup(char *str);
char	*connect_dir(char *path, char *token);
char	*dir_cpy(char *str);
int		is_right_environ(t_token *element);
char	*get_env_key(char *env);
char	*get_env_value(char *env);

// env
int		env_len(char **env);
void	free_env(char **env);
char	**env_control(char **env);

// print
void	print_err(char *err, char *arr);

// reset
void	hand_reset(t_handler *hand);

#endif

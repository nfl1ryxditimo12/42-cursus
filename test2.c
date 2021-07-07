#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int     ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
        if (*s1++ != *s2++)
            return (0);
    return (1);
}

int     ft_strcmp2(char *s1, char *s2)
{
    while (*s1 || *s2)
        if (*s1++ != *s2++)
            return (0);
    return (1);
}

void	process_ls(char **env)
{
	char *cmd[2] = {"ls", 0};
	int pid;

	pid = fork();
	if (pid == 0)
		execve("/bin/ls", cmd, env);
}

char	*ft_strcpy(char *str)
{
	char *ret;
	int i;

	i = 0;
	while (str[i])
		i++;
	ret = malloc(i + 1);
	i = 0;
	str += 3;
	while (*str)
		ret[i++] = *str++;
	ret[i] = 0;
	return (ret);
}

static int  cmd_len(char *str)
{
    int i;

    i = 0;
	if (!str || !*str)
		return (0);
    while (str[i])
        i++;
    return (i);
}

char    *connect_dir(char *path, char *token)
{
    char    *connect;
    int     i;
    
    if (*token == '~')
        token++;
    connect = malloc(cmd_len(path) + cmd_len(token) + 3);
    i = 0;
    while (path && *path)
        connect[i++] = *path++;
	connect[i++] = '/';
    while (token && *token)
        connect[i++] = *token++;
    connect[i] = '/';
	connect[i + 1] = 0;
    return (connect);
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
    home = malloc(cmd_len(env[i]) - 3);
    j = 0;
    while (env[i][j + 5])
    {
        home[j] = env[i][j + 5];
        j++;
    }
    home[j] = '/';
	home[j + 1] = 0;
    return (home);
}

char    *pre_dir(char *dir)
{
    int end;
    int start;
    char    *ret_dir;

    start = 0;
    while (dir[start])
        start++;
    start--;
    if (dir[start] == '/')
        start--;
    while (dir[start] != '/')
        start--;
    end = start;
    start = -1;
    ret_dir = malloc(end);
    while (++start < end)
        ret_dir[start] = dir[start];
	ret_dir[end] = 0;
    return (ret_dir);
}

char	*ft_strdup(char *str)
{
	char *ret;
	int i;

	i = 0;
	ret = malloc(cmd_len(str) + 1);
	while (*str)
		ret[i++] = *str++;
	ret[i] = 0;
	return (ret);
}

char    *process_comma(char *line, char *dir)
{
    int comma;
	char	*ret;

    comma = -1;
    while (line[++comma])
        if (line[comma] != '.')
            return (0);
	if (dir[0] == '/' && dir[1] == 0)
		return (dir);
    if (comma == 1)
        ret = ft_strdup(".");
    else if (comma == 2)
        ret = (pre_dir(dir));
	else
		return (0);
    if (opendir(ret))
		return (ret);
	else
		return (ft_strdup("/"));
}

void	process_cd(char *line, char **env)
{
    char    *dir;
	char	name[1024];
    int     comma;

	getcwd(name, 1024);
	printf("Before DIR : %s\n", name);
	line += 3;
    if (ft_strcmp(line, "~/"))
        dir = connect_dir(home_dir(env), line);
    else if (!*line || ft_strcmp2(line, "~"))
        dir = home_dir(env);
    else if (*line == '.')
        dir = process_comma(line, name);
	else if (*line == '/')
		dir = ft_strdup(line);
	else
		dir = connect_dir(name, line);
    if (chdir(dir))
        perror(dir);
    else
        getcwd(name, 1024);
	free(dir);
	printf("After DIR : %s\n", name);
}

int		main(int ac, char **av, char **env)
{
	char	*line;
	char	*dir;

	(void)ac;
	(void)av;
	while (1)
	{
		line = readline("prompt > ");
		if (line[0] == 'c')
			if (line[1] == 'd')
				process_cd(line, env);
		if (line[0] == 'l')
			if (line [1] == 's')
				process_ls(env);
	}
}

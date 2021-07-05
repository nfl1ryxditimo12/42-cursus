#include <stdio.h>
#include <unistd.h>
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
    while (str[i])
        i++;
    return (i);
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
    ret_dir[end] = 0;
    while (++start < end)
        ret_dir[start] = dir[start];
    return (ret_dir);
}

void	process_cd(char *line, char **env)
{
	char *dir;
	char	name[1024];
	char *cmd;

	dir = getcwd(name, 1024);
	cmd = ft_strcpy(line);
	if (line[3] == ' ')
		line += 3;
	if (!line[3])
	{
		chdir(home_dir(env));
		dir = getcwd(name, 1024);
	}
	else if (ft_strcmp(line, ".."))
	{
		chdir(pre_dir(dir));
		dir = getcwd(name, 1024);
	}
	else
		chdir(cmd);
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

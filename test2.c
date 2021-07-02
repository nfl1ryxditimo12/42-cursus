#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int     ft_strcmp(char *s1, char *s2)
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

void	process_cd(char *line)
{
	char *dir;
	char *cmd;

	dir = getcwd(dir, 10000);
	cmd = ft_strcpy(line);
	if (line[3] == 0)
		chdir("~/");
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
				process_cd(line);
		if (line[0] == 'l')
			if (line [1] == 's')
				process_ls(env);
	}
}

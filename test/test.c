#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MEM_ERR "Memory Allocation Error"

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

void    print_err(char *err, char *arr)
{
    (void)err;
    (void)arr;
}

int     ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
        if (*s1++ != *s2++)
            return (0);
    return (1);
}

int     chk_symbol(char *line)
{
    if (*line == '|')
        if (*(line + 1) == '|')
            return (2);
    if (*line == '&')
        if (*(line + 1) == '&')
            return (2);
    if (*line == '|')
        return (1);
    return (0);
}

int     chk_redirect(char *line)
{
    int cnt;

    cnt = 0;
    if (*line == '<' && *(line + 1) == '<')
        return (2);
    if (*line == '>' && *(line + 1) == '>')
        return (2);
    if (*line == '<' || *line == '>')
        return (1);
    return (0);
}

int     check_num(char *line)
{
    int cnt;

    cnt = 0;
    while ('0' <= *line && *line <= '9')
    {
        line++;
        cnt++;
    }
    if (cnt && (*line == '<' || *line == '>'))
        return (cnt + 1);
    return (0);
}

int     token_len(char  *str)
{
    int i;

    i = 0;
	if (!str)
		return (0);
    if (chk_symbol(str))
        return (chk_symbol(str));
    if (check_num(str))
        return (check_num(str));
    if (chk_redirect(str))
        return (chk_redirect(str));
    while (*str && !(*str == 32 || *str == 9) && !chk_symbol(str) &&
            !chk_redirect(str) && !check_num(str))
	{
		str++;
        i++;
	}
    return (i);
}

int    line_cpy(t_token *ptr, char *line)
{
    int i;
    int j;
    int size;

    i = 0;
    j = 0;
    while (ptr->token[i])
        i++;
    size = token_len(line);
    ptr->token[i] = malloc(size + 1);
    while (j < size)
        ptr->token[i][j++] = *line++;
    ptr->size++;
    ptr->token[i][j] = 0;
    ptr->token[i + 1] = 0;
    return (j);
}

void    process_split(t_token *ptr, char *line)
{
    int flag;

    flag = 0;
    while (*line)
    {
        while (*line && (*line == 32 || *line == 9))
            line++;
        if (chk_symbol(line) || chk_redirect(line) || check_num(line))
        {
            if (flag == 1 || flag == 2)
                ptr = ptr->next;
            line += line_cpy(ptr, line);
            flag = 2;
        }
        if (*line && !(*line == 32 || *line == 9) && !chk_symbol(line) && !chk_redirect(line) && !check_num(line))
        {
            if (flag == 2)
                ptr = ptr->next;
            line += line_cpy(ptr, line);
            flag = 1;
        }
    }
}

t_token	*node_init(void)
{
	t_token	*node;

	if (!(node = malloc(sizeof(t_token))))
		print_err(MEM_ERR, 0);
	node->token[0] = NULL;
	node->cmd_dir = 0;
	node->size = 0;
	node->pre = NULL;
	node->next = NULL;
	return (node);
}

void	node_push(t_handler *hand, int index)
{
    t_token *new;
	t_token	*old;

	new = node_init();
	if (hand->line == NULL)
		hand->line = new;
	else
	{
		old = hand->line;
		old->next = new;
		new->pre = old;
		hand->line = new;
	}
    hand->line->type = -1;
    hand->line->index = index;
}

int     get_token_cnt(char *line)
{
    int cnt;
    int flag;

    cnt = 0;
    flag = 0;
    while (*line)
    {
        while (*line && (*line == 32 || *line == 9 || *line == 45))
            line++;
        if (chk_symbol(line) || chk_redirect(line) || check_num(line))
        {
            line += token_len(line);
            flag = 0;
            cnt++;
        }
        else if (*line && !(*line == 32 || *line == 9) && !chk_symbol(line) &&
                    !chk_redirect(line) && !check_num(line))
        {
            if (!flag)
                cnt++;
            line += token_len(line);
            flag = 1;
        }
    }
    return (cnt);
}

void    line_split(t_handler *hand, char *line)
{
    int     size;
    int     i;

    if (!line)
        return ;
    size = get_token_cnt(line);
    printf("token count : %d\n", size);
    hand->top = hand->line;
    i = 0;
    while (++i < size)
        node_push(hand, i + 1);
	hand->line = hand->top;
    process_split(hand->line, line);
}

int  cmd_len(char *str)
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
    home = malloc(cmd_len(env[i]) - 4);
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

void    hand_init(t_handler *hand, char **env)
{
    hand->env = env;
    hand->line = 0;
    node_push(hand, 1);
    hand->top = hand->line;
    hand->clear = 0;
    getcwd(hand->dir, 1024);
    hand->home_dir = home_dir(env);
    hand->exit = 0;
    hand->status = 1;
    hand->pid = 0;
    hand->cmd_flag = 0;
    hand->cmd[0] = "/bin/";
    hand->cmd[1] = "/usr/local/bin/";
    hand->cmd[2] = "/usr/bin/";
    hand->cmd[3] = "/usr/sbin";
    hand->cmd[4] = "/sbin/";
}

void    shell_init(t_handler *hand, char **env)
{
    int     pid;
    char    *clear[2];

    clear[0] = "clear";
    clear[1] = 0;
    pid = fork();
    if (pid == 0)
        execve("/usr/bin/clear", clear, env);
}

char    *prompt(t_handler *hand)
{
    if (!hand->status)
        return ("😎 \033[0;32m\033[1mminishell \033[0;31m\033[1m▸ \033[0m");
    return ("😎 \033[0;32m\033[1mminishell ▸ \033[0m");
}

void    process_init(t_handler *hand, char **env)
{
    char    *line;
    int     status;

    while (hand->exit == 0)
    {
        line = readline(prompt(hand));
        if (!*line)
        {
            hand->status = 0;
            continue ;
        }
        hand_init(hand, env);
        add_history(line);
        line_split(hand, line);
        hand->line = hand->top;
        while (hand->line)
        {
            int i = -1;
            while (hand->line->token[++i])
                printf("%s ", hand->line->token[i]);
            printf("\n----------------------\n");
            hand->line = hand->line->next;
        }
    }
}

int main(int ac, char **av, char **env)
{
    t_handler hand;

    shell_init(&hand, env);
    process_init(&hand, env);
    prompt(&hand);
}
#include <stdio.h>
#include "lmt_describer.h"
#include "lmt.h"
#include "t_lmt_process_manager.h"

//	Command data
static void	lmt_describer_set_debug_color(void)
{
	printf("\x1b[1;31m \n");
}

static void	lmt_describer_reset_debug_color(void)
{
	printf("\x1b[0;37m \n");
}

static void	lmt_describer_print_title(char *title)
{
	printf("\n[ %s ] \n", title);
}

void	string_array_describe(char **array)
{
	char	**element;

	element = array;
	while (*element != NULL)
	{
		PRINT(*element, s);
		++element;
	}
}

//	Custom data

void	lmt_token_sublist_describe(t_lmt_token_sublist *sublist)
{
	t_token	*element;

	lmt_describer_print_title("lmt_token_sublist describe");

	element = sublist->first;
	while (element != sublist->terminator)
	{
		token_describe(element);
		element = element->next;
	}
}

void	lmt_redirection_describe(t_lmt_redirection *p_redirection)
{
	PRINT(p_redirection->fd_old, d);
	PRINT(p_redirection->type, d);
	PRINT(p_redirection->fd_new, d);
	PRINT(p_redirection->path_new, s);
}

void	lmt_redirection_list_describe(t_lmt_redirection_list *list)
{
	t_lmt_redirection	*element;

	lmt_describer_print_title("lmt_redirection_array describe");

	element = list->p_dummy->next;
	while (element != NULL)
	{
		lmt_redirection_describe(element);
		element = element->next;
	}
}

void	lmt_process_describe(t_lmt_process *p_process)
{
	PRINT(p_process->type, d);
	lmt_token_sublist_describe(p_process->token_sublist);
	lmt_redirection_list_describe(p_process->redirection_list);
	PRINT(p_process->next_operator, d);
	PRINT(p_process->pid, d);
}

void	lmt_process_list_describe(t_lmt_process_list *list)
{
	t_lmt_process	*element;

	lmt_describer_print_title("lmt_process_list describe");

	element = list->p_dummy->next;
	while (element != NULL)
	{
		lmt_process_describe(element);
		element = element->next;
	}
}

//	seonkim's structure
void	token_describe(t_token *p_token)
{
	lmt_describer_print_title("token describe");

	string_array_describe(p_token->token);
	PRINT(p_token->cmd_dir, s);
	PRINT(p_token->type, d);
	PRINT(p_token->size, d);
	putchar('\n');
}

void	token_list_describe(t_token *p_first_token)
{
	t_token	*element;

	element = p_first_token;
	while (element != NULL)
	{
		token_describe(element);
		element = element->next;
	}
}

void	path_describe(t_path *p_path)
{
	PRINT(p_path->dir, s);
	PRINT(p_path->home_dir, s);
}

void	handler_describe(t_handler *p_handler)
{
	t_token	*p_token;

	lmt_describer_set_debug_color();
	lmt_describer_print_title("handler describe");

	p_token = p_handler->top;
	while (p_token != NULL)
	{
		token_describe(p_token);
		p_token = p_token->next;
	}
	path_describe(p_handler->path);
//	string_array_describe(p_handler->env);
	PRINT(p_handler->clear, s);
	PRINT(p_handler->token_size, d);
	PRINT(p_handler->exit, d);
	PRINT(p_handler->status, d);
	PRINT(p_handler->pid, d);
	PRINT(p_handler->cmd_flag, d);

	lmt_describer_reset_debug_color();
}

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_node
{
	int		data;
	struct s_node	*pre;
	struct s_node	*next;
}				t_node;
	
t_node	*create_node(char *str)
{
	t_node	*stk;

	stk = malloc(sizeof(t_node));
	if (!str)
		stk->data = 0;
	stk->pre = NULL;
	stk->next = NULL;
	return (stk);
}

void	node_front(t_node *stk)
{
	while (stk->pre)
		stk = stk->pre;
}

void	node_back(t_node *stk)
{
	while (stk->next)
		stk = stk->next;
}

void	node_push(t_node *stk, char *str)
{
	t_node	*node;
	t_node	*old;

	node = create_node(str);
	if (stk == NULL)
		stk = node;
	else
	{
		old = stk;
		old->next = node;
		node->pre = old;
		stk = node;
	}
}

void	node_pop_front(t_node *stk)
{
	t_node *cur_top;
	t_node *new_top;

	cur_top = stk;
	if (!cur_top)
		return ;
	else
	{
		new_top = stk->next;
		new_top->pre = NULL;
		stk = new_top;
	}
	free(cur_top);
}

void	node_pop_back(t_node *stk)
{
	t_node *cur_top;
	t_node *new_top;

	cur_top = stk;
	if (!cur_top)
		return ;
	else
	{
		new_top = stk->pre;
		new_top->next = NULL;
		stk = new_top;
	}
	free(cur_top);
}


int main()
{
	t_node *lst;
	int i;

	i = -1;
	while (++i < 10)
		node_push(lst, 0);
	printf("%d\n", lst->data);
	printf("test\n");
	node_front(lst);
	printf("test1\n");
	lst->data = 10;
	i = -1;
	while (++i < 10)
	{
		printf("%d\n", lst->data);
		lst = lst->next;
	}
}

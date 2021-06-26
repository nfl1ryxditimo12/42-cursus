#include <stdio.h>
#include <stdlib.h>

typedef struct	s_node
{
	int				data;
	struct s_node	*pre;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	t_node			*top;
	int				size;
}				t_stack;

void	node_top(t_stack *stk)
{
	int i;

	i = stk->size;
	while (stk->top->pre && i > 0)
	{
		stk->top = stk->top->pre;
		i--;
	}
}

void	node_bottom(t_stack *stk)
{
	int	i;

	i = stk->size;
	while (stk->top->next && i > 0)
	{
		stk->top = stk->top->next;
		i--;
	}
}

t_node	*node_init(char *str)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->data =  0;
	node->pre = NULL;
	node->next = NULL;
	return (node);
}

void	node_push(t_stack *stk, char *str)
{
	t_node	*node;
	t_node	*old;

	node = node_init(str);
	if (stk->top == NULL)
		stk->top = node;
	else
	{
		old = stk->top;
		old->next = node;
		node->pre = old;
		stk->top = node;
	}
	stk->size++;
}


void	process_rotate(t_stack *stk)
{
	t_node	*new_top;
	t_node	*old_top;

	node_bottom(stk);
	old_top = stk->top;
	node_top(stk);
	new_top = stk->top->next;
	new_top->pre = NULL;
	stk->top->next = NULL;
	old_top->next = stk->top;
	stk->top->pre = old_top;
	stk->top = new_top;
}

void	process_reverse(t_stack *stk)
{
	t_node	*new_top;
	t_node	*old_top;

	node_top(stk);
	old_top = stk->top;
	node_bottom(stk);
	new_top = stk->top;
	new_top->next = old_top;
	old_top->pre = new_top;
	new_top->pre = NULL;
	stk->top = new_top;
}

void	process_push(t_stack *a, t_stack *b)
{
	t_node	*n_a;
	t_node	*n_b;
	int		flag;

	if (!b->size)
		return ;
	flag = 0;
	printf("\ntest\n");
	node_top(a);
	printf("test1\n");
	node_top(b);
	n_b = b->top->next;
	n_a = b->top;
	n_b->pre = NULL;
	n_a->pre = NULL;
	n_a->next = a->top ? a->top : NULL;
	a->top->pre = a->top ? n_a : NULL;
	a->top = n_a;
	printf("test2\n");
	a->size++;
	b->size--;
}

int main()
{
	t_stack a;
	t_stack b;

	a.top = NULL;
	a.size = 3;
	b.top = NULL;
	b.size = 0;
	for (int i = 0; i < 3; i++)
	{
		node_push(&a, 0);
		a.top->data = i + 1;
		printf("%d\n", a.top->data);
	}
	printf("current %d\n", a.top->data);
	node_top(&a);
	printf("now %d\n", a.top->data);
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", a.top->data);
		if (a.top->next)
			a.top = a.top->next;
	}
	printf("\n");
	process_rotate(&a);
	printf("rotate : %d\n", a.top->data);
	node_top(&a);
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", a.top->data);
		if (a.top->next)
			a.top = a.top->next;
	}
	printf("\n");
	node_top(&a);
	process_reverse(&a);
	printf("reverse : %d\n", a.top->data);
	node_top(&a);
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", a.top->data);
		if (a.top->next)
			a.top = a.top->next;
	}
	process_push(&b, &a);
	printf("%d\n", b.top->data);
}

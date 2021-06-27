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
	t_node			*bot;
	t_node			*ptr;
	int				size;
}				t_stack;

void	node_top(t_stack *stk)
{
	int i;

	i = stk->size;
	while (stk->ptr->pre && i > 0)
	{
		stk->ptr = stk->ptr->pre;
		i--;
	}
}

void	node_bottom(t_stack *stk)
{
	int	i;

	i = stk->size;
	while (stk->ptr->next && i > 0)
	{
		stk->ptr = stk->ptr->next;
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
	if (stk->ptr == NULL)
		stk->ptr = node;
	else
	{
		old = stk->ptr;
		old->next = node;
		node->pre = old;
		stk->ptr = node;
	}
	stk->size++;
}


void	process_rotate(t_stack *stk)
{
	t_node	*new_ptr;
	t_node	*bot_ptr;

	if (!stk->size)
		return ;
	stk->ptr = stk->top;
	bot_ptr = stk->bot;
	new_ptr = stk->top->next;
	new_ptr->pre = NULL;
	stk->ptr->next = NULL;
	bot_ptr->next = stk->ptr;
	stk->ptr->pre = bot_ptr;
	stk->bot = stk->ptr;
	stk->top = new_ptr;
}

void	process_reverse(t_stack *stk)
{
	t_node	*new_ptr;
	t_node	*bot_ptr;

	if (!stk->size)
		return ;
	bot_ptr = stk->bot->pre;
	new_ptr = stk->bot;
	new_ptr->next = stk->top;
	new_ptr->pre = NULL;
	bot_ptr->next = NULL;
	stk->top->pre = new_ptr;
	stk->top = new_ptr;
	stk->bot = bot_ptr;
}

void	process_push(t_stack *a, t_stack *b)
{
	t_node	*n_a;
	t_node	*n_b;

	if (!b->size)
		return ;
	else if (b->size > 1)
	{
		n_b = b->ptr->next;
		n_b->pre = NULL;
	}
	else if (b->size == 1)
		n_b = NULL;
	n_a = b->ptr;
	n_a->pre = NULL;
	if (a->size > 0)
		a->ptr->pre = n_a;
	n_a->next = a->ptr ? a->ptr : NULL;
	a->ptr = n_a;
	b->ptr = n_b;
	a->top = n_a;
	b->top = n_b;
	a->size++;
	b->size--;
}

int main()
{
	t_stack a;
	t_stack b;

	a.ptr = NULL;
	a.top = NULL;
	a.size = 0;
	b.ptr = NULL;
	b.top = NULL;
	b.bot = NULL;
	b.size = 0;
	node_push(&a, 0);
	a.ptr->data = 1;
	a.top = a.ptr;
	for (int i = 1; i < 3; i++)
	{
		node_push(&a, 0);
		a.ptr->data = i + 1;
		printf("%d\n", a.ptr->data);
	}
	a.bot = a.ptr;
	printf("current %d\n", a.ptr->data);
	a.ptr = a.top;
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", a.ptr->data);
		if (a.ptr->next)
			a.ptr = a.ptr->next;
	}
	printf("\n");
	process_rotate(&a);
	printf("rotate : %d\n", a.ptr->data);
	printf("now top : %d\n", a.top->data);
	printf("now bottom: %d\n", a.bot->data);
	process_rotate(&a);
	a.ptr = a.top;
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", a.ptr->data);
		if (a.ptr->next)
			a.ptr = a.ptr->next;
	}
	printf("\n");
	a.ptr = a.top;
	process_reverse(&a);
	printf("reverse : %d\n", a.ptr->data);
	a.ptr = a.top;
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", a.ptr->data);
		if (a.ptr->next)
			a.ptr = a.ptr->next;
	}
	a.ptr = a.top;
	process_push(&b, &a);
	process_push(&b, &a);
	process_push(&b, &a);
	a.size = 0;
	process_push(&b, &a);
	b.top = b.ptr;
	printf("\nb data : ");
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", b.ptr->data);
		if (b.ptr->next)
			b.ptr = b.ptr->next;
	}
	printf("\n\n");
	b.ptr = b.top;
	process_push(&a, &b);
	printf("%d\n", b.ptr->next->data);
	b.ptr = b.ptr->next;
	printf("%d\n", b.ptr->pre->data);
}

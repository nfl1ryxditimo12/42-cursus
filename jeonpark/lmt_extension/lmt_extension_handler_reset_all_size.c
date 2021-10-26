#include "lmt_extension_token.h"

void	lmt_reset_handler_all_size(t_handler *handler)
{
	int		count;
	t_token	*element;

	count = 0;
	element = handler->top;
	while (element != NULL)
	{
		element->size = lmt_count_of_null_terminated_array((void **)element->token);
		++count;
		element = element->next;
	}
	handler->token_size = count;
}

#include "lmt_extension_token.h"

static void	lmt_reset_token_size(t_token *token)
{
	int		count;
	char	**element;

	count = 0;
	element = token->token;
	while (*element != NULL)
	{
		++count;
		++element;
	}
	token->size = count;
}

void	lmt_reset_handler_all_size(t_handler *handler)
{
	int		count;
	t_token	*element;

	count = 0;
	element = handler->top;
	while (element != NULL)
	{
		lmt_reset_token_size(element);
		++count;
		element = element->next;
	}
	handler->token_size = count;
}

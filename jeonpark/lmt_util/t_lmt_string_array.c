#include <stdlib.h>
#include "t_lmt_string_array.h"
#include "lmt_util.h"

//	stdlib.h: free(), NULL

static t_lmt_string_array	*lmt_string_array_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_string_array)));
}

static void	lmt_string_array_init(t_lmt_string_array *array)
{
	array->array = lmt_alloc(sizeof(char *) * 1);
	array->array = NULL;
	array->count = 0;
}

t_lmt_string_array	*lmt_string_array_new(void)
{
	t_lmt_string_array	*array;

	array = lmt_string_array_alloc();
	lmt_string_array_init(array);
	return (array);
}

void	lmt_string_array_free(lmt_string_array *array)
{
	free(array->array);
	free(array);
}

void	lmt_string_array_append(t_lmt_string_array *string_array, char *string)
{
	char	**array;
	int	index;

	array = lmt_alloc(sizeof(char *) * (string_array->count + 2));
	index = 0;
	while (index < string_array->count)
	{
		array[index] = string_array->array[index];
		++index;
	}
	array[index] = string;
	++index;
	array[index] = NULL;
	free(string_array->array);
	string_array->array = array;
}

void	lmt_string_array_append_lmt_string_array(t_lmt_string_array *lhs, t_lmt_string_array *rhs)
{
	char	**array;
	int	index;

	array = lmt_alloc(sizeof(char *) * (lhs->count + rhs->count + 1));
	index = 0;
	while (index < lhs->count)
	{
		array[index] = lhs->array[index];
		++index;
	}
	index = 0;
	while (index < rhs->count)
	{
		array[lhs->count + index] = rhs->array[index];
		++index;
	}
	array[lhs->count + rhs->count] = NULL;
	free(lhs->array);
	lhs->array = array;
}

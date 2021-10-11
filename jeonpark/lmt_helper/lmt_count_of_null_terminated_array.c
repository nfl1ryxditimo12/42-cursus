#include "lmt_helper.h"

int	lmt_count_of_null_terminated_array(void *array)
{
	int	count;

	count = 0;
	while (array != NULL)
	{
		++count;
		++array;
	}
	return (count);
}

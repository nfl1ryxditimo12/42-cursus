#ifndef T_LMT_STRING_ARRAY_H
# define T_LMT_STRING_ARRAY_H

typedef struct s_lmt_string_array
{
	char	**array;
	int	count;
}	t_lmt_string_array;

t_lmt_string_array	*lmt_string_array_new(void);
void	lmt_string_array_free(t_lmt_string_array *array);
void	lmt_string_array_append(t_lmt_string_array *string_array, char *string);
void	lmt_string_array_append_array(t_lmt_string_array *lhs, t_lmt_string_array *rhs);

#endif

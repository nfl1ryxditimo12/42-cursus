#ifndef T_LMT_DESCRIBER_H
# define T_LMT_DESCRIBER_H

# include "lmt_process_manager_typedef.h"

void	string_array_describe(char **array);

void	lmt_token_sublist_describe(t_lmt_token_sublist *sublist);

void	lmt_redirection_describe(t_lmt_redirection *p_redirection);
void	lmt_redirection_list_describe(t_lmt_redirection_list *list);

void	lmt_process_describe(t_lmt_process *p_process);
void	lmt_process_list_describe(t_lmt_process_list *list);
void	token_describe(t_token *p_token);
void	token_list_describe(t_token *p_first_token);
void	handler_describe(t_handler *p_handler);

#endif

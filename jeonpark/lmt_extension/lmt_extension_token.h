#ifndef LMT_EXTENSION_TOKEN_H
# define LMT_EXTENSION_TOKEN_H

# include "minishell.h"	// t_token
# include "lmt_c_library.h"	// t_lmt_string
# include "lmt_util.h"	// is_type_()
# include "constant.h"	// TYPE_

void	lmt_arrange_token(t_token *p_first_token);

int		lmt_is_token_type_control_operator(t_token *p_token);
int		lmt_is_token_type_redirection(t_token *p_token);
int		lmt_is_token_type_open_parenthesis(t_token *p_token);
int		lmt_is_token_type_close_parenthesis(t_token *p_token);
int		lmt_is_token_type_command(t_token *p_token);

void	lmt_refine_token_argv_0(t_token *p_command_token);

void	lmt_set_token_type(t_token *p_first_token);

#endif

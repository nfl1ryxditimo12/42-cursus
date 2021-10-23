#include "minishell.h"
#include "lmt_c_library.h"
#include "lmt_unsafe.h"
#include "lmt_helper.h"

int is_question(char *str)
{
    while (*str)
        if (*str++ == '$')
            if (*str && *str == '?')
                return (1);
    return (0);
}



void    lmt_convert_question_token(t_token *token, int status)
{
    char    **element;
    char    *status_str;
    char    *converted;
    char    *question;
    char    *ptr;

    element = token->token - 1;
    while (*(++element) != NULL)
        while (is_question(*element))
        {
            status_str = lmt_itoa(status);
            question = *element;
            while (*question && (*question != '$' && *(question + 1) != '?'))
                ++question;
            converted = lmt_alloc(cmd_len(*element) - 1 + cmd_len(status_str));
            *question = '\0';
            ptr = lmt_unsafe_strcpy(converted, *element);
            ptr = lmt_unsafe_strcpy(ptr, status_str);
            ptr = lmt_unsafe_strcpy(ptr, question + 2);
            *ptr = '\0';
            free(*element);
            *element = converted;
            free(status_str);
        }
}

void    lmt_convert_question(t_handler *handler)
{
    t_token    *element;

    element = handler->top;
    while (element != NULL)
    {
        lmt_convert_question_token(element, handler->status);
        if (is_type_control_operator(element->type))
            handler->status = 0;
        element = element->next;
    }
}
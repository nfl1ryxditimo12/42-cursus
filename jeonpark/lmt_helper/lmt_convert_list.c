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

char *lmt_strldup(char *str, int size)
{
    char *ret;
    int i;

    i = -1;
    if (!str || !*str)
        return (0);
    ret = malloc(size + 1);
    while (++i < size)
        ret[i] = str[i];
    ret[i] = 0;
    return (ret);
}

void    lmt_convert_question(char **element, int status)
{
    char    *status_str;
    char    *converted;
    char    *question;
    char    *ptr;

    while (is_question(*element) && **element != '\'')
    {
        status_str = lmt_itoa(status);
        question = *element;
        while (*question && (*question != '$' && *(question + 1) != '?'))
            ++question;
        converted = lmt_alloc(lmt_unsafe_strlen(*element) - 1 + \
                    lmt_unsafe_strlen(status_str));
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

void    lmt_remove_quotes(char **element)
{
    char *ptr;

    if (**element == '\"' || **element == '\'')
    {
        ptr = *element;
        *element = lmt_strldup((*element) + 1, \
                    lmt_unsafe_strlen((*element) + 1) - 1);
        free(ptr);
    }
}

void    lmt_convert_token(t_token *token, int status)
{
    char    **element;

    element = token->token;
    while (*element != NULL)
    {
        lmt_convert_question(element, status);
        lmt_remove_quotes(element);
        element++;
    }
}

void    lmt_convert_list(t_handler *handler)
{
    t_token    *element;

    element = handler->top;
    while (element != NULL)
    {
        lmt_convert_token(element, handler->status);
        if (is_type_control_operator(element->type))
            handler->status = 0;
        element = element->next;
    }
}
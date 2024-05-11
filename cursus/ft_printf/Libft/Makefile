SRCS = ft_strlen.c		\
	   ft_isdigit.c		\
	   ft_strchr.c		\
	   ft_strlcpy.c		\
	   ft_strdup.c		\
	   ft_putchar_fd.c

NAME = libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(SRCS) libft.h $(CFLAGS)
	ar -csr $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

CC=gcc
CFLAGS=-Wall -Wextra -Werror -c
SRC = srcs
INC = includes
TARGET = libft.a
SRCS = $(SRC)/ft_putchar.c $(SRC)/ft_swap.c $(SRC)/ft_putstr.c $(SRC)/ft_strlen.c $(SRC)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INC)

$(TARGET): $(OBJS)
	ar cr $@ $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re : fclean all

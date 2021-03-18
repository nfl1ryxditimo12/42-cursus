CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = srcs
INC = includes
TARGET = bsq
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

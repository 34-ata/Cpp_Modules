NAME = bsp

CC = c++

CFLAGS = -std=c++98 -Wall -Werror -Wextra

SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(NAME)

re: clean all


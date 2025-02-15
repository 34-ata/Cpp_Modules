NAME = convert
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = ScalarConverter.cpp main.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CPP) $(CPPFLAGS) $(SRCS) -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all
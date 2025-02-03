NAME = fragtrap

CPP = c++

CFLAGS = -std=c++98 -Wall -Werror -Wextra

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CPP) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(NAME)

re: clean all


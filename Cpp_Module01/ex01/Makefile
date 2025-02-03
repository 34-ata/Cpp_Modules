NAME = horde

FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Zombie.cpp zombieHorde.cpp

all: $(NAME)

$(NAME):
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean $(NAME)
NAME = brainz

FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

all: $(NAME)

$(NAME):
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean $(NAME)
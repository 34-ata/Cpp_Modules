NAME = violence

FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

all: $(NAME)

$(NAME):
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean $(NAME)
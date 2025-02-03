NAME = harl

FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Harl.cpp

all: $(NAME)

$(NAME):
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean $(NAME)
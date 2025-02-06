NAME = bureaucrat
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = Bureaucrat.cpp AForm.cpp main.cpp ShrubberyCreationForm.cpp


all: $(NAME)

$(NAME): $(SRCS)
	$(CPP) $(CPPFLAGS) $(SRCS) -o $@

clean:
	rm -rf $(NAME)

re: clean all
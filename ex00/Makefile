NAME = ex00

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp

OBJS = $(patsubst %.cpp, obj/%.o, $(SRCS))

all: obj $(NAME)

obj:
	@mkdir -p obj

obj/%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(SRCS)
	@c++ $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[32m$(NAME) is created\033[0m"

clean: 
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all
NAME = ex01

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = src/main.cpp src/Bureaucrat.cpp src/Form.cpp

OBJS = $(patsubst src/%.cpp, obj/%.o, $(SRCS))

all: obj $(NAME)

obj:
	@mkdir -p obj

obj/%.o: src/%.cpp | obj
	c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(SRCS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

clean: 
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

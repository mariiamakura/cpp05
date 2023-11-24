NAME = ex02

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = src/main.cpp src/Bureaucrat.cpp src/AForm.cpp src/ShrubberyCreationForm.cpp \
		src/RobotomyRequestForm.cpp src/PresidentialPardonForm.cpp

OBJS = $(patsubst src/%.cpp, obj/%.o, $(SRCS))

all: obj $(NAME)

obj:
	@mkdir -p obj

obj/%.o: src/%.cpp | obj
	@c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(SRCS)
	@c++ $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[32m$(NAME) is created\033[0m"

clean: 
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

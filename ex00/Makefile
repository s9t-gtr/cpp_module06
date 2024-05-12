CPPS = main.cpp ScalarConverter.cpp

OBJS = ${CPPS:.cpp=.o}

DEPS = ${CPPS:.cpp=.d}

NAME = convert
CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS += -g3
CXXFLAGS += -MMD -MP
-include ${DEPS}

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

.PHONY: all clean fclean re
all: $(NAME);

clean: 
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all;

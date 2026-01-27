NAME = federal_bureau_of_control

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98 -pedantic -g #-fsanitize=address,leak,undefined

SOURCES = main.cpp
CLASS_SOURCES = Bureaucrat.cpp
ALL_SOURCES = $(SOURCES) $(CLASS_SOURCES)

HEADERS = Bureaucrat.hpp

OBJ_DIR = objects/
OBJS = $(ALL_SOURCES:%.cpp=$(OBJ_DIR)%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJ_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: re
	./$(NAME)

runval: CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic -g
runval: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
	
runsan: CXXFLAGS:= -std=c++98 -g -fsanitize=address,leak,undefined
runsan: re
	./$(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

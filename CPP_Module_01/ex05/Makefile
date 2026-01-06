NAME = complain

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98 # -g# -fsanitize=address,undefined

SOURCES = main.cpp
CLASS_SOURCES = Harl.cpp
ALL_SOURCES = $(SOURCES) $(CLASS_SOURCES)

HEADERS = main.hpp Harl.hpp

OBJ_DIR = objects/
OBJS = $(ALL_SOURCES:%.cpp=$(OBJ_DIR)%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJ_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)
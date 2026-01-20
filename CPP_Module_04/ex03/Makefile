NAME = i_dont_want_to_set_the_world_on_fire_i_just_want_to_start_a_flame_in_your_heart

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98 -pedantic #-g #-fsanitize=address,leak,undefined

SOURCES = main.cpp
CLASS_SOURCES = AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp
ALL_SOURCES = $(SOURCES) $(CLASS_SOURCES)

HEADERS = AMateria.hpp Cure.hpp Ice.hpp ICharacter.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp

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

runf: CXXFLAGS:= -g -fsanitize=address,leak,undefined
runf: re
	./$(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

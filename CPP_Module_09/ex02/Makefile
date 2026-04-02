NAME = PmergeMe

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98 -pedantic #-O3 #-g #-fsanitize=address,undefined,bounds,float-divide-by-zero

SOURCES = main.cpp
CLASS_SOURCES = PmergeMe.cpp
ALL_SOURCES = $(SOURCES) $(CLASS_SOURCES)

HEADERS = PmergeMe.hpp
TEMPLATE = 

OBJ_DIR = objects/
OBJS = $(ALL_SOURCES:%.cpp=$(OBJ_DIR)%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

#80 43 140 77 110 44 42 35 93 8 95 118 139 83 108 111 130 0 90 84 33 
#11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
#1087 848 28 1669 456 1919 226 1828 621 1868 614 1367 72
run: re
	./$(NAME) 1257 1374 853 1551 1679 1138 1149 801 1186 637 1615 1695 853 1539 1226 377 1176 1889 1917 664 1186 1658 802 1513 141 807 502 1922 1519 984 1787 230 484 1099 1233 856 1228 1300 813 66 1102 984 1515 1111 698 159 654 502 152 1856 296

rand: re
	./$(NAME) `jot -r 21 0 20000000`

runval: CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic -g
runval: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
	
runsan: CXXFLAGS:= -std=c++98 -g -fsanitize=address,leak,undefined,bounds,float-divide-by-zero
runsan: re
	./$(NAME) 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

-include $(DEPS)

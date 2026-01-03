NAME = log

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address,undefined

SOURCES = tests.cpp
CLASS_SOURCES = Account.cpp
ALL_SOURCES = $(SOURCES) $(CLASS_SOURCES)

HEADERS = PhoneBook.class.hpp Contact.class.hpp

OBJ_DIR = objects/
OBJS = $(ALL_SOURCES:%.cpp=$(OBJ_DIR)%.o)

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
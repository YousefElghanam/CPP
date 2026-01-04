NAME = phonebook

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98 #-g -fsanitize=address,undefined

SOURCES = main.cpp colorize.cpp
CLASS_SOURCES = PhoneBook.class.cpp
ALL_SOURCES = $(SOURCES) $(CLASS_SOURCES)

HEADERS = PhoneBook.class.hpp Contact.class.hpp

OBJS_DIR = ./objects/
OBJS = $(ALL_SOURCES:%.cpp=$(OBJS_DIR)%.o)
DEPS = $(OBJS:%.o=%.d)

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
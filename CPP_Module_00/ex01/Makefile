NAME = phonebook

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp colorize.cpp
CLASS_SOURCES = PhoneBook.class.cpp
ALL_SOURCES = $(SOURCES) $(CLASS_SOURCES)

HEADERS = PhoneBook.class.hpp Contact.class.hpp

OBJ_DIR = objects/
OBJS = $(ALL_SOURCES:%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
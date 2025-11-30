NAME = phonebook

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp PhoneBook.class.cpp

HEADERS = PhoneBook.class.hpp Contact.class.hpp

OBJ_DIR = objects/
OBJS = $(SOURCES:%.cpp=$(OBJ_DIR)%.o)

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
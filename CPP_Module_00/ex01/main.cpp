#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstdio>

static int	is_only_spaces(std::string str) {
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
		if (!isspace(*it))
			return (0);
	}
	return (1);
}

static int	prompt_string_field(std::string prompt, std::string *field)
{
	std::string			s;
	std::stringstream	ss;
	
	std::cout << prompt;
	std::getline(std::cin, *field);
	if (std::cin.eof() || field->empty() || is_only_spaces(*field)) {
		if (std::cin.eof()) {
			std::cout << std::endl;
			std::clearerr(stdin);
		}
		std::cin.clear();
		// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (1);
	}
	if (std::cin.fail())
		exit(1);
	return (0);
}

static int	prompt_new_contact(Contact *contact)
{
	std::cout << "Adding new contact" << std::endl;
	if (prompt_string_field("First Name: ", &contact->first_name)
		|| prompt_string_field("Last Name: ", &contact->last_name)
		|| prompt_string_field("Nickname: ", &contact->nick_name)
		|| prompt_string_field("Phone Number: ", &contact->phone)
		|| prompt_string_field("Darkest Secret: ", &contact->secret))
		{
			std::cout << "Adding new contact failed. Can't have an empty field" << std::endl;
			return (1);
		}
	return (0);
}

static int	prompt_contact_id(size_t *id)
{
	std::string			s;
	std::stringstream	ss(s);

	std::cout << "Enter contact id: ";
	std::getline(std::cin, s);
	if (std::cin.eof() || s.empty() || is_only_spaces(s)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.eof())
			std::cout << std::endl;
		std::cout << "Search failed. Empty input" << std::endl;
		return (1);
	}
	if (std::cin.fail()) {
		exit(1);
	}
	ss >> *id;
	if (ss.fail()) {
		std::cout << "Invalid id. Enter a number" << std::endl;
		return (1);
	}
	return (0);
}


int	main(void) {
	PhoneBook	phone_book;
	std::string	input;

	std::cout << "===PHONEBOOK===" << std::endl;
	std::cout << "ADD, SEARCH, EXIT" << std::endl;
	while (1) {
		std::cout  << ">";
		std::getline(std::cin, input);
		if (std::cin.eof() || input == "EXIT") {
			std::cout << std::endl << "Exiting" << std::endl;
			return (0);
		}
		else if (input.empty() || is_only_spaces(input)) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
			continue ;
		}
		else if (!std::cin) {
			std::cout << "Unexpected input, Exiting" << std::endl;
			return (1);
		}

		else if (input == "ADD") {
			Contact	contact;

			if (prompt_new_contact(&contact))
				continue ;
			phone_book.add(contact);
			std::cout << "Contact added successfully" << std::endl;
		}

		else if (input == "SEARCH") {
			size_t	id;
			Contact	contact;

			// if (phone_book.size == 0) {
			// 	std::cout << "The PhoneBook is empty" << std::endl;
			// 	continue ;
			// }
			phone_book.display_all_contacts();
			if (prompt_contact_id(&id))
				continue ;
			phone_book.display_contact_info(id);
			// contact = phone_book.get(id);
		}

		else {
			std::cout << "INVALID INPUT" << std::endl;
		}
	}
}
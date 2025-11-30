#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <cstring>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <iostream>

static int	prompt_string_field(std::string prompt, std::string *field)
{
	std::cout << prompt;
	std::getline(std::cin, *field);
	if (std::cin.eof())
		return (std::cin.clear(), 1);
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
			std::cout << std::endl << "Adding new contact failed. Can't have an empty field" << std::endl;
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
	if (std::cin.eof())
		return (std::cin.clear(), 1);
	ss >> *id;
	return (0);
}


int	main(void) {
	PhoneBook	phone_book;
	std::string	input;

	std::cout << "===PHONEBOOK===" << std::endl;
	std::cout << "ADD, SEARCH, EXIT" << std::endl;
	while (1) {
		std::cin.clear();
		std::cout  << std::endl << ">";
		std::getline(std::cin, input).fail();
		if (std::cin.eof() || input == "EXIT") {
			std::cout << std::endl << "Exiting" << std::endl;
			return (0);
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

			if (phone_book.size == 0) {
				std::cout << "The PhoneBook is empty" << std::endl;
				continue ;
			}
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
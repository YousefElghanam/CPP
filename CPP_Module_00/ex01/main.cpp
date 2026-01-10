#include "main.hpp"

static int	is_only_spaces(std::string str) {
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
		if (!isspace(*it))
			return (0);
	}
	return (1);
}

static int	prompt_string_field(std::string prompt, std::string *field)
{
	cyan(prompt, 0);
	std::getline(std::cin, *field);
	if (std::cin.eof() || field->empty() || is_only_spaces(*field)) {
		if (std::cin.eof())
			std::cout << std::endl;
		clearerr(stdin);
		std::cin.clear();
		return (1);
	}
	if (std::cin.fail())
		exit(1);
	return (0);
}

static int	prompt_new_contact(Contact *contact)
{
	cyan("Adding new contact", 1);
	if (prompt_string_field("First Name: ", &contact->first_name)
		|| prompt_string_field("Last Name: ", &contact->last_name)
		|| prompt_string_field("Nickname: ", &contact->nick_name)
		|| prompt_string_field("Phone Number: ", &contact->phone)
		|| prompt_string_field("Darkest Secret: ", &contact->secret))
		{
			red("Adding new contact failed. Can't have an empty field", 1);
			return (1);
		}
	return (0);
}

static int	prompt_contact_id(size_t *id)
{
	std::string			line;
	std::stringstream	ss;

	cyan("Enter contact id: ", 1);
	std::getline(std::cin, line);
	if (std::cin.eof() || line.empty() || is_only_spaces(line)) {
		if (std::cin.eof())
			std::cout << std::endl;
		red("Search failed. Empty input", 1);
		clearerr(stdin);
		std::cin.clear();
		return (1);
	}
	if (std::cin.fail()) {
		exit(1);
	}
	ss.clear();
	ss.str(line);
	ss >> *id;
	if (ss.fail() || !ss.eof()) {
		red("Invalid input. Not digits or too big", 1);
		return (1);
	}
	return (0);
}

int	search(PhoneBook phone_book) {
	size_t	id;
	Contact	contact;

	if (phone_book.size == 0) {
		cyan("The PhoneBook is empty", 1);
		return (1);
	}
	phone_book.display_all_contacts();
	if (prompt_contact_id(&id))
		return (1);
	phone_book.display_contact_info(id);
	return (0);
}

int	add_contact(PhoneBook &phone_book) {
	Contact	contact;

	if (prompt_new_contact(&contact))
		return (1);
	phone_book.add(contact);
	green("Contact added successfully", 1);
	return (0);
}

int	main(void) {
	PhoneBook	phone_book;
	std::string	input;

	cyan("=====PHONEBOOK=====", 1);
	cyan("ADD - SEARCH - EXIT", 1);
	while (1) {
		std::cout  << ">";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << std::endl;
			magenta("Exiting", 1);
			return (0);
		}
		if (input == "EXIT") {
			magenta("Exiting", 1);
			return (0);
		}
		else if (!std::cin) {
			red("Unexpected input, Exiting", 1);
			return (1);
		}
		else if (input.empty() || is_only_spaces(input)) {
			clearerr(stdin);
			continue ;
		}
		else if (input == "ADD") {
			if (add_contact(phone_book))
				continue ;
		}
		else if (input == "SEARCH") {
			if (search(phone_book))
				continue ;
		}
		else {
			red("INVALID INPUT", 1);
		}
	}
}
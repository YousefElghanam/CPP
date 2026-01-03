#include "phonebook.hpp"
#include "PhoneBook.class.hpp"
#include <ios>
#include <iostream>

PhoneBook::PhoneBook(void) {
	PhoneBook::size = 0;
};

PhoneBook::~PhoneBook(void) {
	PhoneBook::size = 0;
};

void	PhoneBook::add(Contact contact) {
	if (size == 0)
		oldest = 0;
	if (size < CAP)
	{
		contacts[size] = contact;
		size++;
	}
	else
	{
		contacts[oldest] = contact;
		oldest++;
		if (oldest == CAP)
			oldest = 0;
	}
};

static std::string	fix_string(std::string &s) {
	if (s.length() > 10)
	{
		s[9] = '.';
		s = s.substr(0, 10);
	}
	return (s);
};

static void	display_contact(Contact contact, size_t i) {
	std::cout.width(10); std::cout << std::right << i;
	cyan("|", 0);
	std::cout.width(10); std::cout << std::right << fix_string(contact.first_name);
	cyan("|", 0);
	std::cout.width(10); std::cout << std::right << fix_string(contact.last_name);
	cyan("|", 0);
	std::cout.width(10); std::cout << std::right << fix_string(contact.nick_name);
	std::cout << std::endl;
};

void	PhoneBook::display_all_contacts(void) {
	cyan("============ Available Contacts ===========", 1);
	std::cout.width(10); std::cout << std::right << "Index";
	cyan("|", 0);
	std::cout.width(10); std::cout << std::right << "First name";
	cyan("|", 0);
	std::cout.width(10); std::cout << std::right << "Last name";
	cyan("|", 0);
	std::cout.width(10); std::cout << std::right << "Nickname";
	std::cout << std::endl;
	cyan("-------------------------------------------", 1);

	for (size_t i = 0; i < size; i++) {
		display_contact(contacts[i], i);
		if (i + 1 < size)
			cyan("-------------------------------------------", 1);
		else
			cyan("===========================================", 1);
	}
	std::cout << std::endl;
};

void	PhoneBook::display_contact_info(size_t id) {
	if (id >= size) {
		yellow("A contact with id ", 0);
		std::cout << id;
		yellow(" doesn't exist", 1);
		return ;
	}
	cyan("First name: ", 0); std::cout << contacts[id].first_name << std::endl;
	cyan("Last name: ", 0); std::cout << contacts[id].last_name << std::endl;
	cyan("Nickname: ", 0); std::cout << contacts[id].nick_name << std::endl;
	cyan("Phone number: ", 0); std::cout << contacts[id].phone << std::endl;
	cyan("Darkest secret: ", 0); std::cout << contacts[id].secret << std::endl;
}
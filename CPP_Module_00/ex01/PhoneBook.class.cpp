#include "PhoneBook.class.hpp"
#include <iostream>
#include <sstream>

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
		if (oldest + 1 == CAP)
			oldest = 0;
		else
			oldest++;
	}
};

// Contact	PhoneBook::get(size_t id) {
// 	return (contacts[id]);
// };

static std::string	fix_string(std::string s) {
	if (s.length() > 10)
	{
		s[9] = '.';
		s = s.substr(0, 10);
	}
	else if (s.length() < 10)
	{
		for (size_t i = s.length(); i < 10; i++)
			s[i] = ' ';
	}
	return (s);
};

static void	display_contact(Contact contact, size_t i) {
	std::string s;
	std::stringstream ss;

	ss << i;
	s = fix_string(ss.str());
	std::cout << s << "|";
	s = fix_string(contact.first_name);
	std::cout << s << "|";
	s = fix_string(contact.last_name);
	std::cout << s << "|";
	s = fix_string(contact.nick_name);
	std::cout << s << std::endl;
};

void	PhoneBook::display_all_contacts(void) {
	for (size_t i = 0; i < size; i++)
		display_contact(contacts[i], i);
};

void	PhoneBook::display_contact_info(size_t id) {
	if (id >= size) {
		std::cout << "A contact with this id doesn't exist" << std::endl;
		return ;
	}
	std::cout << "First name: " << contacts[id].first_name << std::endl;
	std::cout << "Last name: " << contacts[id].last_name << std::endl;
	std::cout << "Nickname: " << contacts[id].nick_name << std::endl;
	std::cout << "Phone number: " << contacts[id].phone << std::endl;
	std::cout << "Darkest secret: " << contacts[id].secret << std::endl;
}
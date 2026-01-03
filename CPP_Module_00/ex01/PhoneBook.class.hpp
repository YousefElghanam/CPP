#ifndef __PHONEBOOK_CLASS_H__
# define __PHONEBOOK_CLASS_H__

# include "Contact.class.hpp"

# define CAP 8

class PhoneBook {
	private:
		size_t	oldest;
		Contact	contacts[CAP];

	public:
		size_t	size;

		PhoneBook(void);
		~PhoneBook(void);

		void	add(Contact contact);
		void	display_all_contacts();
		void	display_contact_info(size_t id);
};

#endif
#ifndef PHONE_BOOK_CLASS_H
# define PHONE_BOOK_CLASS_H

# include "Contact.hpp"

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

#endif /* PHONE_BOOK_CLASS_H */
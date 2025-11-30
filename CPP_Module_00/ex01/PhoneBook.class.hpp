#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

# define CAP 8

class PhoneBook {
	private:
		static const size_t	cap = CAP;
		size_t				oldest;
		Contact				contacts[CAP];

	public:
		size_t	size;

		PhoneBook(void);
		~PhoneBook(void);

		void	add(Contact contact);
		// Contact	get(size_t id);
		void	display_all_contacts();
		void	display_contact_info(size_t id);
};

#endif
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>
# include "PhoneBook.hpp"
# include "Contact.hpp"

# define RESET   "\033[0m"
# define BLACK   "\033[30m"      /* Black */
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */

/* colorize and print str, setting endl to 1 print endl at the end */
void	black(std::string str, short endl);
void	red(std::string str, short endl); 
void	green(std::string str, short endl); 
void	yellow(std::string str, short endl); 
void	blue(std::string str, short endl); 
void	magenta(std::string str, short endl); 
void	cyan(std::string str, short endl); 
void	white(std::string str, short endl);

#endif
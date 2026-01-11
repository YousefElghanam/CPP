#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed {
	private:
		int					raw;
		static const int	fractions;

	public:
		Fixed(void);
		Fixed(const int	num);
		Fixed(const float num);
		Fixed(const Fixed& obj);
		~Fixed(void);
		Fixed&  operator=(const Fixed& obj);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		// int		getFractions(void) const;
		bool	operator>(const Fixed& obj) const;
		bool	operator<(const Fixed& obj) const;
		bool	operator>=(const Fixed& obj) const;
		bool	operator<=(const Fixed& obj) const;
		bool	operator==(const Fixed& obj) const;
		bool	operator!=(const Fixed& obj) const;

		Fixed	operator+(const Fixed& obj) const;
		Fixed	operator-(const Fixed& obj) const;
		Fixed	operator*(const Fixed& obj) const;
		Fixed	operator/(const Fixed& obj) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed& fixed);

#endif /* FIXED_CLASS_HPP */

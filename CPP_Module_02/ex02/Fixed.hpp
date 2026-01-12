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
		Fixed&				operator=(const Fixed& obj);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		bool				operator>(const Fixed& obj) const;
		bool				operator<(const Fixed& obj) const;
		bool				operator>=(const Fixed& obj) const;
		bool				operator<=(const Fixed& obj) const;
		bool				operator==(const Fixed& obj) const;
		bool				operator!=(const Fixed& obj) const;

		Fixed				operator+(const Fixed& obj) const;
		Fixed				operator-(const Fixed& obj) const;
		Fixed				operator*(const Fixed& obj) const;
		Fixed				operator/(const Fixed& obj) const;

		Fixed				operator++(int x);
		Fixed				operator--(int x);
		Fixed				operator++(void);
		Fixed				operator--(void);

		static Fixed&		min(Fixed& fp1, Fixed& fp2);
		static Fixed&		max(Fixed& fp1, Fixed& fp2);
		const static Fixed&	min(const Fixed& fp1, const Fixed& fp2);
		const static Fixed&	max(const Fixed& fp1, const Fixed& fp2);
};

std::ostream& operator<<(std::ostream &os, const Fixed& fixed);

#endif /* FIXED_CLASS_HPP */

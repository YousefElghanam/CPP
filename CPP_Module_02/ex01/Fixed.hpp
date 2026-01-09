#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed {
	private:
		int		raw;
		int		fractions;

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
};

std::ostream& operator<<(std::ostream &os, Fixed fixed);

#endif /* FIXED_CLASS_HPP */

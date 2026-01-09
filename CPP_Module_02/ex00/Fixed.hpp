#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed {
	private:
		int					raw;
		static const int	fractions;

	public:
		Fixed(void);
		Fixed(const Fixed& obj);
		~Fixed(void);
		Fixed&  operator=(const Fixed& obj);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif /* FIXED_CLASS_HPP */

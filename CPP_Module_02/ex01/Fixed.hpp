#ifndef __FIXED_CLASS_H__
# define __FIXED_CLASS_H__

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

#endif /* __FIXED_CLASS_H__ */
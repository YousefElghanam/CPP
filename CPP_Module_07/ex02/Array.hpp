#ifndef ARRAY_TEMPLATE_CLASS_HPP
# define ARRAY_TEMPLATE_CLASS_HPP

template <class T>
class Array {
	private:
		T				*arr;
		unsigned int	arrLen;
	public:
		Array(void);
		~Array(void);
		explicit Array(unsigned int n);
		Array(const Array& obj);
		Array&			operator=(const Array& obj);

		T&				operator[](unsigned int i) const;
		unsigned int	size(void) const;
};

#endif /* ARRAY_TEMPLATE_CLASS_HPP */

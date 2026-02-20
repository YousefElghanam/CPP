#ifndef RPN_CLASS_HPP
# define RPN_CLASS_HPP

# include <stack>

class RPN {
	private:
		RPN(void);
		RPN(const RPN& obj);
		RPN&	operator=(const RPN& obj);

	public:
		virtual ~RPN(void) = 0;
		static int	calculate(char* input);
};

#endif /* RPN_CLASS_HPP */

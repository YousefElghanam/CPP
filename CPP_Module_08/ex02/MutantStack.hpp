#ifndef MUTANT_STACK_TEMPLATE_HPP
# define MUTANT_STACK_TEMPLATE_HPP

# include <stack>

template<class T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack<T>(void);
		MutantStack<T>(const MutantStack<T>& obj);
		MutantStack<T>&	operator=(const MutantStack<T>& obj);
		~MutantStack<T>(void);

		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator	begin(void);
		iterator	end(void);
};

# include "MutantStack.tpp"

#endif /* MUTANT_STACK_TEMPLATE_HPP */

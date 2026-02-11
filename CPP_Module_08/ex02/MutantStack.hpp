#ifndef MUTANT_STACK_TEMPLATE_HPP
# define MUTANT_STACK_TEMPLATE_HPP

# include <stack>
# include <deque>

template<class T>
class MutantStack: public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator	begin(void);
		iterator	end(void);
};

# include "MutantStack.tpp"

#endif /* MUTANT_STACK_TEMPLATE_HPP */

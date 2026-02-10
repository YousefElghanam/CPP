#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP

# include <set>
# include <exception>

# define AT_INSERTION 1

class Span {
	private:
		std::set<int>	set;
		unsigned int	cap;
		long			curShortestSpan;
		long			curLongestSpan;

		Span(void);

		void						setShortestSpan(const std::set<int>::iterator& first, const std::set<int>::reverse_iterator& last, std::set<int>::iterator num);
		void						setLongestSpan(const std::set<int>::iterator& first, const std::set<int>::reverse_iterator& last);

	public:
		~Span(void);
		Span(const Span& obj);
		Span&						operator=(const Span& obj);
		explicit Span(unsigned int cap);

		void						addNumber(int num);
		void						printContainer(void) const;
		long						shortestSpan(void) const;
		long						longestSpan(void) const;
		template <typename T>void	addNumber(T itBegin, T itEnd) {
			while (itBegin != itEnd) {
				this->addNumber(*itBegin);
				itBegin++;
			}
		}

		class NotEnoughElementsException: public std::exception {
			const char*	what(void) const throw();
		};
		class CapReachedException: public std::exception {
			const char*	what(void) const throw();
		};

};

#endif /* SPAN_CLASS_HPP */

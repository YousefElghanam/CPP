#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP

# include <set>

class Span {
	private:
		std::set<int>	set;
		unsigned int	cap;
		Span(void);
		Span&						operator=(const Span& obj);

	public:
		~Span(void);
		Span(const Span& obj);
		explicit Span(unsigned int cap);

		template <typename T>void	addNumber(T itBegin, T itEnd) {
			while (itBegin != itEnd) {
				this->addNumber(*itBegin);
				itBegin++;
			}
		}

		void						addNumber(int num);
		// template <typename T>void	addNumber(T itBegin, T itEnd);
		void						printSet(void) const;
		// void						addNumbers(std::set<int>::iterator start, std::set<int>::iterator end);
};

#endif /* SPAN_CLASS_HPP */

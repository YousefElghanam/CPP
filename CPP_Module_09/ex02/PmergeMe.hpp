#ifndef PMERGE_ME_CLASS_HPP
# define PMERGE_ME_CLASS_HPP

# include <vector>
# include <deque>

class PmergeMe {
	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe& obj);
		PmergeMe&	operator=(const PmergeMe& obj);

	public:
		virtual ~PmergeMe(void) = 0;
		static int	sort(int argc, char** argv);
};

#endif /* PMERGE_ME_CLASS_HPP */

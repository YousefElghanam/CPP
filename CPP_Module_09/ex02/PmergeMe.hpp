#ifndef PMERGE_ME_CLASS_HPP
# define PMERGE_ME_CLASS_HPP

# include <vector>
# include <deque>
# include <utility>

# include <cstddef>

class PmergeMe {
	private:
		typedef std::vector<long>		Vec;
		typedef std::pair<Vec, size_t>	Pair;

		PmergeMe(void);
		PmergeMe(const PmergeMe& obj);
		PmergeMe&	operator=(const PmergeMe& obj);

	public:
		virtual ~PmergeMe(void) = 0;
		static void	printVec(const std::vector<long>& vec);
		static void	printPairVec(const std::vector<Pair>& vec);
		static void	merge(std::vector<Pair>& PairVec, int level);
		static int	sort(size_t argc, const char** argv);
};

#endif /* PMERGE_ME_CLASS_HPP */

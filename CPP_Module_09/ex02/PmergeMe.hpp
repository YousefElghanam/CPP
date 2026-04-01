#ifndef PMERGE_ME_CLASS_HPP
# define PMERGE_ME_CLASS_HPP

# include <vector>
# include <deque>
# include <utility>

# include <cstddef>

# include <sys/types.h>

# define DEBUG 1

class PmergeMe {
	private:
		typedef std::vector<long>		Vec;
		typedef std::pair<long, size_t> MainPair;

		PmergeMe(void);
		PmergeMe(const PmergeMe& obj);
		PmergeMe&	operator=(const PmergeMe& obj);

		static void	printVec(const std::vector<long>& vec, size_t level);
		static void	printPairVec(const std::vector<MainPair>& vec, size_t level);

	public:
		virtual ~PmergeMe(void) = 0;
		static void	mergeRec(std::vector<long>& vec, size_t level);
		static int	sort(size_t argc, const char** argv);
};

#endif /* PMERGE_ME_CLASS_HPP */

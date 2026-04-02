#ifndef PMERGE_ME_CLASS_HPP
# define PMERGE_ME_CLASS_HPP

# include <vector>
# include <deque>
# include <utility>

# include <cstddef>

# include <sys/types.h>

# ifndef DEBUG
#  define DEBUG 0
# endif
# ifndef CHECK_RES
#  define CHECK_RES 1
# endif

class PmergeMe {
	private:
		typedef std::pair<long, long>	MainPair;
		typedef std::vector<long>		Vec;
		typedef std::vector<MainPair>	PairVec;
		typedef std::deque<long>		Deq;
		typedef std::deque<MainPair>	PairDeq;

		PmergeMe(void);
		PmergeMe(const PmergeMe& obj);
		PmergeMe&	operator=(const PmergeMe& obj);

		static void	printVec(const Vec& vec, size_t level);
		static void	printPairVec(const PairVec& vec, size_t level);
		static void	groupSwap(Vec& vec, size_t i, size_t elmntSize);
		static void	makeSubVecs(const Vec& vec, PairVec& main, Vec& pend,
								Vec& remainder, size_t elmntSize);
		static void	insert(PairVec& main, const Vec& pend, size_t start,
								size_t end, size_t idx, size_t elmntSize);
		static void	binaryInsert(PairVec& main, const Vec& pend, size_t idx,
								size_t elmntSize);
		static void	insertToMain(PairVec& main, const Vec& pend, size_t elmntSize,
								const std::vector<size_t>& jacobSeq);
		static void	mergeRec(Vec& vec, PairVec& main, Vec& pend, Vec& remainder,
								size_t level, const std::vector<size_t>& jacobSeq);

		static void	printDeq(const Deq& vec, size_t level);
		static void	printPairDeq(const PairDeq& vec, size_t level);
		static void	groupSwap(Deq& vec, size_t i, size_t elmntSize);
		static void	makeSubVecs(const Deq& vec, PairDeq& main, Deq& pend,
								Deq& remainder, size_t elmntSize);
		static void	insert(PairDeq& main, const Deq& pend, size_t start,
								size_t end, size_t idx, size_t elmntSize);
		static void	binaryInsert(PairDeq& main, const Deq& pend, size_t idx,
								size_t elmntSize);
		static void	insertToMain(PairDeq& main, const Deq& pend, size_t elmntSize,
								const std::vector<size_t>& jacobSeq);
		static void	mergeRec(Deq& vec, PairDeq& main, Deq& pend, Deq& remainder,
								size_t level, const std::vector<size_t>& jacobSeq);
	public:
		virtual ~PmergeMe(void) = 0;
		static int	sort(size_t argc, const char** argv);
		static int	sortButDeque(size_t argc, const char** argv);
};

#endif /* PMERGE_ME_CLASS_HPP */

#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include <string>

class Brain {
	private:
		const static unsigned int	ideasCount = 100;
		std::string					ideas[ideasCount];

	public:
		Brain(void);
		~Brain(void);
		// explicit Brain(const std::string ideas[ideasCount]);
		explicit Brain(const std::string& animalType);
		Brain(const Brain& obj);
		Brain&	operator=(const Brain& obj);

		void				setIdeas(std::string ideas[ideasCount]);
		const std::string*	getIdeas(void) const;
		const std::string&	getRandomIdea(void) const;
		unsigned int		getIdeasCount(void) const;
		void				initDogThoughts(void);
		void				initCatThoughts(void);
};

void	fillDogThoughts(Brain* brain);
void	fillCatThoughts(Brain* brain);

#endif /* BRAIN_CLASS_HPP */

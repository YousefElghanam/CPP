#ifndef MATERIA_SOURCE_CLASS_HPP
# define MATERIA_SOURCE_CLASS_HPP

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	private:
		const static unsigned int	materiaListCap;
		unsigned int				materiaListSize;
		AMateria*					materiaList[4];

	public:
		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource(const MateriaSource& obj);
		MateriaSource&		operator=(const MateriaSource& obj);
		/** will take ownership of `m` */
		void				learnMateria(AMateria* m);
		AMateria*			createMateria(const std::string& type);
};

#endif /* MATERIA_SOURCE_CLASS_HPP */

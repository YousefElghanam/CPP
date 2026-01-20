#ifndef I_MATERIA_SOURCE_CLASS_HPP
# define I_MATERIA_SOURCE_CLASS_HPP

# include <string>

class AMateria;

class IMateriaSource {
	public:
		virtual ~IMateriaSource(void) {};
		virtual void			learnMateria(AMateria*) = 0;
		virtual AMateria*		createMateria(std::string const & type) = 0;
};

#endif /* I_MATERIA_SOURCE_HPPCLASS_ */

#ifndef I_MATERIA_SOURCE_CLASS_HPP
# define I_MATERIA_SOURCE_CLASS_HPP

# include <string>

class AMateria;

class IMateriaSource
{
	public:
		IMateriaSource(void);
		virtual ~IMateriaSource(void);
		IMateriaSource(const IMateriaSource& obj);
		IMateriaSource&		operator=(const IMateriaSource& obj);
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif /* I_MATERIA_SOURCE_HPPCLASS_ */

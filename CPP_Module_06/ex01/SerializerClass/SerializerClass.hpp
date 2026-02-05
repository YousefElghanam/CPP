#ifndef SERIALIZER_CLASS_HPP
# define SERIALIZER_CLASS_HPP

# include <stdint.h>

typedef struct s_data Data;
// class Data;

class Serializer {
	private:
		Serializer(void);
		Serializer(const Serializer& obj);
		Serializer&	operator=(const Serializer& obj);
		virtual ~Serializer(void) = 0;

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif /* SERIALIZER_CLASS_HPP */

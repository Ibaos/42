#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include <typeinfo>
# include "Data.hpp"

class Serializer
{
	public:
		static	uintptr_t	serialize(Data* ptr);
		static	Data*		deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);
		~Serializer();
	
};

#endif
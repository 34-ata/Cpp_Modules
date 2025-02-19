#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &src);
		~Serializer();
		Serializer &operator=(const Serializer &src);

    public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw); 
};

#endif
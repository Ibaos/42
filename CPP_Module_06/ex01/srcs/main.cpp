/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:54:17 by bhumeau           #+#    #+#             */
/*   Updated: 2025/02/04 15:02:57 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data					data;
	uintptr_t				ptr;
	Data*					dataPtr;
	std::type_info const	*type = &typeid(data);
	std::type_info const	*typePtr = &typeid(ptr);
	std::type_info const	*typeDataPtr = &typeid(dataPtr);

	data.str1 = "Hello";
	data.n = 42;
	data.str2 = "World";

	ptr = Serializer::serialize(&data);
	dataPtr = Serializer::deserialize(ptr);
	
	std::cout << "Data: " << &data << std::endl;
	std::cout << "Type: " << type->name() << std::endl;
	std::cout << "Serialized: " << ptr << std::endl;
	std::cout << "Type: " << typePtr->name() << std::endl;
	std::cout << "Deserialized: " << dataPtr << std::endl;
	std::cout << "Type: " << typeDataPtr->name() << std::endl;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:54:17 by bhumeau           #+#    #+#             */
/*   Updated: 2025/02/07 15:52:44 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main()
{
	
	Base *ptr = generate();
	Base& ref = *generate();
	identify(ptr);
	identify(NULL);
	identify(ref);
	delete ptr;
	delete &ref;
	return (0);
}

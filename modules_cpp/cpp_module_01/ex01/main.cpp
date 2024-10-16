/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:28:42 by bhumeau           #+#    #+#             */
/*   Updated: 2024/10/14 13:33:34 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int N = 10;

	Zombie* Horde = zombieHorde(N, "Zorde");
	for (int i = 0; i < N; i++)
		Horde[i].announce();
	delete [] (Horde);
	return (0);
}

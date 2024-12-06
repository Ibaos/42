/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:26:37 by bhumeau           #+#    #+#             */
/*   Updated: 2024/10/16 11:42:48 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl	test;
	test.complain("DEBUG");
	test.complain("INFO");
	test.complain("INFO");
	test.complain("WARNING");
	test.complain("WARNING");
	test.complain("WARNING");
	test.complain("ERROR");
	test.complain("ERROR");
	test.complain("ERROR");
	test.complain("ERROR");
	Harl	new_test;
	test.complain("ERROR");
	test.complain("NO");
	test.complain("WARNING");
	test.complain("YES");
	test.complain("INFO");
	test.complain("DEBUG");
	test.complain("error");
	test.complain("");
	test.complain("INFO");
	return (0);
}
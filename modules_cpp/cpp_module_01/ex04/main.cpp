/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:59:56 by bhumeau           #+#    #+#             */
/*   Updated: 2024/10/15 19:55:20 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	std::string infilename = argv[1];
	std::string outfilename = infilename + ".replace";
	std::string	s1 = argv[2];
	std::string s2 = argv[3];
	std::string line;
	
	if (argc != 4)
		return (std::cout << "Error: need exactly 3 parameters!" << std::endl, 1);
	std::ifstream infile(infilename.c_str());
	if (!infile.is_open())
		return (std::cout << "Failed to open filename!" << std::endl, 1);
	std::ofstream outfile(outfilename.c_str());
	if (!outfile.is_open())
		return (infile.close(), std::cout << "Failed to create filename.replace!" << std::endl, 1);
	bool endl = false;
	while(infile)
	{
		int i = 0;
		std::getline(infile, line);
		if (!line.empty() && endl == true)
			outfile << std::endl;
		while (line.find(s1, i) != std::string::npos)
		{
			i = line.find(s1, i);
			line.insert(i, s2);
			line.erase(i + s2.size(), s1.size());
			i += s2.size(); 
		}
		endl = true;
		outfile << line;
		line.clear();
	}
	infile.close();
	outfile.close();
	return (0);
}

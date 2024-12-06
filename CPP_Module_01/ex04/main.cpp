/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:59:56 by bhumeau           #+#    #+#             */
/*   Updated: 2024/11/12 15:09:50 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cout << "Error: need exactly 3 parameters!" << std::endl, 1);

	std::string infilename = argv[1];
	std::string outfilename = infilename + ".replace";
	std::string	s1 = argv[2];
	std::string s2 = argv[3];
	std::string file;
	std::string line;
	int i = 0;
	
	std::ifstream infile(infilename.c_str());
	if (!infile.is_open())
		return (std::cout << "Failed to open filename!" << std::endl, 1);
	std::ofstream outfile(outfilename.c_str());
	if (!outfile.is_open())
		return (infile.close(), std::cout << "Failed to create filename.replace!" << std::endl, 1);
	while(infile)
	{
		std::getline(infile, line);
		if(!infile)
			break;
		file += line + '\n';
		line.clear();
	}
	while (file.find(s1, i) != std::string::npos)
	{
		if (s1.size() > 0)
		{
			i = file.find(s1, i);
			file.insert(i, s2);
			file.erase(i + s2.size(), s1.size());
			i += s2.size(); 
		}
		else
			i++;
	}
	outfile << file;
	infile.close();
	outfile.close();
	return (0);
}

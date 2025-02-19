#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain&);         
		Brain& operator=(const Brain&);
		~Brain();
		void	setIdea(unsigned int i, std::string new_idea);
		std::string	getIdea(unsigned int i);
    private:
		std::string ideas[100];
};

#endif
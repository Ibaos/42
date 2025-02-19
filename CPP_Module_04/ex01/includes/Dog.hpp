#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog&);         
		Dog& operator=(const Dog&);
		~Dog();
		void makeSound() const;
		void	setBrain(unsigned int i, std::string new_idea);
		Brain*	getBrain();
		std::string	getIdea(unsigned int i);
    private:
		Brain*	brain;
};

#endif
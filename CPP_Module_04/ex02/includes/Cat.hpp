#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat&);         
		Cat& operator=(const Cat&);
		~Cat();
		void makeSound() const;
		void	setBrain(unsigned int i, std::string new_idea);
		Brain*	getBrain();
		std::string	getIdea(unsigned int i);
    private:
		Brain* brain;
};

#endif
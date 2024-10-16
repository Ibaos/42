#ifndef	ZOMBIE_HPP
# define	ZOMBIE_HPP

# include <iostream>

class Zombie
{
	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();
		void	announce( void );
		void	set_name(std::string name);
	private:
		std::string	name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
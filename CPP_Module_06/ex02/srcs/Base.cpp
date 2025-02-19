#include "Base.hpp"

Base::~Base()
{
	//std::cout << "Base: Default destructor called" << std::endl;
}

Base * generate(void)
{
	srand(time(0));
	int random = rand() % 3;
	if	(random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base* p)
{
	std::cout << "Object type pointed: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	std::cout << "Object type referenced: ";

	try {
		A& testA = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)testA;
	}
	catch (...)	{}
	try {
		B& testB = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)testB;
	}
	catch (...)	{}
	try {
		C& testC = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)testC;
	}
	catch (...)	{}
}

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base	*generate()
{
	if (rand() % 3 == 0)
		return new A;
	else if (rand() % 3 == 1)
		return new B;
	else
		return new C;
}

void	identify(Base *p)
{
    std::cout <<    (dynamic_cast<A *>(p) ? "A" :
                    (dynamic_cast<B *>(p) ? "B" :
                    (dynamic_cast<C *>(p) ? "C" : "Unknown")))
                                                                << std::endl;
}

void	identify(Base &p)
{
	identify(&p);
}


int	main()
{
    srand(time(NULL));
	Base	*base = new Base();
	Base	*gen[10];

	for (int i = 0; i < 10; i++)
	{
		gen[i] = generate();
		identify(gen[i]);
	}
	for (int i = 0; i < 10; i++)
		delete gen[i];
	delete base;
}
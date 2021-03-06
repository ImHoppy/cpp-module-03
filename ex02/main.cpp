#include "FragTrap.hpp"

#include <fstream>

#define MAIN_LOG(A) std::cout << "\033[3;35m" << A << "\033[0m" << std::endl

int main()
{
	MAIN_LOG("Initialize");
	FragTrap a("Dinklebot");
	FragTrap c;
	{
		MAIN_LOG("Test inherit");
		FragTrap *d = new FragTrap("Henry");
		ClapTrap e = *d;
		e.takeDamage(1);
		FragTrap b(a);

		b.takeDamage(1000);
		b.beRepaired(1);
		delete d;
	}
	c.beRepaired(1);

	MAIN_LOG("A loosing 100 energy and C goind to die");
	{

		std::streambuf *coutBackup = std::cout.rdbuf();

		std::ofstream out;
		out.open("/dev/null");
		std::cout.rdbuf(out.rdbuf());

		for (int i = 99; i; i--)
		{
			a.attack("Bob");
			c.takeDamage(1);
		}
		std::cout.rdbuf(coutBackup);
	}

	MAIN_LOG("Test if A can still do action without energy");
	a.attack("Bob");
	a.attack("Bob");
	MAIN_LOG("Test if C can still do action when dead");
	c.highFivesGuys();
	c.beRepaired(1);
	c.takeDamage(1);
	c.takeDamage(2);
	c.highFivesGuys();
}
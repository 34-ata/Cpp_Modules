#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const ScavTrap& other);
	ScavTrap(const std::string& name);
	~ScavTrap();
public:
	ScavTrap& operator=(const ScavTrap& other);
public:
	void guardGate();
	void attack(const std::string &target);
};

#endif

#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(const FragTrap &other);
	FragTrap(const std::string &name);
	~FragTrap();
public:
	FragTrap &operator=(const FragTrap &other);
public:
	void highFivesGuys(void);
};

# endif

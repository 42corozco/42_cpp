#include "ClapTrap.hpp"

/*------Canonical form--------*/
ClapTrap::ClapTrap()
{
	this->_hit = 0;
	this->_maxHit = 0;
	this->_energy = 0;
	this->_maxEnergy = 0;
	this->_level = 1;
	this->_name = "Cl4P-TP";
	this->_meleeDmg = 0;
	this->_rangedDmg = 0;
	this->_armorDmg = 0;
	std::cout << "Contructeur pere!!!!!" << std::endl;
};

ClapTrap::ClapTrap( std::string name )
{
	this->_hit = 0;
	this->_maxHit = 0;
	this->_energy = 0;
	this->_maxEnergy = 0;
	this->_level = 1;
	this->_name = name;
	this->_meleeDmg = 0;
	this->_rangedDmg = 0;
	this->_armorDmg = 0;
	std::cout << "Contructeur pere!!!!!" << std::endl;
};

ClapTrap::ClapTrap( ClapTrap const & obj)
{
	*this = obj;
};

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor: \"ClapTrap\"" << std::endl;
};

ClapTrap &	ClapTrap::operator=( ClapTrap const & rhs)
{
	this->_hit = rhs._hit;
	this->_maxHit = rhs._maxHit;
	this->_energy = rhs._energy;
	this->_maxEnergy = rhs._maxEnergy;
	this->_level = rhs._level;
	this->_name = rhs._name;
	this->_meleeDmg = rhs._meleeDmg;
	this->_rangedDmg = rhs._rangedDmg;
	this->_armorDmg = rhs._armorDmg;
	return *this;
}

/*----------functions----------*/
void	ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << this->_name << " attacks "
		<< target << " at range, causing " << this->_rangedDmg
		<< " points of damage!" << std::endl;
};

void	ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << this->_name << " attacks "
		<< target << " at melee, causing " << this->_meleeDmg
		<< " points of damage!" << std::endl;
};

void	ClapTrap::takeDAmage(unsigned int amount)
{
	int		res;

	amount = ((int)amount - (int)this->_armorDmg > 0) ? amount - this->_armorDmg : 0;
	if ((int)this->_hit - (int)amount < 1)
	{
		res = (int)this->_maxHit - ((int)this->_maxHit - (int)this->_hit);
		std::cout << "(i) " << this->_name << " did take " << res << " of dmg!" << std::endl;
		/* Braveheart (1995) */
		std::cout << this->_name << " Freedooooooooooom!" << std::endl;
		this->_hit = 0;
	}
	else
	{
		this->_hit -= amount;
		std::cout << "(i) " << this->_name << " did take " << amount << " of dmg!" << std::endl;
		std::cout << this->_name << " it doesn't hurt, I'm groot" << std::endl;
	}
	std::cout << "(i) " << this->_name << " life points : " << this->_hit << std::endl;
};

void	ClapTrap::beRepaired(unsigned int amount)
{
	int		res;

	if (this->_hit + amount > this->_maxHit)
		res = (int)this->_maxHit - (int)this->_hit;
	else
		res = (int)amount;
	std::cout << this->_name << " + " << res << " life points" << std::endl;
	this->_hit += res;
	std::cout << "(i) " << this->_name << " life points : " << this->_hit << std::endl;
};

/*-------getters----------*/
std::string	ClapTrap::getName(void) const
{
	return ( this->_name );
};

unsigned int	ClapTrap::getMeleeDmg(void) const
{
	return ( this->_meleeDmg );
};

unsigned int	ClapTrap::getRangedDmg(void) const
{
	return ( this->_rangedDmg );
};


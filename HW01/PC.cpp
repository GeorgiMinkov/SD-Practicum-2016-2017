#include "stdafx.h"
#include "PC.h"

void PC::copy(size_t core, float ram)
{
	this->core = core;
	this->ram = ram;
}

PC::PC() : Stock()
{
	this->core = 0;
	this->ram = 0.0f;
}

PC::PC(Type type, long inventoryNumber, std::string brand, std::string model, float price, size_t core, float ram)
	: Stock(type, inventoryNumber, brand, model, price)
{
	this->copy(core, ram);
}

PC::PC(const PC & other) : Stock(other)
{
	this->copy(other.core, other.ram);
}

PC & PC::operator=(const PC & other)
{
	// DO: operator=
	if (this != &other)
	{
		Stock::operator=(other);

		this->copy(other.core, other.ram);
	}

	return *this;
}

void PC::setCore(const size_t & core)
{
	this->core = core;

}

void PC::setRam(const float & ram)
{
	this->ram = ram;
}

size_t PC::getCore() const
{
	return this->core;
}

float PC::getRam() const
{
	return this->ram;
}

std::ostream & operator<<(std::ostream & out, const PC & source)
{
	// DO: out stream

	// ако не стане така със гетъри
	out << Stock(source) << " " << source.core << " " << source.ram;

	return out;
}

std::istream & operator>>(std::istream & in, PC & source)
{
	// DO: in stream
	Type tmpType = E;
	char tmpTypeChar = 'E';
	long tmpNumber = 0;
	std::string tmpBrand, tmpModel;
	float tmpPrice = 0.0f;

	in >> tmpTypeChar >> tmpNumber >> tmpBrand >> tmpModel >> tmpPrice >> source.core >> source.ram;

	tmpType = getType(tmpTypeChar);

	source.setType(tmpType);
	source.setInventoryNumber(tmpNumber);
	source.setBrand(tmpBrand);
	source.setModel(tmpModel);
	source.setPrice(tmpPrice);

	return in;
}

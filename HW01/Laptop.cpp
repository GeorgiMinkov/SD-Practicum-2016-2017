#include "stdafx.h"
#include "Laptop.h"

void Laptop::copy(float diagonal, float hours)
{
	this->diagonal = diagonal;
	this->hours = hours;
}

Laptop::Laptop() : PC()
{
	this->diagonal = 0.0f;
	this->hours = 0.0f;
}

Laptop::Laptop(Type type, long inventoryNumber, std::string brand, std::string model, float price, size_t core, float ram, float diagonal, float hours)
	: PC(type, inventoryNumber, brand, model, price, core, ram)
{
	this->copy(diagonal, hours);
}

Laptop::Laptop(const Laptop & other) : PC(other)
{
	this->copy(other.diagonal, other.hours);
}

Laptop & Laptop::operator=(const Laptop & other)
{
	// DO: operator=
	if (this != &other)
	{
		PC::operator=(other);

		this->copy(other.diagonal, other.hours);
	}

	return *this;
}

void Laptop::setDiagonal(const float & diagonal)
{
	this->diagonal = diagonal;
}

void Laptop::setHours(const float & hours)
{
	this->hours = hours;
}

float Laptop::getDiagonal() const
{
	return this->diagonal;
}

float Laptop::getHours() const
{
	return this->hours;
}

std::istream & operator>>(std::istream & in, Laptop & source)
{
	// DO: in stream
	Type tmpType = E;
	char tmpTypeChar = 'E';
	long tmpNumber = 0;
	std::string tmpBrand, tmpModel;
	float tmpPrice = 0.0f, tmpRam = 0.0f;
	size_t tmpCore = 0;

	in >> tmpTypeChar >> tmpNumber >> tmpBrand >> tmpModel >> tmpPrice >> tmpCore >> tmpRam >> source.diagonal >> source.hours;

	tmpType = getType(tmpTypeChar);

	source.setType(tmpType);
	source.setInventoryNumber(tmpNumber);
	source.setBrand(tmpBrand);
	source.setModel(tmpModel);
	source.setPrice(tmpPrice);
	source.setCore(tmpCore);
	source.setRam(tmpRam);

	return in;
}

std::ostream & operator<<(std::ostream & out, const Laptop source)
{
	// DO: out stream
	out << PC(source) << " " << source.diagonal << " " << source.hours;

	return out;
}

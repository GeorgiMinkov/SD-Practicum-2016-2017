#include "stdafx.h"
#include "Smartphone.h"

void Smartphone::copy(float rearCamera, float frontCamera, size_t numSIM)
{
	this->rearCamera = rearCamera;
	this->frontCamera = frontCamera;
	this->numSIM = numSIM;
}

Smartphone::Smartphone() : Laptop()
{
	this->rearCamera = 0.0f;
	this->frontCamera = 0.0f;
	this->numSIM = 0;
}

Smartphone::Smartphone(Type type, long inventoryNumber, std::string brand, std::string model, float price, size_t core, float ram, float diagonal, float hours, float rearCamera, float frontCamera, size_t numSIM)
	: Laptop(type, inventoryNumber, brand, model, price, core, ram, diagonal, hours)
{
	this->copy(rearCamera, frontCamera, numSIM);
}

Smartphone::Smartphone(const Smartphone & other) : Laptop(other)
{
	this->copy(other.rearCamera, other.frontCamera, other.numSIM);
}

Smartphone & Smartphone::operator=(const Smartphone & other)
{
	// DO: operator=

	if (this != &other)
	{
		Laptop::operator=(other);

		this->copy(other.rearCamera, other.frontCamera, other.numSIM);
	}

	return *this;
}

void Smartphone::setRearCamera(const float & rearCamera)
{
	this->rearCamera = rearCamera;
}

void Smartphone::setFrontCamera(const float & frontCamera)
{
	this->frontCamera = frontCamera;
}

void Smartphone::setNumSIM(const size_t & numSIM)
{
	this->numSIM = numSIM;
}

float Smartphone::getRearCamera() const
{
	return this->rearCamera;
}

float Smartphone::getFrontCamera() const
{
	return this->frontCamera;
}

size_t Smartphone::getNumSIM() const
{
	return this->numSIM;
}

std::istream & operator>>(std::istream & in, Smartphone & source)
{
	// DO: in stream
	Type tmpType = E;
	char tmpTypeChar = 'E';
	long tmpNumber = 0;
	std::string tmpBrand, tmpModel;
	float tmpPrice = 0.0f, tmpDiagonal = 0.0f, tmpHours = 0.0f, tmpRam = 0.0f;
	size_t tmpCore = 0;

	in >> tmpTypeChar >> tmpNumber >> tmpBrand >> tmpModel >> tmpPrice >> tmpCore >> tmpRam >> tmpDiagonal >> tmpHours >> source.rearCamera >> source.frontCamera >> source.numSIM;

	tmpType = getType(tmpTypeChar);

	source.setType(tmpType);
	source.setInventoryNumber(tmpNumber);
	source.setBrand(tmpBrand);
	source.setModel(tmpModel);
	source.setPrice(tmpPrice);
	source.setCore(tmpCore);
	source.setRam(tmpRam);
	source.setDiagonal(tmpDiagonal);
	source.setHours(tmpHours);

	return in;
}

std::ostream & operator<<(std::ostream & out, const Smartphone & source)
{
	// DO: out stream

	out << Laptop(source) << " " << source.frontCamera << " " << source.rearCamera << " " << source.numSIM;

	return out;
}

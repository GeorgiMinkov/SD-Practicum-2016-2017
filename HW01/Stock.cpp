#include "stdafx.h"
#include "Stock.h"

void Stock::copy(Type type, long inventoryNumber, std::string brand, std::string model, float price)
{
	this->type = type;
	this->inventoryNumber = inventoryNumber;
	this->brand = brand;
	this->model = model;
	this->price = price;

}

Stock::Stock()
{
	this->copy(E, 0, "", "", 0.0f);
}

Stock::Stock(Type type, long inventoryNumber, std::string brand, std::string model, float price)
{
	this->copy(type, inventoryNumber, brand, model, price);
}

Stock::Stock(const Stock & other)
{
	this->copy(other.type, other.inventoryNumber, other.brand, other.model, other.price);
}

Stock & Stock::operator=(const Stock & other)
{
	// DO: operator =
	if (this != &other)
	{
		this->copy(other.type, other.inventoryNumber, other.brand, other.model, other.price);
	}

	return *this;
}

Type Stock::getType() const
{
	return this->type;
}

long Stock::getInventoryNumber() const
{
	return this->inventoryNumber;
}

std::string Stock::getBrand() const
{
	return this->brand;
}

std::string Stock::getModel() const
{
	return this->model;
}

float Stock::getPrice() const
{
	return this->price;
}

void Stock::setType(const Type & type)
{
	this->type = type;
}

void Stock::setInventoryNumber(const long & inventoryNumber)
{
	this->inventoryNumber = inventoryNumber;
}

void Stock::setBrand(std::string & brand)
{
	this->brand = brand;
}

void Stock::setModel(std::string & model)
{
	this->model = model;
}

void Stock::setPrice(float & price)
{
	this->price = price;
}

std::ostream & operator<<(std::ostream & out, const Stock & source)
{
	// DO: out stream
	char charType = returnType(source.type);
	out << charType << " " << source.inventoryNumber << " " << source.brand << " " << source.model << " " << source.price;
	return out;
}

std::istream & operator>>(std::istream & in, Stock & source)
{
	// DO: in stream
	Type tmpType = E;
	char tmpTypeChar = 'E';

	in >> tmpTypeChar >> source.inventoryNumber >> source.brand >> source.model >> source.price;

	tmpType = getType(tmpTypeChar);

	source.type = tmpType;

	return in;
}

#pragma once
#include <string>
#include "HelpFunctions.h"
#include <fstream>

class Stock
{
	Type type;
	long inventoryNumber;
	std::string brand;
	std::string model;
	float price;

	void copy(Type type, long inventoryNumber, std::string brand, std::string model, float price);
public:
	Stock();
	Stock(Type type, long inventoryNumber, std::string brand, std::string model, float price);
	Stock(const Stock &other);

	Stock &operator=(const Stock &other);

	// getters
	Type getType() const;
	long getInventoryNumber() const;
	std::string getBrand() const;
	std::string getModel() const;
	float getPrice() const;

	// setters
	void setType(const Type &type);
	void setInventoryNumber(const long &inventoryNumber);
	void setBrand(std::string &brand);
	void setModel(std::string &model);
	void setPrice(float &price);

	friend std::ostream &operator<<(std::ostream &out, const Stock &source);
	friend std::istream &operator>>(std::istream &in, Stock &source);
};
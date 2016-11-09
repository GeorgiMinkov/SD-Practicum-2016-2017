#pragma once
#include "Stock.h"

class PC : public Stock
{
	size_t core;
	float ram;

	void copy(size_t core, float ram);
public:
	PC();
	PC(Type type, long inventoryNumber, std::string brand, std::string model, float price, size_t core = 0, float ram = 0.0f);
	PC(const PC &other);

	PC &operator=(const PC &other);

	// setters
	void setCore(const size_t &core);
	void setRam(const float &ram);
	// getters 
	size_t getCore() const;
	float getRam() const;

	friend std::ostream &operator<<(std::ostream &out, const PC &source);
	friend std::istream &operator>>(std::istream &in, PC &source);
};
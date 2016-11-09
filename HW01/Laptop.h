#pragma once
#include "PC.h"

class Laptop : public PC
{
	float diagonal;
	float hours;

public:
	Laptop();
	Laptop(Type type, long inventoryNumber, std::string brand, std::string model, float price, size_t core, float ram,
		float diagonal = 0.0f, float hours = 0.0f);
	Laptop(const Laptop &other);

	Laptop &operator=(const Laptop &other);

	// setters
	void setDiagonal(const float &diagonal);
	void setHours(const float &hours);
	// getters
	float getDiagonal() const;
	float getHours() const;

	friend std::istream &operator>>(std::istream &in, Laptop &source);
	friend std::ostream &operator<<(std::ostream &out, const Laptop source);
};
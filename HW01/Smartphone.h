#pragma once
#include "Laptop.h"

class Smartphone : public Laptop
{
	float rearCamera;
	float frontCamera;
	size_t numSIM;

	void copy(float rearCamera, float frontCamera, size_t numSIM);
public:
	Smartphone();
	Smartphone(Type type, long inventoryNumber, std::string brand, std::string model, float price, size_t core, float ram,
		float diagonal, float hours, float rearCamera, float frontCamera, size_t numSIM);
	Smartphone(const Smartphone &other);

	Smartphone &operator=(const Smartphone &other);

	// setters
	void setRearCamera(const float &rearCamera);
	void setFrontCamera(const float &frontCamera);
	void setNumSIM(const size_t &numSIM);
	// getters
	float getRearCamera() const;
	float getFrontCamera() const;
	size_t getNumSIM() const;

	friend std::istream &operator>>(std::istream &in, Smartphone &source);
	friend std::ostream &operator<<(std::ostream &out, const Smartphone &source);
};
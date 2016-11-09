#pragma once
#include "Smartphone.h"
#include "HelpFunctions.h"

void requestByType(const Type &type, const std::string fileName);

void requsetByBrand(const std::string &brand, const std::string fileName);

void requestByModelAndBrand(const std::string &brand, const std::string &model, const std::string fileName);

void requestByPrice(const Type & type, const float &price, const std::string fileName);

void requestByPriceAndMark(const Type & type, const std::string &brand, float &price, const std::string fileName);
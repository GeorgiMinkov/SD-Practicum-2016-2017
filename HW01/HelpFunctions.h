#pragma once
#include <string>
#include "Type.h"

bool checkFileExist(const std::string &fileName);

Type getType(char tmpType);

char returnType(const Type &tmpType);
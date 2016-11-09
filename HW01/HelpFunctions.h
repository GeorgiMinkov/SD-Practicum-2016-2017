#pragma once
#include <string>
#include "Type.h"

// check if the file exist
bool checkFileExist(const std::string &fileName);

// return enum Type from char
Type getType(const char &tmpType);

// return char from enum Type
char returnType(const Type &tmpType);
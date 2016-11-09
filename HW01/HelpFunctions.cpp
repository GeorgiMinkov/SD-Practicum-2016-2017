#include "stdafx.h"
#include "HelpFunctions.h"

bool checkFileExist(const std::string &fileName)
{
	struct stat buffer;
	return (stat(fileName.c_str(), &buffer) == 0);
}

Type getType(const char &tmpType)
{
	switch (tmpType)
	{
	case 'P': return P;
	case 'L': return L;
	case 'S': return S;
	default: return E;
	}
}

char returnType(const Type & tmpType)
{
	switch (tmpType)
	{
	case P: return 'P';
	case L: return 'L';
	case S: return 'S';
	default: return 'E';
	}
}

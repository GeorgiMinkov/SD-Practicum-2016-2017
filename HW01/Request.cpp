#include "stdafx.h"
#include "Request.h"

void requestByType(const Type &type, const std::string fileName)
{
	if (!checkFileExist(fileName))
	{
		throw "FileExistanceExseption";
	}
	else
	{
		std::ifstream fi(fileName.c_str(), std::ios::in);

		if (!fi.is_open())
		{
			throw "FileOpenExseption";
		}
		else
		{
			Type tmpType = E;
			char tmpTypeChar = 'E';

			std::string line = "", fileOutputName = __FUNCTION__;
			fileOutputName += ".txt";

			if (checkFileExist(fileOutputName))
			{
				std::ifstream fiTMP(fileOutputName.c_str(), std::ios::in);
				fiTMP >> tmpTypeChar;
				// fiTMP.seekg(std::ios::beg);

				tmpType = getType(tmpTypeChar);

				if (tmpType == type)
				{
					fiTMP.close();
					return;
				}
				else
				{
					fiTMP.close();
				}
			}

			std::ofstream fo(fileOutputName, std::ios::out | std::ios::trunc);
			if (!fo.is_open())
			{
				throw "FileToWriteExseption";
			}
			else
			{

				while (!fi.eof())
				{
					// взимам типа и създава указател към него
					fi >> tmpTypeChar;
					fi.seekg(-1, std::ios::cur);

					tmpType = getType(tmpTypeChar);

					switch (tmpType)
					{

					case P:
					{
						PC tmp;
						// пълня обекта
						fi >> tmp;

						// проверявам дали е от необходимия тип
						if (tmp.getType() == tmpType)
						{
							fo << tmp << std::endl;
						}break;
					}
					case L:
					{
						Laptop tmp;
						// пълня обекта
						fi >> tmp;

						// проверявам дали е от необходимия тип
						if (tmp.getType() == tmpType)
						{
							fo << tmp << std::endl;
						}break;
					}
					case S:
					{
						Smartphone tmp;
						// пълня обекта
						fi >> tmp;

						// проверявам дали е от необходимия тип
						if (tmp.getType() == tmpType)
						{
							fo << tmp << std::endl;
						}break;
					}
					}
				}

				fo.close();
				fi.close();
			}
		}
	}
}

void requestByModelAndBrand(const std::string &brand, const std::string &model, const std::string fileName)
{

}

void requestByPrice(const Type & type, const float &price, const std::string fileName)
{

}

void requestByPriceAndMark(const Type & type, const std::string &brand, float &price, const std::string fileName)
{

}
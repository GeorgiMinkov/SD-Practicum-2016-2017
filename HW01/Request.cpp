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
						if (tmp.getType() == type)
						{
							fo << tmp << std::endl;
						}	break;
					}
					case L:
					{
						Laptop tmp;
						// пълня обекта
						fi >> tmp;

						// проверявам дали е от необходимия тип
						if (tmp.getType() == type)
						{
							fo << tmp << std::endl;
						}	break;
					}
					case S:
					{
						Smartphone tmp;
						// пълня обекта
						fi >> tmp;

						// проверявам дали е от необходимия тип
						if (tmp.getType() == type)
						{
							fo << tmp << std::endl;
						}	break;
					}
					default : if (fi.eof()) break;
					}
				}

				fo.close();
				fi.close();
			}
		}
	}
}

void requsetByBrand(const std::string & brand, const std::string fileName)
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

			std::string fileOutputName = __FUNCTION__;
			fileOutputName += ".txt";

			if (checkFileExist(fileOutputName))
			{
				std::ifstream fiTMP(fileOutputName.c_str(), std::ios::in);
				fiTMP >> tmpTypeChar;

				tmpType = getType(tmpTypeChar);
				switch (tmpType)
				{
				case P:
				{
					PC tmp;
					fiTMP >> tmp;

					if (brand == tmp.getBrand())
					{
						fiTMP.close();
						return;
					}
					else
					{
						fiTMP.close();
					}
				}
				case L:
				{
					Laptop tmp;
					fiTMP >> tmp;

					if (brand == tmp.getBrand())
					{
						fiTMP.close();
						return;
					}
					else
					{
						fiTMP.close();
					}
				}
				case S:
				{
					Smartphone tmp;
					fiTMP >> tmp;

					if (brand == tmp.getBrand())
					{
						fiTMP.close();
						return;
					}
					else
					{
						fiTMP.close();
					}
				}
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
					// взимам типа 
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

						// проверявам дали е от необходимия тип търсене
						if (brand == tmp.getBrand())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case L:
					{
						Laptop tmp;
						// пълня обекта
						fi >> tmp;

						// проверявам дали е от необходимия тип търсене
						if (brand == tmp.getBrand())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case S:
					{
						Smartphone tmp;
						// пълня обекта
						fi >> tmp;

						// проверявам дали е от необходимия тип
						if (brand == tmp.getBrand())
						{
							fo << tmp << std::endl;
						}	break;
					}
					default: if (fi.eof()) break;
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

			std::string fileOutputName = __FUNCTION__;
			fileOutputName += ".txt";

			if (checkFileExist(fileOutputName))
			{
				std::ifstream fiTMP(fileOutputName.c_str(), std::ios::in);
				fiTMP >> tmpTypeChar;

				tmpType = getType(tmpTypeChar);
				switch (tmpType)
				{
				case P:
				{
					PC tmp;
					fiTMP >> tmp;

					if (brand == tmp.getBrand() && model == tmp.getModel())
					{
						fiTMP.close();
						return;
					}
					else
					{
						fiTMP.close();
					}
				}
				case L:
				{
					Laptop tmp;
					fiTMP >> tmp;

					if (brand == tmp.getBrand() && model == tmp.getModel())
					{
						fiTMP.close();
						return;
					}
					else
					{
						fiTMP.close();
					}
				}
				case S:
				{
					Smartphone tmp;
					fiTMP >> tmp;
					
					if (brand == tmp.getBrand() && model == tmp.getModel())
					{
						fiTMP.close(); 
						return;
					}
					else
					{
						fiTMP.close();
					}
				}
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
					// взимам типа 
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

						// проверявам дали е от необходимия тип търсене
						if (brand == tmp.getBrand() && model == tmp.getModel())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case L:
					{
						Laptop tmp;
						// пълня обекта
						fi >> tmp;

						// проверявам дали е от необходимия тип търсене
						if (brand == tmp.getBrand() && model == tmp.getModel())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case S:
					{
						Smartphone tmp;
						// пълня обекта
						fi >> tmp;

						// проверявам дали е от необходимия тип
						if (brand == tmp.getBrand() && model == tmp.getModel())
						{
							fo << tmp << std::endl;
						}	break;
					}
					default: if (fi.eof()) break;
					}
				}

				fo.close();
				fi.close();
			}
		}
	}
}

void requestByPrice(const Type & type, const float &price, const std::string fileName)
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

			std::string fileOutputName = __FUNCTION__;
			fileOutputName += ".txt";

			std::string fileOutputNameInValue = __FUNCTION__;
			fileOutputNameInValue += "InValue.txt";

			if (checkFileExist(fileOutputNameInValue))
			{
				std::ifstream fiTmp(fileOutputNameInValue, std::ios::in);

				float tmpPrice = 0.0f;

				fiTmp >> tmpTypeChar >> tmpPrice;

				tmpType = getType(tmpTypeChar);

				if (tmpType == type && tmpPrice == price)
				{
					fiTmp.close();
					return;
				}
				else
				{
					fiTmp.close();
				}
			}

			std::ofstream foTmp(fileOutputNameInValue.c_str(), std::ios::out | std::ios::trunc);
			foTmp << returnType(type) << " " << price;
			foTmp.close();

			std::ofstream fo(fileOutputName.c_str(), std::ios::out | std::ios::trunc);
			if (!fo.is_open())
			{
				throw "FileToWriteExseption";
			}
			else
			{

				while (!fi.eof())
				{
					// взимам типа 
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

						// проверявам дали е от необходимия тип търсене
						if (type == tmp.getType() && price >= tmp.getPrice())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case L:
					{
						Laptop tmp;
						// пълня обекта
						fi >> tmp;

						// проверявам дали е от необходимия тип търсене
						if (type == tmp.getType() && price >= tmp.getPrice())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case S:
					{
						Smartphone tmp;
						// пълня обекта
						fi >> tmp;

						// проверявам дали е от необходимия тип
						if (type == tmp.getType() && price >= tmp.getPrice())
						{
							fo << tmp << std::endl;
						}	break;
					}
					default: if (fi.eof()) break;
					}
				}

				fo.close();
				fi.close();
			}
		}
	}
}

void requestByPriceAndBrand(const Type & type, const std::string &brand, const float &price, const std::string fileName)
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

			std::string fileOutputName = __FUNCTION__;
			fileOutputName += ".txt";

			std::string fileOutputNameInValue = __FUNCTION__;
			fileOutputNameInValue += "InValue.txt";

			if (checkFileExist(fileOutputNameInValue))
			{
				std::ifstream fiTmp(fileOutputNameInValue.c_str(), std::ios::in);

				std::string tmpBrand = "";
				float tmpPrice = 0.0f;

				fiTmp >> tmpTypeChar >> tmpBrand >> tmpPrice;

				tmpType = getType(tmpTypeChar);

				if (tmpType == type && tmpPrice == price && tmpBrand == brand)
				{
					fiTmp.close();
					return;
				}
				else
				{
					fiTmp.close();
				}
			}

			std::ofstream foTmp(fileOutputNameInValue.c_str(), std::ios::out | std::ios::trunc);
			foTmp << returnType(type) << " " << brand << " "<< price;
			foTmp.close();

			std::ofstream fo(fileOutputName.c_str(), std::ios::out | std::ios::trunc);
			if (!fo.is_open())
			{
				throw "FileToWriteExseption";
			}
			else
			{

				while (!fi.eof())
				{
					// взимам типа 
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

						// проверявам дали е от необходимия тип търсене
						if (type == tmp.getType() && price >= tmp.getPrice() && brand == tmp.getBrand())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case L:
					{
						Laptop tmp;
						// пълня обекта
						fi >> tmp;

						// проверявам дали е от необходимия тип търсене
						if (type == tmp.getType() && price >= tmp.getPrice() && brand == tmp.getBrand())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case S:
					{
						Smartphone tmp;
						// пълня обекта
						fi >> tmp;

						// проверявам дали е от необходимия тип
						if (type == tmp.getType() && price >= tmp.getPrice() && brand == tmp.getBrand())
						{
							fo << tmp << std::endl;
						}	break;
					}
					default: if (fi.eof()) break;
					}
				}

				fo.close();
				fi.close();
			}
		}
	}
}
#include "stdafx.h"
#include "Request.h"

// In every request we check some equals condition: if file we want to read from, exist in directory, if it is open.
// We have check if there is already output file request then we check for infile equality and if it is not equal we delete file and write over it, to
// save condition from task.

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

			std::string line = "", fileOutputName = __FUNCTION__; // file name with the name of the current function
			fileOutputName += ".txt";

			if (checkFileExist(fileOutputName))
			{
				std::ifstream fiTMP(fileOutputName.c_str(), std::ios::in);
				fiTMP >> tmpTypeChar;

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
					// take type and create needed arguments
					fi >> tmpTypeChar;
					fi.seekg(-1, std::ios::cur);

					tmpType = getType(tmpTypeChar);

					switch (tmpType)
					{

					case P:
					{
						PC tmp;
						// full object from file
						fi >> tmp;

						// check condition
						if (tmp.getType() == type)
						{
							fo << tmp << std::endl;
						}	break;
					}
					case L:
					{
						Laptop tmp;
						// full object from file
						fi >> tmp;

						// check condition
						if (tmp.getType() == type)
						{
							fo << tmp << std::endl;
						}	break;
					}
					case S:
					{
						Smartphone tmp;
						// full object from file
						fi >> tmp;

						// check condition
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
					// read type
					fi >> tmpTypeChar;
					fi.seekg(-1, std::ios::cur);

					tmpType = getType(tmpTypeChar);

					switch (tmpType)
					{

					case P:
					{
						PC tmp;
						// full object from file
						fi >> tmp;

						// check condition
						if (brand == tmp.getBrand())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case L:
					{
						Laptop tmp;
						// full object from file
						fi >> tmp;

						// check condition
						if (brand == tmp.getBrand())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case S:
					{
						Smartphone tmp;
						// full object from file
						fi >> tmp;

						// check condition
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
					// read type
					fi >> tmpTypeChar;
					fi.seekg(-1, std::ios::cur);

					tmpType = getType(tmpTypeChar);

					switch (tmpType)
					{

					case P:
					{
						PC tmp;
						// fill object
						fi >> tmp;

						// check condition
						if (brand == tmp.getBrand() && model == tmp.getModel())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case L:
					{
						Laptop tmp;
						// fill object
						fi >> tmp;

						// check condition
						if (brand == tmp.getBrand() && model == tmp.getModel())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case S:
					{
						Smartphone tmp;
						// fill object
						fi >> tmp;

						// check condition
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
					// read type
					fi >> tmpTypeChar;
					fi.seekg(-1, std::ios::cur);

					tmpType = getType(tmpTypeChar);

					switch (tmpType)
					{

					case P:
					{
						PC tmp;
						// fill object
						fi >> tmp;

						// check condition
						if (type == tmp.getType() && price >= tmp.getPrice())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case L:
					{
						Laptop tmp;
						// fill object
						fi >> tmp;

						// check condition
						if (type == tmp.getType() && price >= tmp.getPrice())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case S:
					{
						Smartphone tmp;
						// fill object
						fi >> tmp;

						// check condition
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
					// read type
					fi >> tmpTypeChar;
					fi.seekg(-1, std::ios::cur);

					tmpType = getType(tmpTypeChar);

					switch (tmpType)
					{

					case P:
					{
						PC tmp;
						// fill object
						fi >> tmp;

						// check condition
						if (type == tmp.getType() && price >= tmp.getPrice() && brand == tmp.getBrand())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case L:
					{
						Laptop tmp;
						// fill object
						fi >> tmp;

						// check condition
						if (type == tmp.getType() && price >= tmp.getPrice() && brand == tmp.getBrand())
						{
							fo << tmp << std::endl;
						}	break;
					}
					case S:
					{
						Smartphone tmp;
						// fill object
						fi >> tmp;

						// check condition
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

void draw()
{
	system("CLS");
	std::cout << "Command    | Request\n";
	std::cout << std::setw(4) << "0" << std::setw(14) << "| Exit\n";
	std::cout << std::setw(4) << "1" << std::setw(17) << "| By type\n";
	std::cout << std::setw(4) << "2" << std::setw(18) << "| By brand\n";
	std::cout << std::setw(4) << "3" << std::setw(28) << "| By model and brand\n";
	std::cout << std::setw(4) << "4" << std::setw(27) << "| By type and price\n";
	std::cout << std::setw(4) << "5" << std::setw(34) << "| By type, brand and price\n";
}

short getCommand()
{
	draw();

	short command = 0;
	std::string fileName = "file.txt";

	std::cout << "\nEnter command: ";
	std::cin >> command;

	switch (command)
	{
	case 1:
	{
		char input = ' ';
		do
		{
			std::cout << "Enter type: P, L, S -> ";
			std::cin >> input;
		} while (input != 'P' && input != 'L' && input != 'S');

		requestByType(getType(input), fileName);
	}break;
	case 2: 
	{
		std::string brand = "";

		std::cout << "Enter brand -> ";
		std::cin >> brand;

		requsetByBrand(brand, fileName);
	}break;
	case 3:
	{
		std::string brand = "", model = "";

		std::cout << "Enter brand -> ";
		std::cin >> brand;

		std::cout << "Enter model -> ";
		std::cin >> model;

		requestByModelAndBrand(brand, model, fileName);
	}break;
	case 4:
	{
		char input = ' ';
		float price = 0.0f;

		do
		{
			std::cout << "Enter type: P, L, S -> ";
			std::cin >> input;
		} while (input != 'P' && input != 'L' && input != 'S');

		do
		{
			std::cout << "Enter price(>=0) -> ";
			std::cin >> price;
		} while (price < 0);

		requestByPrice(getType(input), price, fileName);
	}break;
	case 5:
	{
		char input = ' ';
		float price = 0.0f;
		std::string brand = "";

		do
		{
			std::cout << "Enter type: P, L, S -> ";
			std::cin >> input;
		} while (input != 'P' && input != 'L' && input != 'S');

		std::cout << "Enter brand -> ";
		std::cin >> brand;

		do
		{
			std::cout << "Enter price(>=0) -> ";
			std::cin >> price;
		} while (price < 0);

		requestByPriceAndBrand(getType(input), brand, price, fileName);
	}break;
	}

	std::cout << "Proccesing: ";
	for (size_t i = 0; i < 35; ++i)
	{
		std::cout << "|";
		Sleep(100);
	}
	std::cout << "\nReady\n";
	Sleep(500);

	return command;
}

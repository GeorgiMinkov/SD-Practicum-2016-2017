// Files.cpp : Defines the entry point for the console application.
//

#include "Stock.h"
#include <string>
#include <cmath>
#include <algorithm>

void task01();
void task02();
void makeFile();

void makeFile3(const std::string &fileName);
void task03();
bool checkConditionTask03(const int &number);

void makeFile4(const std::string &fileName);
void task04(const std::string &fileName);

void makeFile5(const std::string &fileName);
void task05(const std::string &fileName);

void task06(const std::string &fileName);
int main()
{
	std::cout << "Task01" << std::endl;
	makeFile();
	task01();

	std::cout << "\nTask02" << std::endl;
	task02();


	std::cout << "\nTask03" << std::endl;
	makeFile3("File.txt");
	task03();

	std::cout << "\nTask04" << std::endl;
	makeFile4("File4.txt");
	task04("File4.txt");

	std::cout << "\nTask05" << std::endl;
	makeFile5("File5.txt");
	task05("File5.txt");

	std::cout << "\nTask06" << std::endl;
	task06("File6.txt");
	return 0;
}

void makeFile3(const std::string & fileName)
{
	std::ofstream fo(fileName.c_str(), std::ios::out);

	int arr[] = { 11, 21, 23, 22, 45 };

	for (size_t i = 0; i < 5; ++i) fo << arr[i] << std::endl;

	fo.close();
}

void makeFile()
{
	std::ofstream fo("file.txt", std::ios::out);
	float arr[] = { 1,-33.1, 13.2, 55.8, 2.2, 1.2 };

	for (size_t index = 0; index < 6; ++index) fo << arr[index] << std::endl;

	fo.close();
}

void task01()
{
	std::ifstream fi;

	fi.open("file.txt", std::ios::in);

	float min, max;

	if (fi.is_open())
	{
		fi >> min;
		max = (min);

		while (!fi.eof())
		{
			float tmp;
			fi >> tmp;

			if (tmp < min) min = tmp;
			if (tmp > max) max = tmp;
		}
	}
	else
	{
		throw "Error open file exseption";
	}

	std::cout << "Min = " << min << "\nMax = " << max << std::endl;

	fi.close();
}



void task02()
{
	std::ifstream fi;

	fi.open("file.txt", std::ios::in);

	float min, max;

	if (fi.is_open())
	{
		fi >> min;
		min = fabs(min);
		max = fabs(min);

		while (!fi.eof())
		{
			float tmp;
			fi >> tmp;
			tmp = fabs(tmp);

			if (tmp < min) min = tmp;
			if (tmp > max) max = tmp;
		}
	}
	else
	{
		throw "Error open file exseption";
	}

	std::cout << "Min = " << min << "\nMax = " << max << std::endl;

	fi.close();
}



void task03()
{
	std::ifstream fi("File.txt", std::ios::in);

	if (fi.is_open())
	{
		std::string binary = "";
		int number;

		while (fi >> number)
		{
			if (checkConditionTask03(number))
			{
				std::cout << number << " - Not in scope\n";
				continue;
			}
			else
			{
				int tmp = number;
				while (tmp)
				{
					binary += std::to_string(tmp % 2);
					tmp /= 2;
				}
				std::reverse(binary.begin(), binary.end());
				std::cout << number << ": " << binary << std::endl;

				binary = "";
			}

		}
	}
	else
	{
		throw "FileOpenException";
	}

	fi.close();
}

bool checkConditionTask03(const int &number)
{
	return (number > 5005 || number < 15);
}

// TASK04
void makeFile4(const std::string & fileName)
{
	std::ofstream fo(fileName.c_str(), std::ios::out);

	int arr[] = { 1121, 1221, 2341, 222 };

	for (size_t i = 0; i < 4; ++i) fo << arr[i] << std::endl;

	fo.close();
}

void task04(const std::string & fileName)
{
    // std::ofstream fo(fileName.c_str(), std::ios::out | std::ios::app);
	std::ifstream fi(fileName.c_str(), std::ios::in);

	if (fi.is_open())
	{
		std::string number;
		size_t count = 0;
		while (fi >> number)
		{
			std::string tmp = number;
			std::reverse(number.begin(), number.end());

			if (number == tmp)
			{
				count++;
			}
		}

		std::cout << count << " palindromes\n";

		fi.close();
	}
	else
	{
		throw "FileOpenExeption";
		return;
	}
}

void makeFile5(const std::string & fileName)
{
	std::ofstream fo(fileName.c_str(), std::ios::out);

	float arr[] = { 1121, 1221, 2341, 222 };

	for (size_t i = 0; i < 4; ++i) fo << arr[i] << std::endl;

	fo.close();
}

void task05(const std::string & fileName)
{
	std::ifstream fi(fileName.c_str(), std::ios::in);

	if (fi.is_open())
	{
		float number, all = 0;

		while (fi >> number)
		{
			std::cout << "Stock: " << number << " DDS: " << number * 0.2 << std::endl;
			all += number + number * 0.2;
		}
		std::cout << "All: " << all << std::endl;

		fi.close();
	}
	else
	{
		throw "OpenFileExseption";
	}
}
// защо при въвеждане във файла използва ostream, a не ofstream
void task06(const std::string & fileName)
{
	std::fstream file(fileName.c_str(), std::ios::in | std::ios::out);

	if (file.is_open())
	{
        Stock element[8];

        for (size_t i = 0; i < 8; ++i)
        {
            std::cin >> element[i];
        }


        for (size_t i = 0; i < 8; ++i)
        {
            file << element[i];
        }

	}
	else
	{
		// throw "FileOpenExseption";
		std::cout << "FILE OPEN EXS" << std::endl;
	}
	file.close();
}

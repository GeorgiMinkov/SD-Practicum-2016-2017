// week06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::endl;

void task01()
{
	unsigned int number;
	float a, res = 1;

	cout << "Enter power and number:\n";
	std::cin >> number >> a;

	for (size_t i = 0; i < number; ++i)
	{
		res *= a;
	}

	cout << "Res a^n = " << res << endl;
}

void task02()
{
	bool flag = true;
	unsigned int k;

	cout << "Enter k = ";
	std::cin >> k;

	for (size_t i = 100; i <= 999; ++i)
	{
		short e = i % 10, d = i % 100 / 10, s = i / 100;

		if ((e + d + s) == k)
		{
			flag = false;
			cout << i << " ";
		}
	}

	if (flag)
	{
		cout << "No numbers\n";
	}
}

void task03()
{
	unsigned int number, count = 0;
	cout << "Number = ";
	std::cin >> number;

	char symbol;

	for (size_t index = 0; index < number; ++index)
	{
		cout << "Enter char[" << index + 1 << "] = ";
		std::cin >> symbol;

		if (symbol >= 'a' && symbol <= 'z')
		{
			count++;
		}
	}

	cout << "Count = " << count << endl;
}

void task04()
{
	int number = -1, count = 0, sum = 0;

	while (number)
	{
		cout << "Number = ";
		std::cin >> number;

		if (number % 2 == 0)
		{
			sum += number;
		}
		else
		{
			count++;
		}
	}

	cout << "Sum = " << sum << endl;
	cout << "Count = " << count << endl;
}

void task05()
{
	int number, sum = 0;
	
	do
	{
		cout << "Number = ";
		std::cin >> number;
	} while (number <= 0);

	for (size_t index = 1; index < number; ++index)
	{
		if (number % index == 0)
		{
			sum += index;
		}
	}

	cout << (sum == number ? "Perfect number" : "Not a perfect number") << endl;
}

void task06()
{
	int tmp, number, digit, reverse = 0;

	cout << "Enter number = ";
	std::cin >> number;

	tmp = number;

	do
	{
		digit = tmp % 10;
		reverse = (reverse * 10) + digit;
		tmp = tmp / 10;
	} while (tmp != 0);

	if (number == reverse)
	{
		cout << "The number is a palindrome";
	}
	else
	{
		cout << "The number is not a palindrome";
	}
}

int main()
{
//	task01();
//	task02();
//	task03();
//	task04();
//	task05();
//	task06();

	return 0;
}


// GeorgiMinkov_71600.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Request.h"

int main()
{
	SetConsoleTitle(TEXT("Homework Georgi Minkov 71600"));

	short command = -1;
	while (command != 0)
	{
		command = getCommand();
	}

    return 0;
}


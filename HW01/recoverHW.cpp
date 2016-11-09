// recoverHW.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Request.h"


int main()
{
	requestByType(S, "file.txt");
	requestByModelAndBrand("Dell", "XPS13", "file.txt");
	requsetByBrand("Huawei", "file.txt");
	requestByPrice(S, 1200, "file.txt");
	requestByPriceAndBrand(S, "Nokia", 99999.99,"file.txt");
    return 0;
}


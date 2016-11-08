#pragma once
#include <iostream>

class Stock
{
    int ID;
    char name[25];
    float price;

public:
    Stock();

    friend std::istream &operator>>(Stock &src, std::istream &in);
    friend std::ifstream &operator>>(Stock &src, std::ifstream &fi);
};

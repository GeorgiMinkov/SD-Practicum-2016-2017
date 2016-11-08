#ifndef STOCK_H
#define STOCK_H
#include <iostream>
#include <fstream>
#include <cstring>

class Stock
{
    private:
        size_t ID;
        char name[25];
        float price;


    public:
        Stock();

        friend std::istream &operator>>(std::istream &in, Stock &src);
        friend std::ifstream &operator>>(std::ifstream &fi, Stock &src);

        friend std::ostream &operator<<(std::ostream &out, const Stock &src);
        friend std::ofstream &operator<<(std::ofstream &fo, const Stock &src);

};

#endif // STOCK_H

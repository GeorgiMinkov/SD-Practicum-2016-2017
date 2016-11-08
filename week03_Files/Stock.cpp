#include "Stock.h"

Stock::Stock()
{
    //ctor
    this->ID = 0;
    std::strcpy(this->name, "");
    this->price = 0;
}

std::istream &operator>>(std::istream &in, Stock &src)
{
    std::cout << "ID = ";
    in >> src.ID;

    std::cout << "Name = ";
    in >> src.name;

    std::cout << "Price = ";
    in >> src.price;


    return in;
}


std::ifstream &operator>>(std::ifstream &in, Stock &src)
{
    in >> src.ID >> src.name >> src.price;

    return in;
}

std::ostream &operator<<(std::ostream &out, const Stock &src)
{
    out << "ID: " << src.ID << std::endl;
    out << "Name: " << src.name << std::endl;
    out << "Price: " << src.price << std::endl;

    return out;
}

std::ofstream &operator<<(std::ofstream &out, const Stock &src)
{
    out << src.ID << " " << src.name << " " << src.price << std::endl;

    return out;
}

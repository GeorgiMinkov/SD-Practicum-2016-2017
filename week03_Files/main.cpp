#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

void task01();
void task02();
void task03();
void task04();
void task05();
void makeFile(){
    ofstream fo("file.txt", ios::out);
    float arr[] = {1,-33.1, 13.2, 55.8, 2.2, 1.2};

    for (size_t index = 0; index < 6; ++index) fo << arr[index] << endl;

    fo.close();
}

void newFile()
{
     ofstream fo("fileT.txt", ios::out);
    float arr[] = {11, 21,23,22,45 };

    for (size_t index = 0; index < 6; ++index) fo << arr[index] << endl;

    fo.close();
}
int main()
{
    cout << "Hello world!" << endl;
    makeFile();
    task01();

    cout << "Hello world!" << endl;

    task02();
    return 0;
}

void task01()
{
    ifstream fi;

    fi.open("file.txt", ios::in);

    float min, max;

    if (fi.is_open())
    {
        fi >> min;
        max = (min);

        while(!fi.eof())
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

    cout << "Min = " << min << "\nMax = " << max << endl;

    fi.close();
}



void task02()
{
    ifstream fi;

    fi.open("file.txt", ios::in);

    float min, max;

    if (fi.is_open())
    {
        fi >> min;
        min = fabs(min);
        max = fabs(min);

        while(!fi.eof())
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

    cout << "Min = " << min << "\nMax = " << max << endl;

    fi.close();
}

void task03()
{
    ifstream fi("fileT.txt");

    while()
}

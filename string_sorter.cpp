#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "dynastring.hpp"
using namespace std;

vector<Dynastring> ParseFile(string fileName)
{
    vector<Dynastring> strings;
    ifstream inputFile;
    inputFile.open(fileName);
    if (inputFile.is_open())
    {
        string temp;
        while (getline(inputFile, temp))
        {
            strings.push_back(Dynastring(temp.data(), temp.length()));
        }
    }
    else {
        cout << "Could not find input file \""<< fileName << "\"" << endl;
        throw 0;
    }
    inputFile.close();
    return strings;
}

// Сортировка вектора динамических строк
void ReverseAlphanumericSort(vector<Dynastring> *linktostrings)
{
    for (int i = 1; i < (*linktostrings).size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if ((*linktostrings)[j] > (*linktostrings)[j - 1])
            {
                swap((*linktostrings)[j], (*linktostrings)[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    auto filename = "input.txt";
    if (argc > 1)
    {
        filename = argv[1];
    }
    auto strings = ParseFile(filename);
    ReverseAlphanumericSort(&strings);
    for (int i = 0; i < strings.size(); i++)
    {
        strings[i].Print();
        cout << endl;
    }
    return 0;
}
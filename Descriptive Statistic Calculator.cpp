// Descriptive Statistic Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include <iostream>
#include <string>

int main()
{
    const int MAX_SIZE = 100;
    int size = 0;
    float data[MAX_SIZE];
    string input;
    do {
        cout << "Enter data point (leave blank to stop): ";
        getline(cin, input);

        if (input.empty()) {
            break;
        }

        else {
            float value = stof(input);
            data[size] = value;
            size++;
        }
    } while (size < MAX_SIZE);


    
}


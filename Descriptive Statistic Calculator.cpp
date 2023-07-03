// Descriptive Statistic Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include <iostream>
#include <string>
#include <cmath>
void sort(double[], int); //Prototype
void printDataSet(double[], int);
void copyArray(double*, double*, int);
double calculateMean(double*, int);
double calculateMedian(double*, int);
double calculateRange(double*, int);
double calculateSampleVariance(double*, int);
double calcSampleStandardDeviation(double*, int);

int main()
{
    const int MAX_SIZE = 100;
    int size = 0;
    double data[MAX_SIZE];
    double copyData[MAX_SIZE];
    string input;
    do {
        cout << "Enter data point (leave blank to stop): ";
        getline(cin, input);

        if (input.empty()) {
            break;
        }

        else {
            double value = stod(input);
            data[size] = value;
            size++;
        }
    } while (size < MAX_SIZE);
    cout << "Original dataset: ";
    printDataSet(data, size);
    copyArray(data, copyData, size);
    sort(copyData, size);
    cout << "Sorted dataset : ";
    printDataSet(copyData, size);
    cout << "Mean: " << calculateMean(copyData, size) << endl;
    cout << "Median: " << calculateMedian(copyData, size) << endl;
    cout << "Range: " << calculateRange(copyData, size) << endl;
    cout << "Sample variance: " << calculateSampleVariance(copyData, size) << endl;
    cout << "Sample Standard Deviation: " << calcSampleStandardDeviation(copyData, size) << endl;
}
    
void printDataSet(double dataset [], int size) {
    for (int i = 0;i < size;i++) {
        double number = dataset[i];
        cout << "[" << number << "]";
    }
    cout << endl;
}

void copyArray(double* source, double* destination, int size) {
    for (int i = 0;i < size; i++) {
        destination[i] = source[i];
    }
}

void sort(double dataset[], int size) {
    for (int i = 0;i < size; i++) {
        int minIndex = i;
        for (int j = i; j < size; j++)
            if (dataset[j] < dataset[minIndex])
                minIndex = j;
        double tempValue = dataset[i];
        dataset[i] = dataset[minIndex];
        dataset[minIndex] = tempValue;
    }
}

double calculateMean(double* dataSet, int size) {
    double sum = 0;
    for (int i = 0; i< size; i++) {
        sum += dataSet[i];
    }
    return sum / size;
}

double calculateMedian(double* dataSet, int size) {
    if (size%2==1) {
        int index = size / 2;
        return dataSet[index];
    }
    else{
        double middle1 = dataSet[size / 2 - 1];
        double middle2 = dataSet[size / 2];
        return (middle1 + middle2) / 2;
    }
}
    
double calculateRange(double* dataSet, int size) {
    double maxValue = dataSet[size-1];
    double minValue = dataSet[0];
    return maxValue - minValue;
}

double calculateSampleVariance(double* dataSet, int size) {
    double sampleVariance = 0;
    double mean = calculateMean(dataSet, size);
    for (int i = 0; i < size; i++) {
        sampleVariance += pow(dataSet[i] - mean, 2) / (size - 1);
    }
    return sampleVariance;
}

double calcSampleStandardDeviation(double* dataSet, int size) {
    return sqrt(calculateSampleVariance(dataSet, size));
}

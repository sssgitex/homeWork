//#include "mylib.h"
#include <iostream>
#include <fstream>

void PrintArr(const float arr[], const int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
}

float* InitArr(const int size)
{
    float* pArr = new (std::nothrow) float[size];
    for (size_t i = 0; i < size; i++)
    {
        pArr[i] = (rand() %10 / -5.0f);
    }
    return pArr;
}
void CountArr(const float arr[], const int size, int& counter)
{
    for (size_t i = 0; i < size; i++)
    {
        (arr[i] >= 0) ? counter = counter : counter++;
    }

}

#define SWAP(a, b) int buff = a; a = b; b = buff;

void BubbleSort(int* array, const int size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if(array[j] > array[j+1])
            {
                const int num = array[j];
                SWAP(array[j], array[j + 1]);
            }
        }
    }
}

void PrintArrINT(const int arr[], const int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
}


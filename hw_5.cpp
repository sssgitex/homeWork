#include <iostream>

void dPrintArr(double * pArr,const int & size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << pArr[i];
    }
    std::cout  << "\n\n";
}

void iPrintArr(short int * pArr,const int & size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << pArr[i];
    }
    std::cout  << "\n\n";
}

void iSwap(short int * pArr,const int & size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (pArr[i] == 0)
            pArr[i] = 1;
        else if (pArr[i] == 1)
            pArr[i] = 0;
    }
    
}

void iSignArray(short int * pArr,const int & size){
    int num = 1;
    for (size_t i = 0; i < size; i++)
    {
        pArr[i] = num;
        num += 3;
    }
    
}

void arraySwap(int * pArr, const int & size, int & buffer, int & step){

    std::cout << "Enter step: ";
    std::cin >> step;

    for (size_t j = 0; j < step; j++)
    {
        int buffer = pArr[size-1]; 
        for (size_t i = (size - 1); i > 0; i--)
        {
            
            pArr[i] = pArr[i-1];
            //std::cout << arr3[i] << "\t";
        }
        pArr[0] = buffer;
    }
}

int main()
{
    /*
    //Задание 1 =============================
    const int arraySize = 11; 
    double arr[arraySize] = {0};
    arr[0] = arraySize;
    dPrintArr(arr, arraySize);
    //Задание 1 =============================

    //Задание 2 =============================
    const short arrSize = 5;
    short int arr1[arrSize] = {0, 1, 0, 0, 1};
    iPrintArr(arr1, arrSize);
    iSwap(arr1, arrSize);
    iPrintArr(arr1, arrSize);
    //Задание 2 =============================   
    
    //Задание 3 ============================= 
    const int arr1Size = 8;
    short int arr2[arr1Size] = {0};

    iSignArray(arr2, arr1Size);
    iPrintArr(arr2, arr1Size);
    //Задание 3 =============================   

    //Задание 4 ============================= 
    const int arr2Size = 6;
    int arr3[arr2Size] = {2, 3 ,4 , 5, 6, 7};
    int step = 0;
    int buffer = 0;

    for (size_t i = 0; i < arr2Size; i++)
    {
        std::cout << arr3[i];
    }
    std::cout  << "\n\n";
    
    arraySwap(arr3, arr2Size, buffer, step);

    for (size_t i = 0; i < arr2Size; i++)
    {
        std::cout << arr3[i];
    }
    std::cout  << "\n\n";
    //Задание 4 ============================= 

*/
    //Задание 5 ============================= 
    const int arr3Size = 3;
    int arr4[arr3Size] = {7, 3 ,3};
    bool res = false;
    int s1 = 0;
    int s2 = 0;

    for (size_t i = 0; i < arr3Size; i++)
    {
        s1 = 0;
        for (size_t j = i+1; j < arr3Size; j++)
        {
            //if(arr4[j] >= arr4[arr3Size]){}
            if (j < arr3Size){
                s1 += arr4[j];
            }
            
        }
        std::cout << arr4[i] <<"|"<< s1 << "\n";
        //std::cout << s1 << "\n";
        (arr4[i] == s1) ? res = 1 : res = 0;
        if (res == 1)
            break;
    }
    //std::cout << res;
    std::cout << res;

    //Задание 5 ============================= 

    return 0;
}
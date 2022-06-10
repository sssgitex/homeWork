#include "mylib.h"
#include <iostream>
#include  <fstream>

#define COMPARE(a, b) ((a >= 0 && a < b) ? "true" : "false")

void NumComp()
{
    int number;
    std::cin >> number;
    std::cout << COMPARE(number, 10) << "\n";
}

#define SIZE 5

void BUBBLE()
{   
    int* array = new (std::nothrow) int[SIZE];
    if (array != nullptr)
    {
        std::cout << "Enter " << SIZE << " numbers: " << "\n";
        for (size_t i = 0; i < SIZE; i++)
        {
            std::cin >> array[i];
        }

        BubbleSort(array, SIZE);
        PrintArrINT(array, SIZE);

        delete[] array;
    }

}

#pragma pack (push, 1)
struct Employee
{
    unsigned long long id = 0;
    char fName[255], lName[255];
    size_t age = 0;
    float salary = 0;
    short exp = 0;
};
#pragma pack(pop)

void printEmployee(const Employee* em)
{
    if (em != nullptr)
    {
        std::cout << "ID: " << em->id << "\n";
        std::cout << em->lName << " " << em->fName << ". " << em->age << "\n";
        std::cout << "Salaray: " << em->salary << "\n";
        std::cout << "Experience: " << em->exp << "year(s)\n";

        std::cout << "Size: " << sizeof(Employee) << " bytes" << "\n";
    }
}

void SaveToFile(std::string filename, const Employee* em)
{
    std::ofstream fout;

    fout.open(filename, std::ios_base::app);

    if (fout.is_open())
    {
        fout << em->id << "\n";
        fout << em->fName << "\n";
        fout << em->lName << "\n";
        fout << em->age << "\n";
        fout << em->salary << "\n";
        fout << em->exp << "\n";

        fout.close();
    }

}


void EmployeeParams()
{
    Employee* em = new (std::nothrow) Employee;

    if (em != nullptr)
    {
        em->id = 1;
        strcpy_s(em->fName, "Viktor");
        strcpy_s(em->lName, "Petrov");
        em->age = 18;
        em->salary = 10'000.00;
        em->exp = 3;

        printEmployee(em);

        SaveToFile("employee.txt", em);

        delete em;
    }
}

int main()
{
    const int size = 5;
    int minusCounter = 0;
    const float* arr = InitArr(size);
    //arr = new (std::nothrow) float[size];
    
    if (arr != nullptr) 
    {
        PrintArr(arr, size);
        CountArr(arr, size, minusCounter);
        std::cout << "\nNegative numbers: " << minusCounter;
        std::cout << "\nNumbers: " << size - minusCounter;

        delete[] arr;
    }

    NumComp();
    BUBBLE();
    EmployeeParams();
    

    return 0;
}
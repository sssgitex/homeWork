#include <iostream>
#include <fstream>
#include <string>

std::ofstream fout;
std::ifstream fin;

void memAlloc (int** pArr, int** pI, int** pNum, int & arrSize)
{
    *pArr = new (std::nothrow) int[arrSize];
    *pI = new (std::nothrow) int [0];
    *pNum = new (std::nothrow) int [0];
}
void memClear(int** pArr, int** pI, int** pNum, int & arrSize)
{
    delete[] pArr;
    pArr = nullptr;
    delete pI;
    pI = nullptr;
    delete pNum;
    pI = nullptr;
}
void fillArray(int* pArr, int* pI, int* pNum, int arrSize)
{
    for (*pI = 0; *pI < arrSize; *pI = *pI + 1)
    {
        pArr[*pI] = *pNum;
        *pNum = (*pNum) * 2;
    }
}
void printArray(int* pArr, int* pI, int* pNum, int arrSize){
    for (*pI = 0; *pI < arrSize; *pI = *pI + 1)
    {
        std::cout << pArr[*pI] << "\t";
    }
    std::cout << "\n";
}

void memAlloc_2(int*** pArr2, const int row, const int line)
{
    pArr2 = new (std::nothrow) int ** [row];
    for (size_t i = 0; i < row; i++)
    {
        *pArr2[i] = new (std::nothrow) int [line];
    }
    pArr2[0][0] = 0;
    std::cout << pArr2[0][0] << "!";
}
void memClear_2(int*** pArr2, const int row, const int line)
{
    for (size_t i = 0; i < row; i++)
    {
        delete[] *pArr2[row];
    }
    delete[] **pArr2;
}
void arrRandFill(int ** pArr2, const int row, const int line)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < line; j++)
        {
            pArr2[i][j] = rand() % 2;
        }
        
    }
}
void arrRandPrint(int ** pArr2, const int row, const int line)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < line; j++)
        {   
            if(j == line - 1)
                std::cout << pArr2[i][j] << "\n";
            else
                std::cout << pArr2[i][j] << "\t";
        }
        
    }
}

void glue(std::string fileName_1, std::string fileName_2)
{
    std::string fileName_3, str_1, str_2;
    std::cout << "Enter 3rd file name: ";
    std::cin >> fileName_3;

    fin.open(fileName_1);

    if (fin.is_open())
    {
        getline(fin, str_1);
        fin.close();
    }

    fin.open(fileName_2);

    if (fin.is_open())
    {
        getline(fin, str_2);
        fin.close();
    }

    fout.open(fileName_3);

    if(fout.is_open())
    {
        fout << str_1 << "\n";
        fout << str_2 << "\n";

    }


}

int main(){

    int* pArr;
    int arrSize;
    int* pI;
    int* pNum;
    

    std::cout << "Enter the size of yor array: ";
    std::cin >> arrSize;

    if (arrSize > 0)
    {
        // 1 задание =============================================
        memAlloc(&pArr, &pI, &pNum, arrSize);

        *pNum = 1;

        if ((pArr != nullptr) && (pI != nullptr))
        {
            fillArray(pArr, pI, pNum, arrSize);
            printArray(pArr, pI, pNum, arrSize);
            memClear(&pArr, &pI, &pNum, arrSize);
        }
        else
        {
            std::cout << "Error! Can not allocate the memmory ";
        }
        // 1 задание =============================================


        // 2 задание =============================================
    int** pArr2;
    const int row = 4;
    const int line = 4;

    //memAlloc_2( &pArr2, row, line);
        
    pArr2 = new (std::nothrow) int * [row];
    for (size_t i = 0; i < row; i++)
    {
        pArr2[i] = new (std::nothrow) int [line];
    }
    
    arrRandFill( pArr2, row, line);
    
    arrRandPrint( pArr2, row, line);

    for (size_t i = 0; i < row; i++)
    {
        delete[] pArr2[row];
    }
    delete[] pArr2;
    
    // 2 задание =============================================


    // 3-4 задание =============================================

    std::string fileName_1, fileName_2;

    

    std::cout << "Enter 1st file name: ";
    std::cin >> fileName_1;

    fout.open (fileName_1, std::ios_base::app);

    if(fout.is_open())
    {
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t j = 0; j < 10; j++)
            {
                fout << j << "|";
            }
        }

        fout.close();    
    }

    std::cout << "Enter 2nd file name: ";
    std::cin >> fileName_2;

    fout.open (fileName_2, std::ios_base::app);

    if(fout.is_open())
    {
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t j = 10; j > 0; j--)
            {
                fout << j << "/";
            }
        }    
    }
    fout.close();

    glue(fileName_1, fileName_2);

    // 3-4 задание =============================================


    // 5 задание =============================================
    std::string str, file_str;
    std::cout << "Enter your word: ";
    std::cin >> str;

    fin.open("test_file.txt");

    if(fin.is_open())
    {
        getline(fin, file_str);

        size_t found = file_str.find(str);
        if (found != std::string::npos)
        std::cout << "First occurrence is " << found << std::endl;

    }

    // 5 задание =============================================


    }

    return 0;
}
#include <iostream>

int main(){
    // 1 задание =============================
    short int a, b, result;

    std::cout << "Enter 1st number: ";
    std::cin >> a;
    std::cout << "Enter 2nd number: ";
    std::cin >> b;

    result = a + b;

    if ((result >= 10) && (result <= 20))
        std::cout << "true";
    else 
        std::cout << "false";
    // 1 задание =============================



    // 2 задание =============================
    const int d = 5, c = 5;

    if ((d == 10) || (c == 10) || (c+d == 10))
        std::cout << "\n\n\ntrue";
    else 
        std::cout << "\n\n\nfalse";
    // 2 задание =============================


    // 3 задание =============================
    for (size_t i = 0; i <= 50; ++i)
    {
        if((i % 2) != 0)
            std::cout << "\n" << i << "\n";
    }
    // 3 задание =============================


    // 4 задание =============================
    int number = 0, alert = 0;
    std::cout << "Enter your number: ";
    std::cin >> number;

    for (size_t k = 1; k <= number; k++)
    {
        if ((number %  k) == 0)
            alert;
    }

    if (alert > 2)
            std::cout << "Your number is not simple";
    else if (alert == 2)
            std::cout << "Your number is simple";
    // 4 задание =============================
    

    // 5 задание =============================
    int year = 1, yearValue = 0;

    printf("\nEnter the year (from 1 to 3'000): ");
    scanf("%d", &year);

    while ((year < 0) || (year > 3000)){
        printf("\nEnter the correct year (from 1 to 3'000): ");
        scanf("%d", &year);
    }

    if ((year % 100) == 0)
        yearValue = 100;
    else if ((year % 100) != 0)
        yearValue = 1;


    switch (yearValue)
    {
        case (1) :  
        
        if ((year % 4) == 0){
            printf ("\nYear %d is visokosniy", year);
        }
                        
        else{
            printf ("\nYear %d is not visokosniy", year);
        }
        break;
        case (100) :    
        
        if ((year % 4) == 0)
        {
            if ((year % 100) == 0)
            {
                if ((year % 400) == 0)
                {
                    printf ("\nYear %d is visokosniy", year);
                }
                else
                    printf ("\nYear %d is not visokosniy", year);
            }
            
            else
            printf ("\nYear %d is not visokosniy", year);
        }
        
        else
        printf ("\nYear %d is not visokosniy", year);
        break;
    }

    // 5 задание =============================



    // 6 задание =============================

    const int line = 5, row = 5;
    int center = 0;

    center = (line - 1) / 2;

    int matrix[line][row] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    std::cout << "\n";
    for (size_t n = 0; n < line; n++)
    {
        for (size_t m = 0; m < row; m++)
        {
            std::cout << matrix[n][m] << "\t";
        }
        std::cout << "\n";
    }
    
    std::cout << "\n\n\n";


    for (size_t t = 0; t < line; t++)
        {
            if (t == 0)
                matrix[center + t][center + t] = 1;
            else
                matrix[center - t][center - t] = 1;
                matrix[center - t][center + t] = 1;
                matrix[center + t][center - t] = 1;
                matrix[center + t][center + t] = 1;
        }


    for (size_t n = 0; n < line; n++)
    {
        for (size_t m = 0; m < row; m++)
        {
            std::cout << matrix[n][m] << "\t";
        }
        std::cout << "\n";
    }

    // 6 задание ============================= (работает при любой квадратной матрице, если константы не четные)


    return 0;
}
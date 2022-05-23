#include <iostream>
#include "add_extern.cpp"

    extern const int a;
    extern const int b;
    extern const int c;
    extern const int d;

int main(){
    // 1-4 ЗАДАНИЕ ===============================
    float result = 0.0f;

    result = a * (b + (static_cast<float>(c)/d));

    std::cout << "Result is = "<< result << "\n\n\n";
    // 1-4 ЗАДАНИЕ ===============================

    // 2 ЗАДАНИЕ ===================================================================

    int number = 0;
    std::cout << "Enter your number: ";
    std::cin >> number;

    if (number <= 21)
        std::cout << "Your number is less than or equal 21: " << 21 - number << "\n";
    else if (number > 21)
        std::cout << "Your number is more than 21: " << ((number - 21) << 1) << "\n";
    // 2 ЗАДАНИЕ ===================================================================


    // 2 ЗАДАНИЕ =========================
    int arr[3][3][3] = {{0},{0},{0}};
    int* pArr = &arr[1][1][1];

    *pArr = 100;

    std::cout << "\n\n" << *pArr << "\n";
    // 2 ЗАДАНИЕ =========================


    return 0;
}
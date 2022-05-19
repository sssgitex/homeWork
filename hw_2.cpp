#include <iostream>

// Крестики нолики ===============================
enum Signs: char
    {
        X = 'X',
        O = 'O',
        E = ' '
    };
struct TicTacToeField
    {
        Signs FieldArr[3][3] = {{E, E, E},
                                {E, E, E},
                                {E, E, E}};
        unsigned short PlayerID : 1;
        unsigned short PlayerSign : 1;
        bool bGameState;
        bool bGameWinner;
        bool bPlayerTurnToMove;
    };

// Переменные ====================================


    typedef float TPlaneSpeed;
    using TCarSpeed = unsigned short int;

    //глобальные переменные
    unsigned short int shi = 0U; // 2byte 0->6500, -32k->32k
    unsigned int a = 100;//4 byte unsigned может принимать значения от  0 -> 4'000'000'000
    long long v = 6124123155612LL; // 8 byte


// 5 задание  ====================================



struct MyVariant {

    union MyData{
        int iVar;
        float fVar;
        unsigned char cVar;
    };

    unsigned short isInt : 1;
    unsigned short isFloat : 1;
    unsigned short isChar : 1;
};

int main(){

// Крестики нолики ===============================

    TicTacToeField Field;
    
    Field.FieldArr[3][3];

    for (int line = 0; line < 3; line++)
    {
        for (int row = 0; row < 3; row++)
        {
            if (row == 2)
                std::cout << Field.FieldArr[line][row] << "\t\n";
            else
                std::cout << Field.FieldArr[line][row] << "\t";
        }
    }


// Переменные ====================================

    //локальные перменные, сегмент стека (временные, тоесть при выходе из main переменные уничтожаються)
    //float f = 9.9999f; //4 byte
    auto f = 9.9999f; //4 byte
    double d = 523416.12315; // 8 byte
    long double dd = 3.5; // 8 byte
    //
    size_t i = 12345; // 0..MAX 4byte-8byte  STL type
    //
    char ch = 'A'; //ASCII DOS, 1byte
    bool flag{ true }; // 1 byte


    d = sizeof(d); // size of the variable types;

    const int b = 100; // не изменяются

    TPlaneSpeed Car_1 = 300.0f;
    TCarSpeed Car = 50.0f;
    
    int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };
    std::cout << arr[3] << std::endl;
    *(arr + 3) = 1'000; // можно работать как с указателем
    std::cout << arr[3] << std::endl;
    arr[3] = 1001;
    std::cout << arr[3] << std::endl;


    char str[100] = "abc";// последний символ 0, тоесть 4 символа

    std::cout << str << "\n";

    std::cout << arr[0] << arr[1] << "\n";


    char arr2[4] = { 'A', 'B', 'C', '\0' };

    int arr3[2][2] = { { 1, 2 }, {3, 4 } };

    std::cout << arr2 << "\n";

   // 5 задание  ====================================

    MyVariant::MyData Info;
    MyVariant State;
    State.isChar = 0;
    State.isInt = 0;
    State.isFloat = 0;

    std::cout << "\nEnter char: ";           //
    std::cin >> Info.cVar;
    State.isChar = 1;
    State.isFloat = 0;
    State.isInt = 0;

    std::cout << "\nEnter float: ";
    std::cin >> Info.fVar;                  // по хорошему сделать функциями
    State.isFloat = 1;
    State.isInt = 0;
    State.isChar = 0;

    std::cout << "\nEnter integer: ";
    std::cin >> Info.iVar;
    State.isInt = 1;
    State.isChar = 0;
    State.isFloat = 0;                      //
    
    std::cout << "\nMyData value "  ; (State.isInt == 1) ? std::cout << " is integer\n" : std::cout <<"is not integer\n";
    std::cout << "MyData value "    ; (State.isChar  == 1) ? std::cout << " is char\n" : std::cout << "is not char\n";
    std::cout << "MyData value "    ; (State.isFloat == 1) ? std::cout << " is float\n" : std::cout << "is not float\n";

    if (State.isFloat == 1)
        std::cout << "And equal " << Info.fVar;
    else if (State.isChar == 1)
        std::cout << "And equal " << Info.cVar;
    else if (State.isInt == 1)
        std::cout << "And equal " << Info.iVar;

    return 0;
}
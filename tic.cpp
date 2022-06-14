#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>
#include <windows.h>


enum TCell : char 
{
    CROSS = 'X',
    ZERO = 'O',
    EMPTY = '_'
};

enum TProgress 
{
    IN_PROGRESS,
    WON_HUMAN,
    WON_AI,
    DRAW
};

struct TCoord
{
    size_t y{0};
    size_t x{0};
};

#pragma pack (push, 1)
struct TGame 
{
    TCell** ppField{nullptr}; // игровое поле 
    const size_t SIZE{3};
    TProgress progress{IN_PROGRESS};
    TCell human, ai;
    size_t turn {0U}; //номер хода - четные человек, нечетные AI
};
#pragma pack(pop)

void clrScreen()
{
    //std::cout << "\x1B[2J\x1B[H";
    system("cls");
}

int32_t gaetRandomNum(int32_t min, int32_t max)
{
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int32_t> dis (min, max);
    return dis(generator);
}

void __fastcall initGame (TGame& game)
{
    game.ppField = new TCell * [game.SIZE];
    for(size_t i = 0; i < game.SIZE; i++)
    {
        game.ppField[i] = new TCell [game.SIZE];
    }

    for (size_t y = 0; y < game.SIZE; y++)
    {
        for (size_t x = 0; x < game.SIZE; x++)
        {
            game.ppField[y][x] = EMPTY;
        }
    }

    if(gaetRandomNum(0, 1000) > 500)
    {
        game.human = CROSS; // first
        game.ai = ZERO;
        game.turn = 0;
    }
    else
    {
        game.human = ZERO; // first
        game.ai = CROSS;
        game.turn = 1;
    }
}

void __fastcall printGame (const TGame& game)
{
    std::cout << "    ";
    for (size_t x = 0; x < game.SIZE; x++)
    {
        std::cout << x+1 << "    ";
    }
    std::cout << std::endl;
    
    for (size_t y = 0; y < game.SIZE; y++)
    {
        std::cout << y+1 << " | ";
        for (size_t x = 0; x < game.SIZE; x++)
        {
           std::cout << (char)game.ppField[y][x] << " | ";
        }
        std::cout << std::endl;
        
    }
    std::cout << std::endl;
    std::cout << " Human: " << (char)game.human << "\n Computer: " << (char)game.ai;
}

void __fastcall deinitGame (TGame& game)
{
    for(size_t i = 0; i < game.SIZE; i++)
    {
        delete[] game.ppField[i];
    }
    delete[] game.ppField;
}

TProgress __fastcall getWon(const TGame & game)
{
    for (size_t y = 0; y < game.SIZE; y++)
    {
        if(game.ppField[y][0] == game.ppField[y][1] && game.ppField[y][0] == game.ppField[y][2])
        {
            if(game.ppField[y][0] == game.human)
                return WON_HUMAN;
            
            if(game.ppField[y][0] == game.ai)
                return WON_AI;
        }
    }

    for (size_t x = 0; x < game.SIZE; x++)
    {
        if(game.ppField[0][x] == game.ppField[1][x] && game.ppField[0][x] == game.ppField[2][x])
        {
            if(game.ppField[0][x] == game.human)
                return WON_HUMAN;
            
            if(game.ppField[0][x] == game.ai)
                return WON_AI;
        }
    }


    if(game.ppField[0][0] == game.ppField[1][1] && game.ppField[0][0] == game.ppField[2][2])
    {
        if(game.ppField[1][1] == game.human)
                return WON_HUMAN;
            
        if(game.ppField[1][1] == game.ai)
                return WON_AI;
    }

    if(game.ppField[0][2] == game.ppField[1][1] && game.ppField[1][1] == game.ppField[2][0])
    {
        if(game.ppField[1][1] == game.human)
                return WON_HUMAN;
            
        if(game.ppField[1][1] == game.ai)
                return WON_AI;
    }

    bool draw{true};

    for (size_t y = 0; y < game.SIZE; y++)
    {
        for (size_t x = 0; x < game.SIZE; x++)
        {
            if (game.ppField[y][x] == EMPTY)
            {
                draw = false;
                break;
            }
        }
        if(!draw)
            break;
    }
    
    if (draw)
        return DRAW;

    return IN_PROGRESS; 
}  

TCoord __fastcall getHumanCoord(const TGame & game)
{
    TCoord c;
    do
    {
        std::cout << "\n Enter X (1...3): ";
        std::cin >> c.x;
        std::cout << "\n Enter Y (1...3): ";
        std::cin >> c.y;
        c.x--;
        c.y--;

    }while (c.x > 2 || c.y > 2 || game.ppField[c.y][c.x] != EMPTY);

    return c;

}
TCoord __fastcall getAICoord(TGame & game)
{
    //превыигрышь
    for (size_t y = 0; y < game.SIZE; y++)
    {
        for (size_t x = 0; x < game.SIZE; x++)
        {
            if (game.ppField[y][x] == EMPTY)
            {
                game.ppField[y][x] = game.ai;
                if(getWon(game) == WON_AI)
                {
                    game.ppField[y][x] = EMPTY;
                    return{y, x};
                }
                game.ppField[y][x] = EMPTY;
            }
        }
    }
    //препроигрышь - мешает
    for (size_t y = 0; y < game.SIZE; y++)
    {
        for (size_t x = 0; x < game.SIZE; x++)
        {
            if (game.ppField[y][x] == EMPTY)
            {
                game.ppField[y][x] = game.human;
                if(getWon(game) == WON_HUMAN)
                {
                    game.ppField[y][x] = EMPTY;
                    return{y, x};
                }
                game.ppField[y][x] = EMPTY;
            }
        }

    }


    // по приоритетам + рандом
    if(game.ppField[1][1] == EMPTY)
    {
        return {1, 1};
    }

    TCoord buff[4];
    size_t num { 0 };
    if (game.ppField[0][0] == EMPTY)
    {
        buff[num] = {0, 0};
        num++;
    }
    if (game.ppField[0][2] == EMPTY)
    {
        buff[num] = {0, 2};
        num++;
    }
    if (game.ppField[2][2] == EMPTY)
    {
        buff[num] = {2, 2};
        num++;
    }
    if (game.ppField[2][0] == EMPTY)
    {
        buff[num] = {2, 0};
        num++;
    }

    if(num > 0)
    {
        const size_t index = gaetRandomNum(0, 1000) % num;
        return buff[index];
    }

    if (game.ppField[1][0] == EMPTY)
    {
        buff[num] = {1, 0};
        num++;
    }
    if (game.ppField[1][2] == EMPTY)
    {
        buff[num] = {1, 2};
        num++;
    }
    if (game.ppField[2][1] == EMPTY)
    {
        buff[num] = {2, 1};
        num++;
    }
    if (game.ppField[0][1] == EMPTY)
    {
        buff[num] = {0, 1};
        num++;
    }

    if(num > 0)
    {
        const size_t index = gaetRandomNum(0, 1000) % num;
        return buff[index];
    }
}

void congrats(const  TGame& game)
{
    if(game.progress == WON_HUMAN)
    {
        std::cout << "\nU WIN!";
    }
    else if(game.progress == WON_AI)
    {
        std::cout << "\nAI WIN (";
    }
    else
    {
        std::cout << "\nDRAW!";
    }
}

int main()
{
    TGame game;
    initGame(game);
    clrScreen();
    printGame(game);
    size_t exit = 0;
    do
    {
        if(game.turn % 2 == 0) // [человек]
        {
            TCoord c = getHumanCoord(game);
            game.ppField[c.y][c.x] = game.human;
        }
        else // [аи]
        {
            TCoord c = getAICoord(game);
            game.ppField[c.y][c.x] = game.ai;
        }
        clrScreen();
        printGame(game);
        game.turn++;
        game.progress = getWon(game);
        
    } while (game.progress == IN_PROGRESS);

    congrats(game);
    deinitGame(game);

    return 0;
}
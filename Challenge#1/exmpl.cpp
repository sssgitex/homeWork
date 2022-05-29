#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

const unsigned int heightArr = 20, widthArr = 50;
unsigned int PlayerPosY = 2, PlayerPosX = 3;
unsigned int FistPosY = PlayerPosY, FistPosX =  PlayerPosX + 1;
unsigned int NextPosY = 0, NextPosX = 0;
//char currentMap[heightArr][widthArr];
//char prevMap[heightArr][widthArr];
class Player
{
public:
    char charModel;

    Player(char m){
        charModel = m;
}
};
class Framebuffer{
public:
    char MapArr[heightArr][widthArr];
};

Framebuffer curr_;
Framebuffer prev_;
 

void ConstructConsole(int Width, int Height)
{
    COORD bufSize;
    bufSize.X = Width;
    bufSize.Y = Height;

    SMALL_RECT winSize;
    winSize.Top = Height+1;
    winSize.Left = Width+1;
    winSize.Bottom = 0;
    winSize.Right = 0;

    COORD newSize;
    newSize.X = bufSize.X;
    newSize.Y = bufSize.Y;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(Handle, TRUE , &winSize);
    SetConsoleScreenBufferSize(Handle, bufSize);
}
void ClearScreen()
{
    system("cls");
}
bool setCursorToPosition(int x, int y)
{
    COORD cursCoord;
    cursCoord.X = x;
    cursCoord.Y = y;

    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursCoord);
}
void PrevMapReframe();
void ConstructMap()
{
    //current map
    for (size_t i = 0; i <= heightArr; i++)
    {
            
        for (size_t j = 0; j <= widthArr; j++)
        {
            curr_.MapArr[i][j] = ' ';
        }
    }

    for (size_t i = 0; i <= heightArr; i++)
    {
        for (size_t j = 0; j <= widthArr; j++)
        {   
            if((i == 0) || (i == heightArr))
                curr_.MapArr[i][j] = '#';
            
            if((i > 0) && (i < heightArr))
            {
                if(j > 0 && j < widthArr){}
                    
                else    
                    curr_.MapArr[i][j] = '#';
            }
        }
    }
    //prev map 
    PrevMapReframe();
    
}
void PrevMapReframe(){
    for (size_t i = 0; i <= heightArr; i++)
    {
            
        for (size_t j = 0; j <= widthArr; j++)
        {
            prev_.MapArr[i][j] = curr_.MapArr[i][j]; 
        }
    }
}

void ShowMap()
{
    for (size_t i = 0; i <= heightArr; i++)
    {
        for (size_t j = 0; j <= widthArr; j++)
        {
            std::cout << prev_.MapArr[i][j];
        }
        std::cout << '\n';
    }
}
void RefreshMap()
{
    //ClearScreen();
    for (size_t i = 0; i <= heightArr; i++)
    {
        for (size_t j = 0; j <= widthArr; j++)
        {
            if(curr_.MapArr[i][j] == prev_.MapArr[i][j])
            {
                setCursorToPosition(j, i);
                std::cout << curr_.MapArr[i][j];
                continue;
            }
            else
            {
                setCursorToPosition(j, i);
                std::cout << curr_.MapArr[i][j];
            }
        }
    }
    std::cout.flush();
}

void MoveRight(Player& pl1)
{
    NextPosX = PlayerPosX + 1;
    if(NextPosX == widthArr){}
    else{

        if (FistPosX == widthArr){}
        else
            curr_.MapArr[PlayerPosY][FistPosX] = ' ';

        curr_.MapArr[PlayerPosY][PlayerPosX] = ' ';
        PlayerPosX++;
        curr_.MapArr[PlayerPosY][PlayerPosX] = pl1.charModel;
    }
    
}
void MoveLeft(Player& pl1)
{
    NextPosX = PlayerPosX - 1;
    if(NextPosX == 0){}
    else{

        if (FistPosX == widthArr){}
        else
            curr_.MapArr[PlayerPosY][FistPosX] = ' ';

        curr_.MapArr[PlayerPosY][PlayerPosX] = ' ';
        PlayerPosX--;
        curr_.MapArr[PlayerPosY][PlayerPosX] = pl1.charModel;
        
    }
    
}
void MoveUp(Player& pl1)
{

    NextPosY = PlayerPosY - 1;
    if(NextPosY == 0){}
    else{

        if (FistPosX == widthArr){}
        else
            curr_.MapArr[PlayerPosY][FistPosX] = ' ';


        curr_.MapArr[PlayerPosY][PlayerPosX] = ' ';
        PlayerPosY--;
        curr_.MapArr[PlayerPosY][PlayerPosX] = pl1.charModel;
    }
    
}
void MoveDown(Player& pl1)
{
    NextPosY = PlayerPosY + 1;
    if(NextPosY == heightArr){}
    else{

        if (FistPosX == widthArr){}
        else
            curr_.MapArr[PlayerPosY][FistPosX] = ' ';

        curr_.MapArr[PlayerPosY][PlayerPosX] = ' ';
        PlayerPosY++;
        curr_.MapArr[PlayerPosY][PlayerPosX] = pl1.charModel;
    }
   
}

void Punch()
{
    FistPosX = PlayerPosX + 1;
    
    if(FistPosX == widthArr){}
    else
    {
        curr_.MapArr[PlayerPosY][FistPosX] = '-';
    }

    
   
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void ShowTextInfo()
{
    setCursorToPosition(55, 10);
    std::cout << "        ↑           \n";
    setCursorToPosition(55, 11);
    std::cout << "Press ← ↓ → to move \n";
    setCursorToPosition(55, 12);
    std::cout << "Press SPACE to punch \n";
    setCursorToPosition(55, 13);
    std::cout << "Press ESC to exit game \n";
}

int main()
{
    int exit = 0;
    ClearScreen();

    Player pl1('@');

    ConstructConsole(100, 100);
    ConstructMap();
    ShowTextInfo();

    setCursorToPosition(0, 0);

    curr_.MapArr[PlayerPosY][PlayerPosX] = '0';
    
    ShowMap();
    CONSOLE_CURSOR_INFO cursorInfo;
    while (exit != 1){
        ShowConsoleCursor(0);
        RefreshMap();
        system("pause>nul");
        if (GetAsyncKeyState(VK_DOWN) < 0)
                MoveDown(pl1);
        if (GetAsyncKeyState(VK_UP) < 0)
                MoveUp(pl1);
        if (GetAsyncKeyState(VK_LEFT) < 0)
                MoveLeft(pl1);
        if (GetAsyncKeyState(VK_RIGHT) < 0)
                MoveRight(pl1);
        if (GetAsyncKeyState(VK_SPACE) < 0)
                Punch();
        if (GetAsyncKeyState(VK_ESCAPE) < 0)
                exit = 1;
    }
    

    return 0;
}


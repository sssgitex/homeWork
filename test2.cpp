#include <iostream>
#include <fstream>
#include <string>

std::ofstream fout1;

void glue(std::ifstream& fin, std::ofstream& fout)
{
    std::string str;

    getline(fin, str);
    fout << str << std::endl;
    /*while(!fin.eof())
    {
        getline(fin, str);
        fout << str << std::endl;
    }*/
}

int main()
{

std::string fileName_1, fileName_2, fileName_3;

    

    std::cout << "Enter 1st file name: ";
    std::cin >> fileName_1;

    fout1.open (fileName_1, std::ios_base::app);

    if(fout1.is_open())
    {
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t j = 0; j < 10; j++)
            {
                fout1 << j << "|\n";
            }
        }

        fout1.close();    
    }

    std::cout << "Enter 2nd file name: ";
    std::cin >> fileName_2;

    fout1.open (fileName_2, std::ios_base::app);

    if(fout1.is_open())
    {
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t j = 10; j > 0; j--)
            {
                fout1 << j << "/\n";
            }
        }    
    }
    fout1.close();

    //std::string str_1, str_2, str_out;
    std::cout << "Enter 3rd file name: ";
    std::cin >> fileName_3;

    std::ifstream fin1(fileName_1+".txt");
    std::ifstream fin2(fileName_2+".txt");
    std::ofstream fout3(fileName_3+".txt");

    //fin1.open(fileName_1+".txt");
    //fout3.open(fileName_3+".txt");
    glue(fin1, fout3);
    fin1.close();

    //fin2.open(fileName_2+".txt");
    //fout3.open(fileName_3+".txt");
    glue(fin2, fout3);
    fin2.close();

    fout3.close();


return 0;
}

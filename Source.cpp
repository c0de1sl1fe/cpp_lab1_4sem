#include <iostream>

#include "Class.h"
#include <stdio.h>

void menu1()
{
    system("cls");
    std::cout << "Hello! Choose one option:";
    std::cout << "1. Insert" << std::endl;
    std::cout << "2. Check contains" << std::endl;
    std::cout << "3. Erase element" << std::endl;
    std::cout << "4. Do lab task" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Choice: ";
}
int EnterNumber()
{
    double tmp;
    char stmp[24];
    bool exit1 = false;
    while (!exit1)
    {
        bool exit = true;
        gets_s(stmp);
        char* endptr = stmp;
        tmp = strtod(stmp, &endptr);
        if (endptr == stmp)
        {
            exit = false;
            continue;
        }
        if ((tmp == DBL_MAX || tmp == DBL_MIN) && errno == ERANGE)
        {
            exit = false;
            continue;
        }
        while (*endptr)
        {
            if ((*endptr != ' ') && (*endptr != '\n'))
            {
                exit = false;
                break;
            }
            endptr++;
        }
        if (exit)
        {
            exit1 = true;
        }
        else
        {
            exit1 = false;
            printf("\nsomething wrong with number\n");
        }
    }
    return (int)tmp;
}

void main()
{
    set test;

    test.insert(6);
    test.insert(4);
    test.insert(7);
    test.insert(2);

    test.insert(5);


    test.print();
}
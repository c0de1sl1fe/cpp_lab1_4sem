#include <iostream>

#include "Class.h"
#include <stdio.h>

void printMenu()
{
    system("cls");
    std::cout << "Hello! Choose one option:" << std::endl;
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


void test()
{
    set test;

    test.insert(6);
    test.insert(4);
    test.insert(7);
    test.insert(2);

    test.insert(5);
    std::cout << test.contains(7) << std::endl;

}

void main()
{
    test();
    set tree;
    int choice = 0;
    bool exit = false;
    while (!exit)
    {
        printMenu();
        choice = EnterNumber();
        switch (choice)
        {
        case(1):
            int key;
            std::cout << "Let's enter number: ";
            key = EnterNumber();
            if (tree.insert(key))
            {
                std::cout << "uccessfully inserted" << std::endl;
            }
            else
            {
                std::cout << "something went wrong" << std::endl;
            }
            
            tree.print();
            system("pause");
            break;
        case(2):

            break;
        case(3):

            break;
        case(4):

            break;
        case(5):
            std::cout << "Bye!" << std::endl;
            exit = true;
            break;

        default:
            std::cout << "Unable to recognize your request" << std::endl;
            break;
        }
    }
}
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





set interseption(Node* src, const set rhs, set& dst)
{
    if (!src)
    {
        return dst;
    }
    if (rhs.contains(src->data))
    {
        dst.insert(src->data);
    }
    interseption(src->left, rhs, dst);
    interseption(src->right, rhs, dst);
    return dst;
}

set interseption(const set lhs, const set rhs)
{
    set result;
    return interseption(lhs.getRoot(), rhs, result);
}
set difference(Node* src, const set rhs, set& dst)
{
    if (!src)
    {
        return dst;
    }
    if (!rhs.contains(src->data))
    {
        dst.insert(src->data);
    }
    difference(src->left, rhs, dst);
    difference(src->right, rhs, dst);
    return dst;
}

set difference(const set lhs, const set rhs)
{
    set result;
    return difference(lhs.getRoot(), rhs, result);
}

void test()
{
    set test;
    test.insert(6);
    test.insert(4);
    test.insert(7);
    test.insert(2);
    test.insert(5);
    test.print();
    std::cout << "test:" << std::endl;

    set test1;
    test1.insert(7);
    test1.insert(5);
    test1.insert(7);
    test1.insert(3);

    test1.insert(1);
    
    test1.print();
    std::cout << "test:" << std::endl << std::endl;
    set tmp = interseption(test, test1);
    std::cout << "res:" << std::endl;
    tmp.print();

    tmp = difference(test, test1);
    std::cout << "res:" << std::endl;
    tmp.print();
}
void main()
{
    //test();
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
        {
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
        }
        case(2):
        {
            std::cout << std::endl;
            std::cout << "Are number contained in set: ";
            int key = EnterNumber();
            if (tree.contains(key))
            {
                std::cout << "Yes, number " << key << " are contained in this set" << std::endl;
            }
            else
            {
                std::cout << "NO, number " << key << " aren' contained in this set" << std::endl;
            }

            tree.print();
            system("pause");
            break;
        }
        case(3):
        {
            tree.print();
            std::cout << std::endl;
            std::cout << "Let's erase: ";
            int key = EnterNumber();
            if (tree.erase(key))
            {
                std::cout << "uccessfully erased" << std::endl;
            }
            else
            {
                std::cout << "something went wrong" << std::endl;
            }

            tree.print();
            system("pause");

            break;
        }
        case(4):
        {
            system("cls");
            set lhs;
            lhs.insert(6);
            lhs.insert(4);
            lhs.insert(7);
            lhs.insert(2);
            lhs.insert(5);
            std::cout << "lhs:" << std::endl;
            lhs.print();

            set rhs;
            rhs.insert(5);
            rhs.insert(1);
            rhs.insert(3);
            rhs.insert(7);

            std::cout << "rhs:" << std::endl;
            rhs.print();
                
            std::cout << std::endl;
            std::cout << "Here you can see work of functions interseption() and difference()" << std::endl << std::endl;


            std::cout << "interseption():" << std::endl;
            set tmp = interseption(lhs, rhs);
            tmp.print();

            std::cout << std::endl;

            std::cout << "difference():" << std::endl;
            tmp = difference(lhs, rhs);
            tmp.print();

            system("pause");
            break;
        }
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
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


size_t lcg() {
    static size_t x = 0;
    x = (1021 * x + 24631) % 116640;
    return x;
}

#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
using namespace std::chrono;

void testFILLMySet(int numb, int rep)
{
    set test;
    int res = 0;
    for (int j = 0; j < rep; j++)
    {
        auto start = high_resolution_clock::now();
        for (int i = 0; i < numb; i++)
        {
            test.insert(lcg());
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        //std::cout << "Time taken by function: "
        //    << duration.count() << " microseconds" << std::endl;
        res += duration.count();
    }
    std::cout << "Time of FILL for " << numb << " for " << rep << " times: " << (double)res / rep << " microseconds" << std::endl;
}

void testContainsMySet(int numb, int rep)
{
    set test;
    for (int i = 0; i < numb; i++)
    {
        test.insert(lcg());
    }
    long double res = 0;
    for (int j = 0; j < rep; j++)
    {
        auto start = high_resolution_clock::now();
        test.contains(lcg());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        //std::cout << "Time taken by function: "
        //    << duration.count() << " microseconds" << std::endl;
        res += duration.count();
    }
    std::cout << "Time of IS_CONTAINS for " << numb << " for " << rep << " times: " << (double)res / rep << " nanoseconds" << std::endl;
}

void testInsertMySet(int numb, int rep)
{
    set test;
    for (int i = 0; i < numb; i++)
    {
        test.insert(lcg());
    }
    int res = 0;
    for (int j = 0; j < rep; j++)
    {
        set tmp = test;
        auto start = high_resolution_clock::now();
        tmp.insert(lcg());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        //std::cout << "Time taken by function: "
        //    << duration.count() << " microseconds" << std::endl;
        res += duration.count();
    }
    std::cout << "Time of INSERT for " << numb << " for " << rep << " times: " << (double)res / rep << " nanoseconds" << std::endl;
}

void testEraseMySet(int numb, int rep)
{
    set test;
    for (int i = 0; i < numb; i++)
    {
        test.insert(lcg());
    }
    int res = 0;
    for (int j = 0; j < rep; j++)
    {
        set tmp = test;
        auto start = high_resolution_clock::now();
        tmp.erase(lcg());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        //std::cout << "Time taken by function: "
        //    << duration.count() << " microseconds" << std::endl;
        res += duration.count();
    }
    std::cout << "Time of ERASE for " << numb << " for " << rep << " times: " << (double)res / rep << " nanoseconds" << std::endl;
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
            testFILLMySet(1000, 100);
            testFILLMySet(10000, 100);
            testFILLMySet(100000, 100);

            std::cout << std::endl;

            testContainsMySet(1000, 1000);
            testContainsMySet(10000, 1000);
            testContainsMySet(100000, 1000);

            std::cout << std::endl;

            testInsertMySet(1000, 1000);
            testInsertMySet(10000, 1000);
            testInsertMySet(100000, 1000);

            std::cout << std::endl;

            testEraseMySet(1000, 1000);
            testEraseMySet(10000, 1000);
            testEraseMySet(100000, 1000);

            exit = true;
            break;

        default:
            std::cout << "Unable to recognize your request" << std::endl;
            break;
        }
    }
}
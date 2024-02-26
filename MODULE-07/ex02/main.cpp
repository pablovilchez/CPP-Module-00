#include <iostream>
#include <Array.hpp>

#define MAX_VAL 10

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // show generated arrays:
    std::cout << "numbers:      ";
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << numbers[i] << "  ";
    std::cout << std::endl;
    std::cout << "mirror:       ";
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << mirror[i] << "  ";
    std::cout << std::endl;
    // ++++++++++++++++++++++

    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        // show generated arrays with copy an equal:
            std::cout << "(copy) tmp:   ";
        for (int i = 0; i < MAX_VAL; i++)
            std::cout << tmp[i] << "  ";
        std::cout << std::endl;
            std::cout << "(equal) test: ";
        for (int i = 0; i < MAX_VAL; i++)
            std::cout << test[i] << "  ";
        std::cout << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // reasign values to "numbers"
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    // compare new array with old
    std::cout << "(new)numbers: ";
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << numbers[i] << "  ";
    std::cout << std::endl;
    std::cout << "mirror:       ";
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << mirror[i] << "  ";
    std::cout << std::endl;

    delete [] mirror;//
    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "./Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    DEBUGLOG << "=== Initializing Array ===" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    
    DEBUGLOG << "Filling array with " << MAX_VAL << " random values..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    DEBUGLOG << "✓ Array filled successfully" << std::endl;
    DEBUGLOG << "  Array size: " << numbers.size() << std::endl;
    DEBUGLOG << "  First 5 values: ";
    for (int i = 0; i < 5; i++)
        DEBUGLOG << numbers[i] << " ";
    DEBUGLOG << std::endl;
    DEBUGLOG << "  Last 5 values: ";
    for (int i = MAX_VAL - 5; i < MAX_VAL; i++)
        DEBUGLOG << numbers[i] << " ";
    DEBUGLOG << std::endl << std::endl;
    
    //SCOPE
    {
        DEBUGLOG << "=== Testing Copy Constructor ===" << std::endl;
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        DEBUGLOG << "✓ Copy operations completed" << std::endl;
        DEBUGLOG << "  Copied array size: " << test.size() << std::endl;
        DEBUGLOG << "  Copied first 5 values: ";
        for (int i = 0; i < 5; i++)
            DEBUGLOG << test[i] << " ";
        DEBUGLOG << std::endl << std::endl;
    }

    DEBUGLOG << "=== Verifying Array Values ===" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    DEBUGLOG << "✓ All values verified successfully" << std::endl << std::endl;
    DEBUGLOG << "=== Testing Out of Bounds Access ===" << std::endl;
    DEBUGLOG << "Attempting to access index -2..." << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    DEBUGLOG << "Attempting to access index " << MAX_VAL << "..." << std::endl;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    DEBUGLOG << std::endl;

    DEBUGLOG << "=== Refilling Array with New Values ===" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    DEBUGLOG << "✓ Array refilled successfully" << std::endl;
    DEBUGLOG << "  Array size: " << numbers.size() << std::endl;
    DEBUGLOG << "  New first 5 values: ";
    for (int i = 0; i < 5; i++)
        DEBUGLOG << numbers[i] << " ";
    DEBUGLOG << std::endl;
    DEBUGLOG << "  New last 5 values: ";
    for (int i = MAX_VAL - 5; i < MAX_VAL; i++)
        DEBUGLOG << numbers[i] << " ";
    DEBUGLOG << std::endl << std::endl;
    
    DEBUGLOG << "=== Cleanup ===" << std::endl;
    delete [] mirror;
    DEBUGLOG << "✓ Program completed successfully" << std::endl;
    return 0;
}
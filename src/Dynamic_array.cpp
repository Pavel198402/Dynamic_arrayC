// Dynamic_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"

int main()
{
    Vector numbers(5);
    
    numbers[0] = 16;
    numbers[1] = 02;    // numbers.set(1, 02);
    numbers[2] = 19;    // numbers.set(2, 19);
    numbers[3] = 84;    // numbers.set(3, 84);
    numbers[4] = 42;        // numbers.set(4, 42);
    
    Vector copy(numbers);
    const Vector constCopy(numbers);
                                            // constCopy[2] = 100;
    std::cout << "Old array:" << std::endl;

    for (unsigned int i = 0; i < numbers.getSize(); i++)
    {
        std::cout << numbers.get(i) << std::endl;
    }

   // numbers.resize(8);


    //numbers[0] = 10;   //для тестування розкоментувати    -----  numbers[0] = 10;
   
    if (numbers == copy)
    {
        std::cout << "Vectors are equal" << std::endl;
    }
    else
    {
        std::cout << "Vectors are not equal" << std::endl;
    }
    if (numbers != copy)
    {
        std::cout << "operator!= : Vectors are not equal" << std::endl;
       
    }
    else
    {
        std::cout << "operator!= : Vectors are equal" << std::endl;
    }
	numbers.resize(8);  

   

    std::cout << "New array:" << std::endl;

    for (unsigned int i = 0; i < numbers.getSize(); i++)
    {
        std::cout << numbers.get(i) << std::endl;
    }
    std::cout << "Copy array:" << std::endl;

    for (unsigned int i = 0; i < copy.getSize(); i++)
    {
        std::cout << copy.get(i) << std::endl;
    }
    std::cout << "show choose:" << std::endl;
    std::cout << constCopy[2] << std::endl;
   
    
    return 0;
    
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// Dynamic_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"
#include <stdexcept>
#include "StaticArray.h"
int main()
{
    Vector<int> numbers(5);
    
    numbers[0] = 16;
    numbers[1] = 02;    // numbers.set(1, 02);
    numbers[2] = 19;    // numbers.set(2, 19);
    numbers[3] = 84;    // numbers.set(3, 84);
    numbers[4] = 42;        // numbers.set(4, 42);
    
    Vector<int> copy(numbers);
    const Vector<int> constCopy(numbers);
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
        
		// тестування викидання виключення при зверненні до елементу за межами масиву
    try
    {
        std::cout << numbers[20] << std::endl;
    }
    catch (const std::out_of_range& error)
    {
        std::cout << error.what() << std::endl;
    }
    
	// тестування викидання виключення при зверненні до елементу за межами масиву

    try
    {
        std::cout << numbers.get(20) << std::endl;
    }
    catch (const std::out_of_range& error)
    {
        std::cout << error.what() << std::endl;
    }
	// тестування викидання виключення при зверненні до елементу за межами масиву set()

    try
    {
        numbers.set(20, 100);
    }
    catch (const std::out_of_range& error)
    {
        std::cout << error.what() << std::endl;
    }

	// тестування 
    Vector<int> empty;

    if (empty)
    {
        std::cout << "Not empty\n";
    }
    else
    {
        std::cout << "Empty\n";
    }

    Vector<int> numbers2(5);

    if (numbers2)
    {
        std::cout << "Not empty\n";
    }
   /*TEST WITH double*/
    Vector<double> doubleNumbers(3);

    doubleNumbers[0] = 1.5;
    doubleNumbers[1] = 2.75;
    doubleNumbers[2] = 3.14;

    std::cout << "Vector<double>:" << std::endl;

    for (unsigned int i = 0; i < doubleNumbers.getSize(); i++)
    {
        std::cout << doubleNumbers[i] << std::endl;
    }
	/*TEST WITH StaticArray*/
    StaticArray<int, 5> staticNumbers;

    staticNumbers[0] = 10;
    staticNumbers[1] = 20;
    staticNumbers[2] = 30;
    staticNumbers[3] = 40;
    staticNumbers[4] = 50;
    std::cout << "StaticArray<int, 5>:" << std::endl;

    for (std::size_t i = 0; i < staticNumbers.getSize(); i++)
    {
        std::cout << staticNumbers[i] << std::endl;
    }
	// Testing set() method
    staticNumbers.set(2, 300);

    std::cout << "After set():" << std::endl;
    std::cout << staticNumbers.get(2) << std::endl;
    //
    try
    {
        std::cout << staticNumbers[10] << std::endl;
    }
    catch (const std::out_of_range& error)
    {
        std::cout << error.what() << std::endl;
    }

    StaticArray<int, 5> staticCopy;

    staticCopy[0] = 10;
    staticCopy[1] = 20;
    staticCopy[2] = 300;
    staticCopy[3] = 40;
    staticCopy[4] = 50;
	
    if (staticNumbers == staticCopy)
    {
        std::cout << "Static arrays are equal" << std::endl;
    }
    else
    {
        std::cout << "Static arrays are not equal" << std::endl;
    }

    staticCopy[0] = 100;       //для тестування розкоментувати    -----  staticCopy[0] = 100;
    if (staticNumbers != staticCopy)
    {
        std::cout << "Static arrays are not equal" << std::endl;
    }
	// тестування push_back()
    Vector<int> pushTest;
    pushTest.push_back(10);
    std::cout << "size = " << pushTest.getSize()
        << ", capacity = " << pushTest.getCapacity() << std::endl;

    pushTest.push_back(20);
    std::cout << "size = " << pushTest.getSize()
        << ", capacity = " << pushTest.getCapacity() << std::endl;

    pushTest.push_back(30);
    std::cout << "size = " << pushTest.getSize()
        << ", capacity = " << pushTest.getCapacity() << std::endl;

    pushTest.push_back(40);
    std::cout << "size = " << pushTest.getSize()
        << ", capacity = " << pushTest.getCapacity() << std::endl;

    pushTest.push_back(50);
    std::cout << "size = " << pushTest.getSize()
        << ", capacity = " << pushTest.getCapacity() << std::endl;

    std::cout << "push_back test:" << std::endl;

    for (unsigned int i = 0; i < pushTest.getSize(); i++)
    {
        std::cout << pushTest[i] << std::endl;
    }
    std::cout << "Vector with operator<<: " << pushTest << std::endl;

    Vector<int> inputTest(3);

    std::cout << "Enter 3 values: ";
    std::cin >> inputTest;

    std::cout << "You entered: " << inputTest << std::endl;
    //перевірка  що конструктор копіювання переносить не тільки size, а й capacity.
    Vector<int> pushCopy(pushTest);

    std::cout << "Copy size = " << pushCopy.getSize()
        << ", capacity = " << pushCopy.getCapacity() << std::endl;

    std::cout << "Copy vector: " << pushCopy << std::endl;
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

// Dynamic_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Vector
{
private:
    unsigned int size = 0;
    int* dynamicArray = nullptr;

public:
    Vector(unsigned int sizeOfArray)
    {
        size = sizeOfArray;
        dynamicArray = new int[size];

        for (unsigned int i = 0; i < size; i++)
        {
            dynamicArray[i] = 0;
        }
    }

    ~Vector()
    {
        delete[] dynamicArray;
    }

    void resize(unsigned int newSize)
    {
        int* newArray = new int[newSize];

        unsigned int minSize = size;

        if (newSize < size)
        {
            minSize = newSize;
        }

        for (unsigned int i = 0; i < minSize; i++)
        {
            newArray[i] = dynamicArray[i];
        }

        for (unsigned int i = minSize; i < newSize; i++)
        {
            newArray[i] = 0;
        }

        delete[] dynamicArray;

        dynamicArray = newArray;
        size = newSize;
    }

    void set(unsigned int index, int newValue)
    {
        if (index >= size)
        {
            return;
        }

        dynamicArray[index] = newValue;
    }

    int get(unsigned int index) const
    {
        if (index >= size)
        {
            return 0;
        }

        return dynamicArray[index];
    }

    unsigned int getSize() const
    {
        return size;
    }
};

int main()
{
    Vector numbers(5);

    numbers.set(0,16);
    numbers.set(1, 02);
    numbers.set(2, 19);
    numbers.set(3, 84);
    numbers.set(4, 42);

    std::cout << "Old array:" << std::endl;

    for (unsigned int i = 0; i < numbers.getSize(); i++)
    {
        std::cout << numbers.get(i) << std::endl;
    }

    numbers.resize(8);

    std::cout << "New array:" << std::endl;

    for (unsigned int i = 0; i < numbers.getSize(); i++)
    {
        std::cout << numbers.get(i) << std::endl;
    }

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

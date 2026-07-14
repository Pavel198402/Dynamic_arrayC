#include "Vector.h"
Vector::Vector(unsigned int sizeOfArray)

{
    size = sizeOfArray;
    dynamicArray = new int[size];

    for (unsigned int i = 0; i < size; i++)
    {
        dynamicArray[i] = 0;
    }
}
Vector::~Vector()
{
    delete[] dynamicArray;
}
void Vector::resize(unsigned int newSize)
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
void Vector::set(unsigned int index, int newValue)

{
        if (index >= size)
        {
            return;
        }

        dynamicArray[index] = newValue;
}


 int Vector::get(unsigned int index) const
{
    if (index >= size)
    {
        return 0;
    }

    return dynamicArray[index];
}
unsigned int Vector::getSize() const
{
    return size;
}
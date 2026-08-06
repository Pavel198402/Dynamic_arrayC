#include "Vector.h"
#include <stdexcept>

bool Vector::operator!=(const Vector& other) const
{
    return !operator==(other);
}

bool Vector:: operator==(const Vector& other) const
{
	if (size != other.size)
	{
		return false;
	}
    for (unsigned int i = 0; i < size; i++)
    {
        if (dynamicArray[i] != other.dynamicArray[i])
        {
            return false;
        }
    }
    return true;

}
/*Назва оператора однакова, параметр index однаковий.
Вибір між версіями тут відбувається через константність самого об'єкта.
const int& Vector:: operator[](unsigned int index) const
{
	return dynamicArray[index];
}
*/
const int& Vector::operator[](unsigned int index) const
{
    if (index >= size)
    {
        throw std::out_of_range("operator[]: index is out of range");
    }

    return dynamicArray[index];
}

/*замінюємо використання set() на перевантажений operator[], 
щоб навчитися задавати поведінку[] для власного класу Vector.
int& Vector::operator[](unsigned int index)
{
    return dynamicArray[index];
}
*/
int& Vector::operator[](unsigned int index)
{
    if (index >= size)
    {
        throw std::out_of_range("operator[]: index is out of range");
    }

    return dynamicArray[index];
}

Vector& Vector::operator=(const Vector& other)
{
    if (this == &other)         //Перевіряє: чи не присвоюємо об'єкт самому собі
    {
        return *this;
    }
    
        delete[] dynamicArray;      // Звільняє старий dynamicArray поточного об'єкта
        this->size = other.size;        // Копіює size з other у поточний об'єкт
        this->dynamicArray = new int[size];

        for (unsigned int i = 0; i < size; i++)
        {
            this->dynamicArray[i] = other.dynamicArray[i];
        }
        return *this;
}

Vector::Vector(const Vector& other)
{
   
    size = other.size;
    dynamicArray = new int[size];

    for (unsigned int i = 0; i < size; i++)
    {
        dynamicArray[i] = other.dynamicArray[i];
    }
       
}
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
            throw std::out_of_range("set(): index is out of range");
        }

        dynamicArray[index] = newValue;
}


/* int Vector::get(unsigned int index) const
{
    if (index >= size)
    {
        return 0;
    }

    return dynamicArray[index];
}
*/

int Vector::get(unsigned int index) const
{
    if (index >= size)
    {
        throw std::out_of_range("get(): index is out of range");
    }

    return dynamicArray[index];
}

Vector::Vector()
{
}

Vector::operator bool() const
{
    return size != 0;
}
unsigned int Vector::getSize() const
{
    return size;
}
#pragma once
template <typename T>
class Vector
{
private:
    
    unsigned int size = 0;
    T* dynamicArray = nullptr;

public:
    explicit operator bool() const;
    Vector();
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;
	T& operator[](unsigned int index); // не константна версія оператора []
	const T& operator[](unsigned int index) const; // константна версія оператора []
    Vector(const Vector&);
    Vector& operator=(const Vector&);
  
    Vector(unsigned int sizeOfArray);
    
    ~Vector();

    void resize(unsigned int newSize);

    void set(unsigned int index, T newValue);

    T get(unsigned int index) const;

    unsigned int getSize() const;
};

template <typename T>
bool Vector<T>::operator!=(const Vector<T>& other) const
{
    return !operator==(other);
}
template <typename T>
bool Vector<T>::operator==(const Vector<T>& other) const
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
template <typename T>
const T& Vector<T>::operator[](unsigned int index) const
{
    if (index >= size)
    {
        throw std::out_of_range("operator[]: index is out of range");
    }

    return dynamicArray[index];
}
template <typename T>
T& Vector<T>::operator[](unsigned int index)
{
    if (index >= size)
    {
        throw std::out_of_range("operator[]: index is out of range");
    }

    return dynamicArray[index];
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this == &other)         //Перевіряє: чи не присвоюємо об'єкт самому собі
    {
        return *this;
    }

    delete[] dynamicArray;      // Звільняє старий dynamicArray поточного об'єкта
    this->size = other.size;        // Копіює size з other у поточний об'єкт
    this->dynamicArray = new T[size];

    for (unsigned int i = 0; i < size; i++)
    {
        this->dynamicArray[i] = other.dynamicArray[i];
    }
    return *this;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{

    size = other.size;
    dynamicArray = new T[size];

    for (unsigned int i = 0; i < size; i++)
    {
        dynamicArray[i] = other.dynamicArray[i];
    }

}
template <typename T>
Vector<T>::Vector(unsigned int sizeOfArray)
{

    size = sizeOfArray;
    dynamicArray = new T[size];

    for (unsigned int i = 0; i < size; i++)
    {
        dynamicArray[i] = T();
    }



}
template <typename T>
Vector<T>::~Vector()
{
    delete[] dynamicArray;
}
template <typename T>
void Vector<T>::resize(unsigned int newSize)
{
    T* newArray = new T[newSize];

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
        newArray[i] = T();
    }

    delete[] dynamicArray;
    dynamicArray = newArray;
    size = newSize;
}
template <typename T>
void Vector<T>::set(unsigned int index, T newValue)
{
    if (index >= size)
    {
        throw std::out_of_range("set(): index is out of range");
    }

    dynamicArray[index] = newValue;
}

template <typename T>
T Vector<T>::get(unsigned int index) const
{
    if (index >= size)
    {
        throw std::out_of_range("get(): index is out of range");
    }

    return dynamicArray[index];
}

template <typename T>
Vector<T>::Vector()
{
}

template <typename T>
Vector<T>::operator bool() const
{
    return size != 0;
}
template <typename T>
unsigned int Vector<T>::getSize() const
{
    return size;
}
#pragma once

class Vector
{
private:
    unsigned int size = 0;
    int* dynamicArray = nullptr;

public:
    Vector(unsigned int sizeOfArray);

    ~Vector();

    void resize(unsigned int newSize);

    void set(unsigned int index, int newValue);

    int get(unsigned int index) const;

    unsigned int getSize() const;
};
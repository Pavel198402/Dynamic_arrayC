#pragma once

class Vector
{
private:
    
    unsigned int size = 0;
    int* dynamicArray = nullptr;

public:
    explicit operator bool() const;
    Vector();
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;
	int& operator[](unsigned int index); // не константна версія оператора []
	const int& operator[](unsigned int index) const; // константна версія оператора []
    Vector(const Vector&);
    Vector& operator=(const Vector&);
  
    Vector(unsigned int sizeOfArray);

    ~Vector();

    void resize(unsigned int newSize);

    void set(unsigned int index, int newValue);

    int get(unsigned int index) const;

    unsigned int getSize() const;
};
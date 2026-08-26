#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T, std::size_t N>
class StaticArray
{
private:
    T data_[N]{};

public:
    std::size_t getSize() const;

    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;
    void set(std::size_t index, T value);
    T get(std::size_t index) const;
    explicit operator bool() const;
    bool operator==(const StaticArray<T, N>& other) const;
    bool operator!=(const StaticArray<T, N>& other) const;

};
template <typename T, std::size_t N>
std::size_t StaticArray<T, N>::getSize() const
{
    return N;
}


template <typename T, std::size_t N>
T& StaticArray<T, N>::operator[](std::size_t index)
{
    if (index >= N)
    {
        throw std::out_of_range("operator[]: index is out of range");
    }

    return data_[index];
}
template <typename T, std::size_t N>
const T& StaticArray<T, N>::operator[](std::size_t index) const
{
    if (index >= N)
    {
        throw std::out_of_range("operator[]: index is out of range");
    }

    return data_[index];
}
template <typename T, std::size_t N>
void StaticArray<T, N>::set(std::size_t index, T value)
{
    if (index >= N)
    {
        throw std::out_of_range("set(): index is out of range");
    }

    data_[index] = value;
}
// template <typename T, std::size_t N>
template <typename T, std::size_t N>
T StaticArray<T, N>::get(std::size_t index) const
{
    if (index >= N)
    {
        throw std::out_of_range("get(): index is out of range");
    }

    return data_[index];
}
//
template <typename T, std::size_t N>
StaticArray<T, N>::operator bool() const
{
    return N != 0;
}
template <typename T, std::size_t N>
bool StaticArray<T, N>::operator==(const StaticArray<T, N>& other) const
{
    for (std::size_t i = 0; i < N; i++)
    {
        if (data_[i] != other.data_[i])
        {
            return false;
        }
    }

    return true;
}

template <typename T, std::size_t N>
bool StaticArray<T, N>::operator!=(const StaticArray<T, N>& other) const
{
    return !(*this == other);
}
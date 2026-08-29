#pragma once
#include "Vector.h"
template <typename T>
void insertion_sort(Vector<T>& arr)
{
    for (unsigned int i = 1; i < arr.getSize(); ++i)
    {
        T value = arr[i];
        unsigned int j = i;

        while (j > 0 && arr[j - 1] > value)
        {
            arr[j] = arr[j - 1];
            --j;
        }

        arr[j] = value;
    }
}
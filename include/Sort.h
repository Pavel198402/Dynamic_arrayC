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
template <typename T>
void bubble_sort(Vector<T>& arr)
{
    for (unsigned int i = 0; i < arr.getSize(); ++i)
    {
        for (unsigned int j = 0; j + 1 < arr.getSize() - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
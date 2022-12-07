#ifndef INSERTION_LIB
#define INSERTION_LIB

#include <vector>
#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void insert_sort(std::vector <int> &arr)
{
    // pass through all elements
    // swaping the greater element to the end
    int len = arr.size();
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] < arr[j]){
                // TODO: understand this condition
                swap(arr[i], arr[j]);
            }
        }
    }
}

#endif
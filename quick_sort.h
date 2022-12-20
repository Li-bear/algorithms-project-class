#ifndef QUICK_SORT_LIB  
#define QUICK_SORT_LIB

#include <vector>
#include <algorithm>
#include <iostream>

void quick_part(std::vector <int> &vec, int left, int right);

int partition_last(std::vector <int> &vec, int left, int right)
{
    int pivot = vec[left];
    int leftBigger = left + 1;
    int rightSmaller = right;
    int count_smaller = 0;
    
    while (leftBigger < rightSmaller){
        if (vec[rightSmaller] <= pivot)
        {
            if (vec[leftBigger] <= pivot)
                leftBigger++;
            else if (vec[leftBigger] >= vec[rightSmaller])
            {
                std::swap(vec[leftBigger], vec[rightSmaller]);
                leftBigger++;
            }
            count_smaller++;
        }
        else
            rightSmaller--;
    }
    std::swap(vec[left], vec[leftBigger + 1]);
    return leftBigger + 1;   
}

void print(std::vector <int> &vec)
{
    for (int i= 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

void quick_sort(std::vector <int> &vec){
    int left = 0;
    int right = vec.size() - 1;

    if (vec.size() > 1)
    {
        quick_part(vec, left, right);
    }
}

void quick_part(std::vector <int> &vec, int left, int right){
    int pivot = partition_last(vec, left, right);
    // TODO: FIX CONDITION
    if (left < right){
        quick_part(vec, left, pivot - 1);
        quick_part(vec, pivot + 1, right);
        print(vec);
        //pivot = partition_last(vec, left, right);
    }
}

#endif
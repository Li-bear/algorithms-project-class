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
    int count_smaller = left + 1;
    
    while (leftBigger <= rightSmaller){
        if (vec[leftBigger] > pivot && vec[rightSmaller] < pivot)
        {
            std::swap(vec[leftBigger], vec[rightSmaller]);
            //rightSmaller--;
            //leftBigger++;
        }
        
        if (vec[rightSmaller] > pivot)
            rightSmaller--;
        
        if (vec[leftBigger] <= pivot)
            leftBigger++;
    }

    std::swap(vec[left], vec[rightSmaller]);
    return rightSmaller;   
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
    // TODO: FIX CONDITION
    if (left < right){
        int pivot = partition_last(vec, left, right);
        quick_part(vec, left, pivot - 1);
        // TODO: something weird happen when left part is called
        quick_part(vec, pivot + 1, right);
        // print(vec);
        //pivot = partition_last(vec, left, right);
    }
}

#endif
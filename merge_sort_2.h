#ifndef MERGE_SORT
#define MERGE_SORT

#include <vector>
#include <iostream>
void merge(std::vector <int> &vec, int index_left, int index_mid, int index_right, std::vector<int> &temp);
void divide_vector(std::vector <int> &vec, int index_begin, int index_end, std::vector <int> &temp);

void merge_sort(std::vector <int> &vec){
    // Declare three indexes to divide the array
    int index_left = 0;
    int index_mid = vec.size() / 2;
    int index_right = vec.size();
    
    // Create and reserve memory of a temporary array
    std::vector <int> temp(vec.size());
    //temp.reserve(vec.size());
    
    // Check array size bc 1 means that is already sorted
    if (vec.size() != 1)
    {
        divide_vector(vec, index_left, index_right, temp);
    }

}

void divide_vector(std::vector <int> &vec, int index_begin, int index_end, std::vector <int> &temp)
{
    if (index_begin + 1 < index_end )
    {
        int index_mid = (index_end - index_begin) / 2;
        //std::cout << index_begin << " " << index_mid << " " <<index_end << std::endl;
        divide_vector(vec, index_begin, index_begin + index_mid, temp);
        divide_vector(vec, index_begin + index_mid , index_end, temp);
        merge(vec, index_begin, index_begin + index_mid, index_end, temp);
    }
}


void merge(std::vector <int> &vec, int index_left, int index_mid, int index_right, std::vector<int> &temp)
{
    int index_l = index_left;
    int index_m = index_mid;
    int index_temp = index_l;

    while(index_l < index_mid && index_m < index_right)
    {
        if (vec[index_l] >= vec[index_m])
        {
            temp[index_temp] = vec[index_m];
            index_m++;
            
        }
        else
        {
            temp[index_temp] = vec[index_l];
            index_l++;
        }
        index_temp++;
    }

    while (index_l < index_mid)
    {
        temp[index_temp] = vec[index_l];
        index_temp++;
        index_l++;
    }

    while (index_m < index_right)
    {
        temp[index_temp] = vec[index_m];
        index_temp++;
        index_m++;
    }

    for (int i= index_left; i < index_right; i++)
    {
        vec[i] = temp[i];
    }
}


#endif
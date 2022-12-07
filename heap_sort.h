#ifndef HEAPSORT_LIB
#define HEAPSORT_LIB

#include <vector>
#include <iostream>


void swap(int &a, int &b);
void fix_heap(std::vector <int> &vec, int i, int largest);
void largest_2back(std::vector <int> &vec, int &h);

void heap_sort(std::vector <int> &vec)
{
    /// @brief fix heap from the back, reduce size and swap largest
    /// number to the end and fix heap from the back again.
    /// @param vec 

    int h = vec.size();
    // building heap

    for (int i = vec.size() - 1; i >=0; i--)
    {
        fix_heap(vec, i, h);
    }

    for (int repetitions  = 0; repetitions < vec.size(); repetitions++){
        largest_2back(vec, h);
        fix_heap(vec, 0, h);
    }
}

void largest_2back(std::vector <int> &vec, int &h)
{
    swap(vec[0], vec[h - 1]);
    h--;
}

void fix_heap(std::vector <int> &vec, int i, int h)
{
    int heap = vec[i];
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (right < h)
    {
        int l_child = vec[left];
        int r_child = vec[right];
        if (r_child > heap && r_child >= l_child) {
            swap(vec[i], vec[right]);
            fix_heap(vec, right, h);
        }
        else if (l_child > heap && l_child >= r_child)
        {
            swap(vec[i], vec[left]);
            fix_heap(vec, left, h);
        }
    }
    // only one child
    else if (left < h)
    {
        int l_child = vec[left];
        if (heap < l_child)
        {
            swap(vec[i], vec[left]);
        }
    }
}


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

#endif
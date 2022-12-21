#include "merge_sort_2.h"
#include <vector>
#include <iostream>

int main()
{
    std::vector <int> xs {7, 2, 5, -2, 0, 1, 9, 2, 8, 0, 100, -9, 6, -32, 3};
    merge_sort(xs);
    std::vector <int> xs_sorted {-2, 0, 1, 2, 2, 5, 7, 9};
    if (xs != xs_sorted)
        std::cout << "Merge sort does not work" << std::endl;


    std::vector <int> ys {2, 0, 0, -1, -1};
    merge_sort(ys);
    
    std::vector <int> ys_sorted {-1, -1, 0, 0, 2};
    if (ys != ys_sorted)
        std::cout << "Heap sort does not work" << std::endl;
    return 0;
}
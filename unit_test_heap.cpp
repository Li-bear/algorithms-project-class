#include "heap_sort.h"
#include <vector>
#include <iostream>

int main()
{
    
    std::vector <int> xs {7, 2, 5, -2, 0, 1, 9, 2};
    heap_sort(xs);
    for (int i= 0; i < xs.size(); i++)
        std::cout << xs[i] << " ";
    std::cout << std::endl;

    std::vector <int> xs_sorted {-2, 0, 1, 2, 2, 5, 7, 9};
    if (xs != xs_sorted)
        std::cout << "Heap sort does not work" << std::endl;
    

    std::vector <int> ys {2, 0, 0, -1, -1};
    heap_sort(ys);
    for (int i= 0; i < ys.size(); i++)
        std::cout << ys[i] << " ";
    std::cout << std::endl;
    
    std::vector <int> ys_sorted {-1, -1, 0, 0, 2};
    if (ys != ys_sorted)
        std::cout << "Heap sort does not work" << std::endl;
    

    return 0;
}
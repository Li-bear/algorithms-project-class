#include "quick_sort.h"
#include <vector>
#include <iostream>

int main()
{
    
    std::vector <int> xs {4, 7, 2, 5, -2, 0, 1, 9, 2};
    quick_sort(xs);
    for (int i= 0; i < xs.size(); i++)
        std::cout << xs[i] << " ";
    std::cout << std::endl;
    std::vector <int> ys {-6, 1, 23, -100, -5, 76};
    
    quick_sort(ys);
    for (int i= 0; i < ys.size(); i++)
        std::cout << ys[i] << " ";
    std::cout << std::endl;
    /*
    std::vector <int> xs_sorted {-2, 0, 1, 2, 2, 5, 7, 9};
    if (xs != xs_sorted)
        std::cout << "Merge sort does not work" << std::endl;
    */

    std::vector <int> zs {4, 3, 5, 6, 8, 1, 0, 10, -2, 7, 1};
    quick_sort(zs);
    for (int i= 0; i < zs.size(); i++)
        std::cout << zs[i] << " ";
    std::cout << std::endl;
    /*
    */

   std::vector <int> zs2 {4, -100, 3, 5, 6, 7, 8, 1, 0, 10, -2, 7, 1};
    quick_sort(zs2);
    for (int i= 0; i < zs2.size(); i++)
        std::cout << zs2[i] << " ";
    std::cout << std::endl;
    
    return 0;
}
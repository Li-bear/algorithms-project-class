#include "insert_sort.h"
#include <vector>
#include <iostream>

int main()
{
    std::vector <int> xs {7, 2, 5, -2, 0, 1, 9, 2};
    insert_sort(xs);
    std::vector <int> xs_sorted {-2, 0, 1, 2, 2, 5, 7, 9};
    if (xs != xs_sorted)
        std::cout << "insert sort does not work" << std::endl;
    

    std::vector <int> ys {2, 0, 0, -1, -1};
    insert_sort(ys);
    std::vector <int> ys_sorted {-1, -1, 0, 0, 2};
    if (ys != ys_sorted)
        std::cout << "insert sort does not work" << std::endl;


    std::vector zs {9, 8, 7, 6, 5, 4};
    insert_sort(zs);
    std::vector <int> zs_sorted {4, 5, 6, 7, 8, 9};
    if (zs != zs_sorted)
        std::cout << "Test 3. Insert does not work" << std::endl;

    return 0;
}
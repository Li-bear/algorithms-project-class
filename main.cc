#include <algorithm>
#include <chrono>
#include <cassert>
#include <iostream>
#include <random>
#include "insert.h"
#include "heap_sort.h"
#include "merge_sort_2.h"
#include "quick_sort.h"
#include <fstream>
#include <vector>

constexpr int step = 50;
constexpr int maxlen = 1000; // 10000
constexpr int times = 100;

using std::chrono::nanoseconds;


nanoseconds timeit(std::vector <int> original, std::vector <int> &vec, void what(std::vector <int> &vec)){
    //std::vector <int> vec;
    vec = original;
    auto begin = std::chrono::steady_clock::now();
    what(vec);
    auto end = std::chrono::steady_clock::now();
    
    nanoseconds total(end - begin);
    return total;
}


int main() {
    std::random_device rd;
    //std::mt19937 gen(rd());
    // I have to change the seed bc my laptot was producing the same value
    std::mt19937 gen(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::ofstream file;
    file.open("results_small.txt");
    file << "Len" << "\tInsertion" << "\tHeap sort" << "\tMerge sort"<< "\tQuick sort" << std::endl;
    
    for (int len = step ; len < maxlen ; len += step) {
        nanoseconds ins(0);
        nanoseconds heap(0);
        nanoseconds merge_t(0);
        nanoseconds quick_t(0);


        std::vector <int> original(len);
        // full original vector with values from 0 to its length
        for (int i = 0 ; i < len ; i++) {
            //original.push_back(i);
            original[i] = i;
        }

        std::vector <int> vec(len);


        for (int t = 0 ; t < times ; t++) {
            // shuffle the array
            std::shuffle(original.begin(), original.end(), gen);

            ins += timeit(original, vec, &insert_sort);
            heap += timeit(original, vec, &heap_sort);
            quick_t += timeit(original, vec, &quick_sort);
            merge_t += timeit(original, vec, &merge_sort);
        }

        file
            << len << "\t"
            << ins.count() / times << "\t"
            << heap.count() / times << "\t"
            << merge_t.count() / times << "\t"
            << quick_t.count() / times
            << std::endl;
    }
    return 0;
}

#ifndef INSERT_H
#define INSERT_H

#include <vector>

void insert_sort(std::vector <int> &vec){
    for (int i = 1 ; i < vec.size() ; i++) {
        int val = vec[i];
        int cur = i;
        while ( (cur > 0) && vec[cur - 1] > val ) {
            vec[cur] = vec[cur - 1];
            cur--;
        }
        vec[cur] = val;
    }
}


#endif  // INSERT_H

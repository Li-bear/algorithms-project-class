#ifndef MERGESORT_LIB
#define MERGESORT_LIB

#include <vector>
#include <iostream>

std::vector <int> sub_sort(std::vector <int> &right, std::vector <int> &left);
std::vector <int> sort_3(std::vector <int> &v2sort, int index_l, int index_r);
void sub_sort_2(std::vector <int> &vec, int begin_left, int begin_right);

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void merge_sort(std::vector <int> &vec)
{
    // [?] for by pairs
    std::vector <int> sorted;
    if (vec.size() == 1)
    {
        if (vec[0] > vec[1])
            swap(vec[0], vec[1]);
    }
    else
    {
        std::vector <int> sub_vec (vec.begin(), vec.begin() + vec.size() / 2);
        merge_sort(sub_vec);
    }
}

void merge_sort_2(std::vector <int> &vec)
{
    for (int i = 0; i < vec.size(); i +=2)
    {
        if (vec.size() % 2 != 0  && i == vec.size() - 1)
            break;
        else
        {
            if (vec[i] > vec[i+1])
                swap(vec[i], vec[i+1]);
        }
    }

    for (int i = 0; i < vec.size(); i +=4)
    {
        if (vec.size() % 2 != 0  && i == vec.size() - 1)
            break;
        //else
        //{
            
            //vec = sub_sort(vec);
        //}
    }
}


void merge_sort_3(std::vector <int> &v2sort)
{
    int index_l = 0;
    int index_r = v2sort.size();
    int index_m = index_l + (index_r - index_l) / 2;
    int group = 2;
    std::vector <int> merged;

    while (group < v2sort.size())
    {
        for (int i = 0; i < v2sort.size(); i+= group)
        {
            std::vector left(v2sort.begin(), v2sort.begin() + group); // 2
            std::vector right(v2sort.begin() + group, v2sort.end()); // 4
            merged = sub_sort(left, right);
        }
        group *= 2;
    }

    
    for (int i= 0; i < merged.size(); i++)
        std::cout << merged[i] << " ";
    std::cout << std::endl;
    /*
    for (int i= 0; i < right.size(); i++)
        std::cout << right[i] << " ";
    std::cout << std::endl;
    */
}

void merge_sort_4(std::vector <int> &v2sort)
{
    /// @brief four attempt using a sub_sort with vector and indixes as parameters
    int index_l = 0;
    int index_r = v2sort.size();
    // int index_m = index_l + (index_r - index_l) / 2;
    int group = 2;

    while (group < v2sort.size())
    {
        // [?] debugging it works for pairs but not more
        for (int i = 0; i < v2sort.size(); i+= group)
        {
            index_l = i;
            index_r = i + group - 1;
            sub_sort_2(v2sort, index_l, index_r);
        }
        group *= 2;
    }
}


std::vector <int> sub_sort(std::vector <int> &left, std::vector <int> &right)
{
    // TODO: maybe you dont need to pass the vector splitted, only indices
    int index_l = 0;
    int index_r = 0;
    int index_o = 0;
    std::vector <int> output;
    int amount_elements = right.size() + left.size();
    //int amount_elements = v2sort.size();
    // [?] Index o or output.size()
    while (amount_elements != output.size())
    {
        if (left[index_l] > right[index_r])
        {
            output.push_back(right[index_r]);
            index_r++;
        }
        else if (left[index_l] < right[index_r])
        {
            output.push_back(left[index_l]);
            index_l++;
        }
        else
        {
            output.push_back(right[index_r]);
            output.push_back(left[index_l]);
            index_r++;
            index_l++;
        }
    }
    return output;
}


void sub_sort_2(std::vector <int> &vec, int begin_left, int begin_right)
{
    int index_l = begin_left;
    int index_r = begin_right;
    int elements_changed = begin_right - begin_left;
    std::vector <int> output;
    output.reserve(elements_changed);

    // int amount_elements = begin_right - begin_left;
    //int amount_elements = v2sort.size();
    // [?] Index o or output.size()
    //std::vector <int> temp (vec.begin() + begin_left, vec.begin() + begin_right);
    for (int i = 0; i < elements_changed; i++)
    {
        if (vec[index_l] > vec[index_r])
        {
            //swap(vec[index_l], vec[index_r]);
            output.push_back(vec[index_r]);
            index_r++;
        }
        else if (vec[index_l] < vec[index_r])
        {
            //swap(vec[index_l], vec[index_r]);
            output.push_back(vec[index_l]);
            index_l++;
        }
    }
}

#endif
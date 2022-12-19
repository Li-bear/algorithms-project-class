#ifndef QUICK_SORT_LIB  
#define QUICK_SORT_LIB

#include <vector>
#include <algorithm>
#include <iostream>

/*
Elegir un elemento del conjunto de elementos a ordenar, al que llamaremos pivote.
Resituar los demás elementos de la lista a cada lado del pivote, de manera que a un lado queden todos los menores que él, y al otro los mayores. Los elementos iguales al pivote pueden ser colocados tanto a su derecha como a su izquierda, dependiendo de la implementación deseada. En este momento, el pivote ocupa exactamente el lugar que le corresponderá en la lista ordenada.
La lista queda separada en dos sublistas, una formada por los elementos a la izquierda del pivote, y otra por los elementos a su derecha.
Repetir este proceso de forma recursiva para cada sublista mientras éstas contengan más de un elemento. Una vez terminado este proceso todos los elementos estarán ordenados.
*/

void vec_partition(std::vector <int> &vec);

void quicksort(std::vector <int> &vec)
{
    /*
    int pivot_index = 0;
    int pivot_num = vec[0];
    while (pivot_index != vec.size())
    {
        for (int i = 1; i < vec.size(); i++){
        if (vec[i] < pivot_num)
        {
            std::swap(vec[pivot_index], vec[i]);
            pivot_index = i;
        }
        // partition when is bigger? 
    }
    }
    */
}


void vec_partition(std::vector <int> &vec)
{
    int pivot_num = vec[0];
    int pivot_index = 0;
    int greater_index = 0;
    int num_greater = 0;
    int smaller_index = 1;
    int index = 1;

    while (greater_index > smaller_index)
    {
        if (vec[index] <= pivot_num)
            smaller_index = index;
        else
        {
            greater_index = index;
        }  
        index++;
    }
    /*
    for (int i = 1; i < vec.size(); i++){
        if (vec[i] > pivot_num)
        {
            //greater_index = i;
            num_greater += 1;
        }
        else if (vec[i] < pivot_num){
            for (int j = 0; j < num_greater; j ++)
            {
                std::swap(vec[j], vec[i]);
                pivot_index = i;
            }
        }
    }
    */
}

void part(std::vector <int> &vec)
{
    int smaller = 0;
    int bigger = 0;
    int pivot = vec[0];
    int elements = 0;
    for (int i = 1; i< vec.size(); i++){
        if (vec[i] > pivot)
        {
            std::cout << "bigger: " << vec[i] <<std::endl;
            bigger = i;
            elements++;
        }
        else
        {
            std::cout << "smaller: " << vec[i] << std::endl;
            smaller = i;         
        }
        /*
        if (bigger < smaller && bigger && smaller)
        {
            for (int j = 0; j < elements; j++){
                std::swap(vec[smaller], vec[bigger - elements]);
                elements--;
            }
        } 
        */
        while (smaller > bigger){
            std::swap(vec[bigger], vec[smaller]);
            int tmp = bigger;
            bigger = smaller;
        }      
    }
    
}


void partition_last(std::vector <int> &vec, int left, int right)
{
    if (right > 1)
    {
        int pivot = vec[0];
        int leftBigger = 1;
        int rightSmaller = vec.size() - 1;
        while (leftBigger < rightSmaller){
            if (vec[rightSmaller] <= pivot)
            {
                if (vec[leftBigger] < pivot)
                    leftBigger++;
                else if (vec[leftBigger] >= vec[rightSmaller])
                {
                    std::swap(vec[leftBigger], vec[rightSmaller]);
                    leftBigger++;
                }
            }
            else
                rightSmaller--;
        }
        std::swap(vec[0], vec[leftBigger - 1]);
    }
}

void quick(std::vector <int> &vec){
    partition_last(vec, 1, vec.size() - 1);
}



void part_list(std::vector <int> &vec, std::vector<int> &temp){
    std::vector <int> smaller;
    std::vector <int> greater;
    int pivot = vec[0];
    while (vec.size() > 1){
        for(int i = 1; i < vec.size(); i++)
        {
            if (vec[i] <= pivot)
                smaller.push_back(vec[i]);
            else
                greater.push_back(vec[i]);
        }

        temp[smaller.size()] = pivot;

        if (smaller.size() > 0)
            part_list(smaller, temp);
        if (greater.size() > 0)
            part_list(greater, temp);
    }
    
    //for (int i= 0; i < smaller.size(); i++)
    //    std::cout << smaller[i] << " ";
    
    //std::cout << pivot << " ";
    
    //for (int i= 0; i < greater.size(); i++)
    //    std::cout << greater[i] << " ";
    //std::cout << std::endl;
    
    
}


void quick_sort2(std::vector <int> &vec){
    std::vector <int> temp(vec.size());
    part_list(vec, temp);
    //vec = temp;
}

#endif
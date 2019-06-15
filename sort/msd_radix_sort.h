#ifndef ALGOS_SORT_MSD_RADIX_SORT_H_
#define ALGOS_SORT_MSD_RADIX_SORT_H_

#include<vector>
#include<string>
#include<iostream>

int GetCharAt(const std::string &a_string, int index);


void RecursiveRadix(std::vector<std::string> *a_vector, \
                    int radix, int string_index, int sort_from, int sort_to, \
                    std::vector<std::string> *aux_vector);

void MSDRadixSort(std::vector<std::string> *a_vector, int radix);


#endif // ALGOS_SORT_MSD_RADIX_SORT_H_

#include<vector>
#include<iostream>
#include<string>
#include"../sort/sort_utils.h"
#include"three_way_radix.h"


void RecursiveRadixQuickSort(std::vector<std::string> *a_vector, \
                             int sort_from, int sort_to, int string_index) {

  if (sort_from >= sort_to)
    return;

  char v = GetCharAt((*a_vector)[sort_from], string_index);
  int i = sort_from;
  int lt = sort_from;
  int gt = sort_to;

  while (i <= gt) {
    if (GetCharAt((*a_vector)[i], string_index) < v) {
      Swap(a_vector, i, lt);
      i++;
      lt++;
    } else if (GetCharAt((*a_vector)[i], string_index) > v) {
      Swap(a_vector, i, gt);
      gt--;
    } else {
      i++;
    }
  }

  RecursiveRadixQuickSort(a_vector, sort_from, lt - 1, string_index);
  RecursiveRadixQuickSort(a_vector, gt + 1, sort_to, string_index);
  RecursiveRadixQuickSort(a_vector, lt, gt, string_index + 1);
}


void RadixQuickSort(std::vector<std::string> *a_vector) {
  RecursiveRadixQuickSort(a_vector, 0, a_vector->size() - 1, 0);
}


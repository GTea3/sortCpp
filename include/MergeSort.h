#ifndef SORT_MERGESORT_H
#define SORT_MERGESORT_H

#include "Sort.h"

template <typename T>
class MergeSort : public Sort<T> {
public:
    static void sort(std::vector<T>&);
};

#endif //SORT_MERGESORT_H

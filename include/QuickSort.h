#ifndef SORT_QUICKSORT_H
#define SORT_QUICKSORT_H

#include "Sort.h"

template <typename T>
class QuickSort : public Sort<T> {
public:
    static void sort(std::vector<T>&);
};

#endif //SORT_QUICKSORT_H

#ifndef SORT_INSERTIONSORT_H
#define SORT_INSERTIONSORT_H

#include "Sort.h"

template <typename T>
class InsertionSort : public Sort<T> {
public:
    static void sort(std::vector<T>&);
};

#endif //SORT_INSERTIONSORT_H

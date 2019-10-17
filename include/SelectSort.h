#ifndef SORT_SELECTSORT_H
#define SORT_SELECTSORT_H

#include "Sort.h"

template <typename T>
class SelectSort : public Sort<T> {
public:
    static void sort(std::vector<T>&);
};

#endif //SORT_SELECTSORT_H

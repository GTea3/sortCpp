#ifndef SORT_BUBBLESORT_H
#define SORT_BUBBLESORT_H

#include "Sort.h"

template <class T>
class BubbleSort : public Sort<T> {
public:
    static void sort(std::vector<T>&);
};

#endif //SORT_BUBBLESORT_H

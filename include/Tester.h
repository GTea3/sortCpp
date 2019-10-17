#ifndef SORT_TESTER_H
#define SORT_TESTER_H

#include <vector>
#include <functional>
#include <limits>
#include <random>

template <class T>
class Tester {
private:
    static T random(T min, T max);
    static std::vector<T> randomVector(size_t size, T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max());
    static void testThis(std::function<void(std::vector<T>&)> baseline, std::vector<std::pair<std::function<void(std::vector<T>&)>, std::string>> toBeTested, int testsCount, size_t testsSize = 100, T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max());
public:
    static void test(int testsCount, size_t testsSize);
};

#endif //SORT_TESTER_H

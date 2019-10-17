//
// Created by wright on 2019-09-28.
//

#include "Tester.h"

#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <iomanip>

#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

template class Tester<int>;

template <typename ResultT, typename TimeT = std::chrono::milliseconds>
struct measure
{
    template<typename F, typename ...Args>
    static typename std::pair<ResultT, typename TimeT::rep> execution(F&& func, Args&&... args)
    {
        auto start = std::chrono::steady_clock::now();
        ResultT result = std::forward<decltype(func)>(func)(std::forward<Args>(args)...);
        auto duration = std::chrono::duration_cast<TimeT>(std::chrono::steady_clock::now() - start);
        return {result, duration.count()};
    }
};

thread_local std::mt19937 gen{std::random_device{}()};

template <typename T>
T Tester<T>::random(T min, T max) {
    using dist = std::conditional_t<std::is_integral<T>::value, std::uniform_int_distribution<T>, std::uniform_real_distribution<T>>;
    return dist{min, max}(gen);
}

template <typename T>
std::vector<T> Tester<T>::randomVector(size_t size, T min, T max) {
    std::vector<T> v(size);
    std::generate(v.begin(), v.end(), [min, max] () -> T { return random(min, max); });
    return v;
}

template <typename T>
void Tester<T>::testThis(std::function<void(std::vector<T>&)> baseline, std::vector<std::pair<std::function<void(std::vector<T>&)>, std::string>> toBeTested, int testsCount, size_t testsSize, T min, T max) {
    std::vector<std::vector<T>> tests(testsCount, std::vector<T>(testsSize));
    std::vector<std::vector<T>> sorted(testsCount, std::vector<T>(testsSize));
    for(auto i = 0; i < testsCount; ++i) {
        tests.at(i) = randomVector(testsSize, min, max);
        sorted.at(i) = tests.at(i);
        baseline(sorted.at(i));
    }

    size_t maxStringLength = 0;
    for(auto [f, s] : toBeTested) {
        maxStringLength = std::max(maxStringLength, s.length());
    }
    for(auto [f, s] : toBeTested) {
        std::function<int()> test = [testsCount, tests, sorted, f] () -> int {
            size_t correct = 0;
            for(auto i = 0; i < testsCount; ++i) {
                std::vector<T> toBeSorted = tests.at(i);
                f(toBeSorted);
                if (toBeSorted == sorted.at(i))
                    ++correct;
            }
            return correct;
        };
        auto res = measure<int>::execution(test);
        std::cout << s << ":" << std::string(maxStringLength - s.length() + 1, ' ') << std::setfill(' ') << std::setw(log10(testsCount) + 1) << res.first << "/" << testsCount << " " << (res.first == testsCount ? "[ OK ]" : "[FAIL]") << " (" << res.second << "ms)\n";
    }
    std::cout << std::flush;
}

template <class T>
void Tester<T>::test(int testsCount, size_t testsSize) {
    std::vector<std::pair<std::function<void(std::vector<T>&)>, std::string>> toBeTested = {
            {BubbleSort<T>::sort,    "bubble sort"},
            {SelectSort<T>::sort,    "select sort"},
            {InsertionSort<T>::sort, "insert sort"},
            {MergeSort<T>::sort,     "merge sort"},
            {QuickSort<T>::sort,     "quick sort"}
    };

    testThis([] (std::vector<T>& v) -> void { std::sort(v.begin(), v.end()); }, toBeTested, testsCount, testsSize);
}

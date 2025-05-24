#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <chrono>


class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void sortAndMeasure(const std::vector<int>& input);

private:
    void mergeInsertSort(std::vector<int>& container);
    void mergeInsertSort(std::deque<int>& container);
};

#endif
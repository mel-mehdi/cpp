#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <utility> // for std::pair
#include <ctime>   // instead of chrono
#include <cstdlib> // for std::atoi
class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    
    void mergeInsertSort(std::vector<int>& container);
    void mergeInsertSort(std::deque<int>& container);
    void sortAndMeasure(const std::vector<int>& input);
};

#endif
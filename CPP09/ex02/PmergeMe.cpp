#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::mergeInsertSort(std::vector<int>& container) {
    // Implement merge-insert sort for vector
}

void PmergeMe::mergeInsertSort(std::deque<int>& container) {
    // Implement merge-insert sort for deque
}

void PmergeMe::sortAndMeasure(const std::vector<int>& input) {
    std::vector<int> vec(input.begin(), input.end());
    std::deque<int> deq(input.begin(), input.end());

    auto start = std::chrono::high_resolution_clock::now();
    mergeInsertSort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Time to process with vector: " 
              << std::chrono::duration<double, std::micro>(end - start).count() 
              << " us" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    mergeInsertSort(deq);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Time to process with deque: " 
              << std::chrono::duration<double, std::micro>(end - start).count() 
              << " us" << std::endl;
}
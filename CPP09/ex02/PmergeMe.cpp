#include "PmergeMe.hpp"
#include <ctime>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::mergeInsertSort(std::vector<int>& container) {
    if (container.size() <= 1)
        return;
    
    // Recursion base case
    if (container.size() == 2) {
        if (container[0] > container[1])
            std::swap(container[0], container[1]);
        return;
    }
    
    // Step 1: Create pairs from the elements
    std::vector<std::pair<int, int> > pairs; // Fixed nested template syntax
    size_t unpaired = 0;
    bool hasUnpaired = false;
    
    if (container.size() % 2 != 0) {
        unpaired = container.back();
        hasUnpaired = true;
        container.pop_back();
    }
    
    for (size_t i = 0; i < container.size(); i += 2) {
        int first = container[i];
        int second = container[i + 1];
        if (first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }
    
    // Step 2: Extract the larger elements and sort them recursively
    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        largerElements.push_back(pairs[i].second);
    }
    
    mergeInsertSort(largerElements);
    
    // Step 3: Initialize result with the first small element and the sorted larger elements
    std::vector<int> result;
    result.push_back(pairs[0].first);
    
    for (size_t i = 0; i < largerElements.size(); i++) {
        result.push_back(largerElements[i]);
    }
    
    // Step 4: Insert the remaining small elements using binary search
    for (size_t i = 1; i < pairs.size(); i++) {
        int element = pairs[i].first;
        
        // Binary search to find insertion point
        size_t left = 0;
        size_t right = i + 1;
        
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < element)
                left = mid + 1;
            else
                right = mid;
        }
        
        // Insert at the correct position
        result.insert(result.begin() + left, element);
    }
    
    // Step 5: Insert the unpaired element if there was one
    if (hasUnpaired) {
        // Binary search to find insertion point for unpaired element
        size_t left = 0;
        size_t right = result.size();
        
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < static_cast<int>(unpaired)) // Fixed sign comparison
                left = mid + 1;
            else
                right = mid;
        }
        
        result.insert(result.begin() + left, unpaired);
    }
    
    // Copy result back to the container
    container = result;
}

void PmergeMe::mergeInsertSort(std::deque<int>& container) {
    if (container.size() <= 1)
        return;
    
    // Recursion base case
    if (container.size() == 2) {
        if (container[0] > container[1])
            std::swap(container[0], container[1]);
        return;
    }
    
    // Step 1: Create pairs from the elements
    std::deque<std::pair<int, int> > pairs; // Fixed nested template syntax
    size_t unpaired = 0;
    bool hasUnpaired = false;
    
    if (container.size() % 2 != 0) {
        unpaired = container.back();
        hasUnpaired = true;
        container.pop_back();
    }
    
    for (size_t i = 0; i < container.size(); i += 2) {
        int first = container[i];
        int second = container[i + 1];
        if (first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }
    
    // Step 2: Extract the larger elements and sort them recursively
    std::deque<int> largerElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        largerElements.push_back(pairs[i].second);
    }
    
    mergeInsertSort(largerElements);
    
    // Step 3: Initialize result with the first small element and the sorted larger elements
    std::deque<int> result;
    result.push_back(pairs[0].first);
    
    for (size_t i = 0; i < largerElements.size(); i++) {
        result.push_back(largerElements[i]);
    }
    
    // Step 4: Insert the remaining small elements using binary search
    for (size_t i = 1; i < pairs.size(); i++) {
        int element = pairs[i].first;
        
        // Binary search to find insertion point
        size_t left = 0;
        size_t right = i + 1;
        
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < element)
                left = mid + 1;
            else
                right = mid;
        }
        
        // Insert at the correct position
        result.insert(result.begin() + left, element);
    }
    
    // Step 5: Insert the unpaired element if there was one
    if (hasUnpaired) {
        // Binary search to find insertion point for unpaired element
        size_t left = 0;
        size_t right = result.size();
        
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < static_cast<int>(unpaired)) // Fixed sign comparison
                left = mid + 1;
            else
                right = mid;
        }
        
        result.insert(result.begin() + left, unpaired);
    }
    
    // Copy result back to the container
    container = result;
}

void PmergeMe::sortAndMeasure(const std::vector<int>& input) {
    // Display elements before sorting
    std::cout << "Before: ";
    for (size_t i = 0; i < input.size(); i++) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
    
    std::vector<int> vec(input.begin(), input.end());
    std::deque<int> deq(input.begin(), input.end());

    // Use C++98 compatible timing mechanism
    clock_t start_vec = clock();
    mergeInsertSort(vec);
    clock_t end_vec = clock();
    
    clock_t start_deq = clock();
    mergeInsertSort(deq);
    clock_t end_deq = clock();
    
    // Display elements after sorting
    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    
    // Calculate time in microseconds
    double time_vec = (end_vec - start_vec) * 1000000.0 / CLOCKS_PER_SEC;
    double time_deq = (end_deq - start_deq) * 1000000.0 / CLOCKS_PER_SEC;
    
    std::cout << "Time to process a range of " << input.size() << " elements with std::vector : " 
              << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << input.size() << " elements with std::deque : " 
              << time_deq << " us" << std::endl;
}
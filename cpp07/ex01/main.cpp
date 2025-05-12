
#include "iter.hpp"
#include <iostream>

void printInt(int& x) {
    std::cout << x << " ";
}

void increment(int& x) {
    ++x;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    iter(arr, length, printInt);
    std::cout << std::endl;

    iter(arr, length, increment);

    std::cout << "Incremented array: ";
    iter(arr, length, printInt);
    std::cout << std::endl;

    return 0;
}
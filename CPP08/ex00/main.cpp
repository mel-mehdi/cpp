
#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(i);

    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
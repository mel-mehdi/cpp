#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <sequence of positive integers>" << std::endl;
        return 1;
    }

    std::vector<int> input;
    for (int i = 1; i < argc; ++i) {
        try {
            int num = std::stoi(argv[i]);
            if (num < 0) throw std::invalid_argument("Negative number");
            input.push_back(num);
        } catch (...) {
            std::cerr << "Error: invalid input." << std::endl;
            return 1;
        }
    }

    PmergeMe sorter;
    sorter.sortAndMeasure(input);

    return 0;
}
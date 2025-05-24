
#include "Span.hpp"

Span::Span(unsigned int maxSize) : _maxSize(maxSize) {}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw std::overflow_error("Span is full");
    _numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_numbers.size() + std::distance(begin, end) > _maxSize)
        throw std::overflow_error("Adding range exceeds Span capacity");
    _numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i)
        minSpan = std::min(minSpan, sorted[i + 1] - sorted[i]);
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");
    return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}
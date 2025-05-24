
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int maxSize);
    ~Span();

    void addNumber(int number);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan() const;
    int longestSpan() const;
};

#endif
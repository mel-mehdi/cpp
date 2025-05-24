#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class RPN {
public:
    RPN();
    ~RPN();

    int evaluate(const std::string& expression);

private:
    bool isOperator(char c) const;
    int applyOperation(int a, int b, char op) const;
};

#endif
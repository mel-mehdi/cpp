#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOperation(int a, int b, char op) const {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw std::runtime_error("Error");
            return a / b;
        default: throw std::runtime_error("Error");
    }
}

int RPN::evaluate(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.size() == 1 && isOperator(token[0])) {
            if (stack.size() < 2) throw std::runtime_error("Error");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(applyOperation(a, b, token[0]));
        } else {
            for (size_t i = 0; i < token.size(); ++i) {
                if (i == 0 && token[i] == '-') continue;
                if (!isdigit(token[i])) throw std::runtime_error("Error");
            }
            stack.push(std::atoi(token.c_str()));
        }
    }
    if (stack.size() != 1) throw std::runtime_error("Error");
    return stack.top();
}
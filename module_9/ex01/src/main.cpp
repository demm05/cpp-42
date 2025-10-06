#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <sys/types.h>

template <typename T> std::string toString(T const &v) {
    std::ostringstream ss;
    ss << v;
    return ss.str();
}

template <typename T> T fromString(std::string const &str) {
    std::istringstream ss(str);
    T ret;
    ss >> ret;
    if (ss.fail() || !ss.eof())
        throw std::runtime_error("Invalid number format: '" + str + "'");
    return ret;
}

bool isAllDigit(std::string const &s) {
    if (s.empty())
        return false;
    std::string::const_iterator it = s.begin();
    if (*it == '-' || *it == '+')
        ++it;
    for (; it != s.end(); ++it) {
        if (!::isdigit(*it))
            return false;
    }
    return true;
}

bool isValidOperand(char op) {
    return op == '-' || op == '+' || op == '*' || op == '/';
}

template <typename T> bool performOperation(std::stack<T> &stack, char op) {
    if (!isValidOperand(op) || stack.size() < 2)
        return false;
    T y = stack.top();
    stack.pop();
    T x = stack.top();
    stack.pop();
    T res;
    if (op == '+')
        res = x + y;
    else if (op == '-')
        res = x - y;
    else if (op == '*')
        res = x * y;
    else if (op == '/') {
        if (y == 0)
            throw std::runtime_error("Division by zero");
        res = x / y;
    } else
        throw std::runtime_error("Internal Error: unimplemented operand");
    stack.push(res);
    return true;
}

template <typename T> T doRPN(std::string const &input) {
    std::istringstream ss(input);
    std::stack<T> stack;
    std::string token;
    if (input.empty())
        return 0;
    while (ss >> token) {
        if (token.size() == 1 && isValidOperand(token[0])) {
            if (performOperation(stack, token[0]))
                continue;
        }
        if (isAllDigit(token)) {
            stack.push(fromString<T>(token));
        } else {
            throw std::runtime_error(
                "Unexpected token: '" + token +
                "'; stack size: " + toString(stack.size()));
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Not enough operators");
    return stack.top();
}

int main(int argc, char **argv) {
    if (argc < 2)
        std::cerr << "At lest one RPN is required" << std::endl;
    for (int i = 1; i < argc; i++) {
        try {
            std::cout << "[" << i - 1 << "] " << doRPN<int>(argv[i])
                      << std::endl;
        } catch (std::exception const &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

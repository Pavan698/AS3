#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include <string> // Include the necessary header for working with strings.
#include <stack> // Include the necessary header for using the stack data structure.

class ExpressionManager {
public:
    // Member function to check if an expression with braces, parentheses, and brackets is balanced.
    bool isBalanced(const std::string& expression);

    // Member function to convert an infix expression to postfix notation.
    std::string infixToPostfix(const std::string& infix);
};

#endif // EXPRESSION_MANAGER_H


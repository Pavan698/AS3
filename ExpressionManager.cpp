#include "ExpressionManager.h"

// Function to check if an expression with braces, parentheses, and brackets is balanced.
bool ExpressionManager::isBalanced(const std::string& expression) {
    std::stack<char> stack; // Create a stack to store opening symbols.

    // Loop through each character in the input expression.
    for (char ch : expression) {
        if (ch == '{' || ch == '(' || ch == '[') {
            // If an opening symbol is encountered, push it onto the stack.
            stack.push(ch);
        } else if (ch == '}' || ch == ')' || ch == ']') {
            // If a closing symbol is encountered, check if the stack is empty.
            if (stack.empty()) {
                return false; // Unmatched closing symbol, so the expression is not balanced.
            }
            char top = stack.top(); // Get the top symbol from the stack.
            stack.pop(); // Pop the top symbol from the stack.

            // Check if the closing symbol matches the last opening symbol on the stack.
            if ((ch == '}' && top != '{') ||
                (ch == ')' && top != '(') ||
                (ch == ']' && top != '[')) {
                return false; // Mismatched symbols, so the expression is not balanced.
            }
        }
    }

    // After processing all characters, if the stack is empty, the expression is balanced.
    return stack.empty();
}

// Function to determine the precedence of an operator.
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1; // Addition and subtraction have lower precedence.
    } else if (op == '*' || op == '/' || op == '%') {
        return 2; // Multiplication, division, and modulo have higher precedence.
    }
    return 0; // Default precedence for non-operators.
}

// Function to convert an infix expression to postfix notation.
std::string ExpressionManager::infixToPostfix(const std::string& infix) {
    std::string postfix; // Initialize an empty string to store the postfix expression.
    std::stack<char> operators; // Create a stack to store operators.

    // Loop through each character in the input infix expression.
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch; // If the character is an operand, add it to the postfix expression.
        } else if (ch == '(') {
            operators.push(ch); // Push an opening parenthesis onto the stack.
        } else if (ch == ')') {
            // When a closing parenthesis is encountered, pop operators from the stack and add them to the postfix expression
            // until the corresponding opening parenthesis is found and removed from the stack.
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove the '(' from the stack.
        } else {
            // For operators, pop operators with higher or equal precedence from the stack and add them to the postfix expression.
            while (!operators.empty() && precedence(ch) <= precedence(operators.top())) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch); // Push the current operator onto the stack.
        }
    }

    // After processing all characters, pop any remaining operators from the stack and add them to the postfix expression.
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix; // Return the final postfix expression.
}

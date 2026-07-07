// Mateo Sanchez Sinche, CS 110C
// A Postfix calculator that only use digits

#include "ArrayStack.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Function prototypes
int precedence(char op);
string infixToPostfix(string infix);
char applyOp(char a, char b, char op);
int evaluatePostfix(string postfix);
bool isOperator(char c);

// Test the program
int main() {
    string infix;

    while (true) {
        cout << "\nEnter infix expression (or q to quit): ";
        getline(cin, infix);

        if (infix == "q")
            break;

        string postfix = infixToPostfix(infix);

        cout << "Postfix: " << postfix << endl;

        int result = evaluatePostfix(postfix);

        cout << "Result: " << result << endl;
    }

    return 0;
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    ArrayStack stack;
    string postfix = "";
	int parenCount = 0; // To keep track of the number of parentheses

	// Traverse the infix expression
    for (char c : infix) {

        // Ignore whitespaces in the string
        // (Extra Credit Part)
        if (c == ' ')
            continue;

		// If the character is an operand (number), add it to the postfix expression
        if (c >= '0' && c <= '9') {
            postfix += c;
        }

		// If the character is '(', push it to the stack
        else if (c == '(') {
            stack.push(c);
            parenCount++;
        }

		// If the character is ')', pop from the stack to the postfix expression until '(' is encountered
		// When '(' is encountered, pop it from the stack but do not add it to the postfix expression
        else if (c == ')') {

            // If there is no corresponding '(' for each ')', then parenthesis are unbalanced
            // (Extra Credit Part)
            if (parenCount == 0) {
                cout << "Error: Unmatched closing parenthesis ')'\n";
                exit(1);
            }

            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.peek();
                stack.pop();
            }
            stack.pop();
            parenCount--;
        }

		// If the character is an operator, pop from the stack to the postfix expression until an operator with less precedence is encountered or the stack is empty
        else if (isOperator(c)) {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(c)) {
                postfix += stack.peek();
                stack.pop();
            }

            stack.push(c);
        }

		// If the character is not a digit, operator, or parenthesis, the expression is invalid
        // (Extra Credit Part)
        else {
            cout << "Error: Invalid expression" << endl;
            exit(1);
        }
    }

    // If there is no corresponding ')' for each '(', then parenthesis are unbalanced
    // (Extra Credit Part)
    if (parenCount != 0) {
        cout << "Error: Invalid expression. Unmatched opening parenthesis '('" << endl;
        exit(1);
    }

	// Pop all the remaining operators from the stack to the postfix expression
    while (!stack.isEmpty()) {
        postfix += stack.peek();
        stack.pop();
    }

    return postfix;
}

// Function to calculate the integer value of the character
char applyOp(char a, char b, char op) {
	// Convert char digits to integers
    int x = a - '0';
    int y = b - '0';
    int result;

	// Perform the operation based on the operator
    if (op == '+') result = x + y;
    else if (op == '-') result = x - y;
    else if (op == '*') result = x * y;
    else result = x / y;

    return result + '0';
}

// Function to evaluate Postfix expressions only using digits
int evaluatePostfix(string postfix) {
    ArrayStack stack;

	// Traverse the postfix expression
    for (char c : postfix) {
        // If the character is an operand (number), push it to the stack
        if (c >= '0' && c <= '9') {
            stack.push(c);
        }

        // If the character is an operator, pop the top two elements from the stack, apply the operator, and push the result back to the stack
        else if (isOperator(c)) {

            // If there are less than two operands in the stack, the expression is invalid
            // (Extra Credit Part)
            if (stack.isEmpty()) {
                cout << "Error: Invalid expression. Not enough operands for operator" << endl;
                exit(1);
            }

            char operand2 = stack.peek(); stack.pop();

            // If there are less than two operands in the stack, the expression is invalid
            // (Extra Credit Part)
            if (stack.isEmpty()) {
                cout << "Error: Invalid expression. Not enough operands for operator" << endl;
                exit(1);
            }

            char operand1 = stack.peek(); stack.pop();

			// If the operator is division and the second operand is zero, the expression is invalid
            // (Extra Credit Part)
            if (c == '/' && operand2 == '0') {
                cout << "Error: Invalid expression. Division by zero" << endl;
                exit(1);
            }

			// Apply the operator to the operands and push the result back to the stack
            char result = applyOp(operand1, operand2, c);
            stack.push(result);
        }

        else {
            // Invalid postfix
            // (Extra Credit Part)
            cout << "Error: Invalid character in postfix expression\n";
            exit(1);
        }
    }

    // If the stack is empty, then the expression could not be evaluated
    // (Extra Credit Part)
    if (stack.isEmpty()) {
        cout << "Error: Expression could not be evaluated\n";
        exit(1);
    }

	// The final result should be the only element left in the stack
    char finalChar = stack.peek(); stack.pop();

    // If the stack is not empty after the final result, then there is at least one operand left in the stack
    // (Extra Credit Part)
    if (!stack.isEmpty()) {
        cout << "Error: Too many operands left in stack\n";
        exit(1);
    }

    return finalChar - '0';
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

/* SAMPLE OUTPUT:
Enter infix expression (or q to quit): (1+2)*3
Postfix: 12+3*
Result: 9

Enter infix expression (or q to quit): 8/(4-2)
Postfix: 842-/
Result: 4

Enter infix expression (or q to quit): q
*/

/* SAMPLE OUTPUT (invalid strings):
(Extra Credit Part)

Enter infix expression(or q to quit) : 1+2)
Error: Invalid expression.Unmatched closing parenthesis ')'

Enter infix expression (or q to quit): (1+2
Error: Invalid expression. Unmatched opening parenthesis '('

Enter infix expression (or q to quit): 1+a
Error: Invalid expression

Enter infix expression (or q to quit): 3+
Postfix: 3+
Error: Invalid expression. Not enough operands for operator

Enter infix expression (or q to quit): 4/0
Postfix: 40/
Error: Invalid expression. Division by zero

Enter infix expression (or q to quit):
Postfix:
Error: Expression could not be evaluated

Enter infix expression (or q to quit): 12+3
Postfix: 123+
Error: Too many operands left in stack

Enter infix expression (or q to quit): ()
Postfix:
Error: Expression could not be evaluated
*/
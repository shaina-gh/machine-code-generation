#include <iostream>
#include <stack>
#include <vector>
#include <cctype>
#include <tuple>
using namespace std;

// Function to get precedence of operators
int getPrecedence(char operation) {
    if (operation == '+' || operation == '-') return 1;
    if (operation == '*' || operation == '/') return 2;
    if (operation == '^') return 3;
    return 0;
}

// Convert infix to postfix expression
string convertToPostfix(string input) {
    stack<char> opStack;
    string postfixResult;

    for (char character : input) {
        if (isalnum(character)) {
            postfixResult += character;
        } else if (character == '(') {
            opStack.push(character);
        } else if (character == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfixResult += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // Remove '('
        } else {
            while (!opStack.empty() && getPrecedence(opStack.top()) >= getPrecedence(character)) {
                postfixResult += opStack.top();
                opStack.pop();
            }
            opStack.push(character);
        }
    }

    while (!opStack.empty()) {
        postfixResult += opStack.top();
        opStack.pop();
    }
    return postfixResult;
}

// Generate Quadruples
void createQuadruple(string postfix) {
    stack<string> valueStack;
    vector<tuple<string, string, string, string>> quadList;
    int tempCounter = 1;

    for (char character : postfix) {
        if (isalnum(character)) {
            valueStack.push(string(1, character));
        } else {
            string secondArg = valueStack.top(); valueStack.pop();
            string firstArg = valueStack.top(); valueStack.pop();
            string resultVar = "t" + to_string(tempCounter++);
            quadList.push_back(make_tuple(string(1, character), firstArg, secondArg, resultVar));
            valueStack.push(resultVar);
        }
    }

    cout << "\nQuadruples:\n";
    for (const auto& quad : quadList) {
        cout << "(" << get<0>(quad) << ", " << get<1>(quad) << ", " << get<2>(quad) << ", " << get<3>(quad) << ")\n";
    }
}

// Generate Three Address Code or Machine Code
void createThreeAddressCode(string postfix) {
    stack<string> valueStack;
    int tempCounter = 1;

    cout << "\nThree-Address Code/Machine Code:\n";
    for (char character : postfix) {
        if (isalnum(character)) {
            valueStack.push(string(1, character));
        } else {
            string secondArg = valueStack.top(); valueStack.pop();
            string firstArg = valueStack.top(); valueStack.pop();
            string resultVar = "t" + to_string(tempCounter++);

            cout << "MOV " << firstArg << ", R0\n";
            if (character == '+') {
                cout << "ADD " << secondArg << ", R0\n";
            } else if (character == '*') {
                cout << "MUL " << secondArg << ", R0\n";
            } else if (character == '-') {
                cout << "SUB " << secondArg << ", R0\n";
            } else if (character == '/') {
                cout << "DIV " << secondArg << ", R0\n";
            } else if (character == '^') {
                cout << "POW " << secondArg << ", R0\n";
            }

            cout << "MOV R0, " << resultVar << "\n";
            valueStack.push(resultVar);
        }
    }

    cout << "MOV " << valueStack.top() << ", a\n";
}

int main() {
    string expr;
    cout << "Input an expression: ";
    cin >> expr;

    string postfixExpr = convertToPostfix(expr);
    cout << "Postfix Expression: " << postfixExpr << endl;

    createQuadruple(postfixExpr);
    createThreeAddressCode(postfixExpr);

    return 0;
}

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define MAX 100

class Stack {
private:
    double arr[MAX];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    bool empty() {
        return (topIndex == -1);
    }

    bool full() {
        return (topIndex == MAX - 1);
    }

    void push(double value) {
        if (full()) {
            cout << "\nStack overflow. Cannot push more elements.\n";
            return;
        }
        arr[++topIndex] = value;
    }

    double pop() {
        if (empty()) {
            cout << "\nStack underflow. Invalid expression.\n";
            return 0;
        }
        return arr[topIndex--];
    }

    double top() {
        if (empty()) {
            cout << "\nStack is empty.\n";
            return 0;
        }
        return arr[topIndex];
    }
};

class PostfixEvaluator {
private:
    Stack stack;

    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
    }

public:
    double evaluate(string exp) {
        for (int i = 0; i < exp.length(); i++) {
            char ch = exp[i];

            if (ch == ' ')
                continue;

            if (isdigit(ch)) {
                stack.push(ch - '0');
            }
            else if (isOperator(ch)) {
                double val2 = stack.pop();
                double val1 = stack.pop();
                double result = 0;

                switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': result = pow(val1, val2); break;
                }

                stack.push(result);
            }
            else {
                cout << "\nInvalid character encountered: " << ch << endl;
                return 0;
            }
        }

        return stack.pop();
    }
};

int main() {
    PostfixEvaluator evaluator;
    string expression;

    cout << "Enter a postfix expression: ";
    cin >> expression;

    double result = evaluator.evaluate(expression);
    cout << "Result: " << result << endl;

    return 0;
}

#include <iostream>
#include <cmath>
#include <string>
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
            cout << "Stack overflow\n";
            return;
        }
        arr[++topIndex] = value;
    }

    double pop() {
        if (empty()) {
            cout << "Stack underflow\n";
            return 0;
        }
        return arr[topIndex--];
    }

    double top() {
        if (empty()) {
            cout << "Stack is empty\n";
            return 0;
        }
        return arr[topIndex];
    }
};

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

double evaluatePrefix(string exp) {
    Stack s;
    for (int i = exp.length() - 1; i >= 0; i--) {
        char ch = exp[i];

        if (ch == ' ') continue;

        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else if (isOperator(ch)) {
            double op1 = s.pop();
            double op2 = s.pop();
            double result = 0;

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
            }

            s.push(result);
        }
    }
    return s.pop();
}

int main() {
    string expression;
    cout << "Enter a prefix expression: ";
    cin >> expression;

    double result = evaluatePrefix(expression);
    cout << "Result: " << result << endl;

    return 0;
}

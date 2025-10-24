#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
private:
    char arr[MAX];
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

    void push(char value) {
        if (full()) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++topIndex] = value;
    }

    char pop() {
        if (empty()) {
            cout << "Stack underflow\n";
            return '\0';
        }
        return arr[topIndex--];
    }

    char top() {
        if (empty()) return '\0';
        return arr[topIndex];
    }
};

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.pop();
            }
            if (!s.empty()) s.pop();
        }
        else if (isOperator(ch)) {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                if (ch == '^' && s.top() == '^') break;
                postfix += s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infixToPostfix(infix);

    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}

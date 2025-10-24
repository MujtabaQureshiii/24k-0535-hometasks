#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
private:
    string arr[MAX];
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

    void push(string url) {
        if (full()) {
            cout << "Stack overflow. Cannot add more pages.\n";
            return;
        }
        arr[++topIndex] = url;
    }

    string pop() {
        if (empty()) {
            cout << "Stack underflow. No pages to go back to.\n";
            return "";
        }
        return arr[topIndex--];
    }

    string top() {
        if (empty()) return "";
        return arr[topIndex];
    }

    void display() {
        if (empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (most recent first):\n";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

class Node {
public:
    string url;
    Node* next;

    Node(string u) {
        url = u;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void addFront(string url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
    }

    void removeFront() {
        if (head == nullptr) {
            cout << "History is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        if (head == nullptr) {
            cout << "History is empty.\n";
            return;
        }
        cout << "Browsing History (Most recent first):\n";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->url << endl;
            temp = temp->next;
        }
    }

    string getCurrentPage() {
        if (head == nullptr) return "None";
        return head->url;
    }
};

int main() {
    Stack historyStack;
    LinkedList browsingList;

    string websites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};

    for (int i = 0; i < 5; i++) {
        string site = websites[i];
        browsingList.addFront(site);
        historyStack.push(site);
    }

    cout << "Initial Browsing History:\n";
    browsingList.display();

    cout << "\nUser presses BACK twice...\n";
    historyStack.pop();
    browsingList.removeFront();
    historyStack.pop();
    browsingList.removeFront();

    cout << "\nAfter going back twice:\n";
    browsingList.display();

    cout << "\nCurrent Page: " << browsingList.getCurrentPage() << endl;

    return 0;
}

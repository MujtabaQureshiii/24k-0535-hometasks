#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Call {
private:
    string name;
    string number;
    int duration;

public:
    Call() {
        name = "";
        number = "";
        duration = 0;
    }

    Call(string n, string num, int d) {
        name = n;
        number = num;
        duration = d;
    }

    void setCall(string n, string num, int d) {
        name = n;
        number = num;
        duration = d;
    }

    void displayCall() const {
        cout << name << " | " << number << " | " << duration << " min";
    }

    string getName() const { return name; }
    string getNumber() const { return number; }
    int getDuration() const { return duration; }
};

class CallHistory {
private:
    Call stack[MAX];
    int topIndex;

public:
    CallHistory() {
        topIndex = -1;
    }

    bool empty() {
        return (topIndex == -1);
    }

    bool full() {
        return (topIndex == MAX - 1);
    }

    void push(const Call& c) {
        if (full()) {
            cout << "\nCall history is full! Cannot add more calls.\n";
            return;
        }
        stack[++topIndex] = c;
        cout << "\nNew call added successfully.\n";
        display();
    }

    void pop() {
        if (empty()) {
            cout << "\nNo calls to delete. History is empty.\n";
            return;
        }
        cout << "\nDeleting most recent call: " << stack[topIndex].getName() << endl;
        topIndex--;
        display();
    }

    void top() {
        if (empty()) {
            cout << "\nNo recent call to show. History is empty.\n";
            return;
        }
        cout << "\nMost Recent Call:\n";
        stack[topIndex].displayCall();
        cout << endl;
    }

    void display() {
        if (empty()) {
            cout << "\nCall history is empty.\n";
            return;
        }
        cout << "\nCurrent Call History (Most recent first):\n";
        for (int i = topIndex; i >= 0; i--) {
            cout << i + 1 << ". ";
            stack[i].displayCall();
            cout << endl;
        }
    }
};

int main() {
    CallHistory history;
    int choice;
    string name, number;
    int duration;

    do {
        cout << "\n===== MOBILE CALL HISTORY SYSTEM =====\n";
        cout << "1. Add New Call (Push)\n";
        cout << "2. Delete Recent Call (Pop)\n";
        cout << "3. Show Most Recent Call (Top)\n";
        cout << "4. Check if History is Empty\n";
        cout << "5. Display All Calls\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter caller name: ";
            getline(cin, name);
            cout << "Enter caller number: ";
            getline(cin, number);
            cout << "Enter call duration (in minutes): ";
            cin >> duration;
            {
                Call c(name, number, duration);
                history.push(c);
            }
            break;

        case 2:
            history.pop();
            break;

        case 3:
            history.top();
            break;

        case 4:
            if (history.empty())
                cout << "\nCall history is empty.\n";
            else
                cout << "\nCall history is not empty.\n";
            break;

        case 5:
            history.display();
            break;

        case 0:
            cout << "\nExiting program...\n";
            break;

        default:
            cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

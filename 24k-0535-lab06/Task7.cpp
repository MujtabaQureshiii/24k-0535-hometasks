#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Patron {
private:
    string name;
    int books;

public:
    Patron() {
        name = "";
        books = 0;
    }

    Patron(string n, int b) {
        name = n;
        books = b;
    }

    void setPatron(string n, int b) {
        name = n;
        books = b;
    }

    string getName() const { return name; }
    int getBooks() const { return books; }

    void displayPatron() const {
        cout << name << " | Books: " << books;
    }
};

class LibraryQueue {
private:
    Patron queue[MAX];
    int front, rear;

public:
    LibraryQueue() {
        front = -1;
        rear = -1;
    }

    bool empty() {
        return (front == -1 || front > rear);
    }

    bool full() {
        return (rear == MAX - 1);
    }

    void enqueue(const Patron& p) {
        if (full()) {
            cout << "Queue is full. Cannot add more patrons.\n";
            return;
        }
        if (front == -1) front = 0;
        queue[++rear] = p;
        cout << "Patron added to queue successfully.\n";
    }

    void dequeue() {
        if (empty()) {
            cout << "No patrons to remove. Queue is empty.\n";
            return;
        }
        cout << "Servicing and removing patron: " << queue[front].getName() << endl;
        front++;
    }

    void display() {
        if (empty()) {
            cout << "No patrons are currently waiting.\n";
            return;
        }
        cout << "Current Patrons in Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". ";
            queue[i].displayPatron();
            cout << endl;
        }
    }
};

int main() {
    LibraryQueue library;
    int choice;
    string name;
    int books;

    do {
        cout << "\n===== LIBRARY QUEUE SYSTEM =====\n";
        cout << "1. Add Patron to Queue\n";
        cout << "2. Remove Patron (Transaction Completed)\n";
        cout << "3. Display Current Queue\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter patron name: ";
            getline(cin, name);
            cout << "Enter number of books: ";
            cin >> books;
            {
                Patron p(name, books);
                library.enqueue(p);
            }
            break;

        case 2:
            library.dequeue();
            break;

        case 3:
            library.display();
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

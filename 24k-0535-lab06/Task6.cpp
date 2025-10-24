#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Order {
private:
    string item;
    int quantity;

public:
    Order() {
        item = "";
        quantity = 0;
    }

    Order(string i, int q) {
        item = i;
        quantity = q;
    }

    void setOrder(string i, int q) {
        item = i;
        quantity = q;
    }

    void display() const {
        cout << item << " | Quantity: " << quantity << endl;
    }
};

class OrderQueue {
private:
    Order queue[MAX];
    int front, rear;

public:
    OrderQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(const Order& o) {
        if (isFull()) {
            cout << "Cannot add new order. Queue is full.\n";
            return;
        }
        if (front == -1)
            front = 0;
        queue[++rear] = o;
        cout << "Order added successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No orders to process. Queue is empty.\n";
            return;
        }
        cout << "Processing order: ";
        queue[front].display();
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }
        cout << "Current Orders in Queue:\n";
        for (int i = front; i <= rear; i++) {
            queue[i].display();
        }
    }
};

int main() {
    OrderQueue restaurant;
    int choice;
    string item;
    int quantity;

    do {
        cout << "\n===== RESTAURANT ORDER SYSTEM =====\n";
        cout << "1. Add New Order\n";
        cout << "2. Process Next Order\n";
        cout << "3. Display All Orders\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            getline(cin, item);
            cout << "Enter quantity: ";
            cin >> quantity;
            restaurant.enqueue(Order(item, quantity));
            break;

        case 2:
            restaurant.dequeue();
            break;

        case 3:
            restaurant.display();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

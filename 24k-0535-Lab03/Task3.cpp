#include <iostream>
using namespace std;

struct Node {
    int compartmentNumber;
    Node* prev;
    Node* next;
    Node(int num) : compartmentNumber(num), prev(nullptr), next(nullptr) {}
};

class Train {
    Node* head;
    Node* tail;

public:
    Train() : head(nullptr), tail(nullptr) {}

    void addEnd(int compartmentNum) {
        Node* newNode = new Node(compartmentNum);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Added compartment: " << compartmentNum << endl;  // ✅ added message
    }

    void removeFirst() {
        if (!head) {
            cout << "Train has no compartments.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;

        cout << "Removed compartment number: " << temp->compartmentNumber << endl;
        delete temp;
    }

    void search(int compartmentNum) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->compartmentNumber == compartmentNum) {
                cout << "Compartment " << compartmentNum << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Compartment " << compartmentNum << " not found.\n";
    }

    void display() {
        if (!head) {
            cout << "Train has no compartments.\n";
            return;
        }
        cout << "Train compartments from front to end:\n";
        Node* temp = head;
        int pos = 1;
        while (temp) {
            cout << pos << ". " << temp->compartmentNumber << endl;  
            temp = temp->next;
            pos++;
        }
    }

    ~Train() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Train train;

    train.addEnd(20);
    train.addEnd(21);
    train.addEnd(22);
    train.addEnd(23);
    train.addEnd(24);

    train.display();

    train.removeFirst();

    train.search(22);
    train.search(26);

    train.display();

    return 0;
}

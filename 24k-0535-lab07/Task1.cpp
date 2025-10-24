#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
};

void insert(Node*& head, string name, int score) {
    Node* newNode = new Node{name, score, nullptr};
    if (!head)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int getMax(Node* head) {
    int max = head->score;
    Node* temp = head->next;
    while (temp) {
        if (temp->score > max)
            max = temp->score;
        temp = temp->next;
    }
    return max;
}

int getDigit(int number, int exp) {
    return (number / exp) % 10;
}

Node* countSort(Node* head, int exp) {
    Node* buckets[10] = {nullptr};
    Node* tails[10] = {nullptr};

    for (Node* curr = head; curr; curr = curr->next) {
        int digit = getDigit(curr->score, exp);
        Node* newNode = new Node{curr->name, curr->score, nullptr};

        if (!buckets[digit])
            buckets[digit] = tails[digit] = newNode;
        else {
            tails[digit]->next = newNode;
            tails[digit] = newNode;
        }
    }

    Node* newHead = nullptr;
    Node* newTail = nullptr;
    for (int i = 0; i < 10; i++) {
        if (buckets[i]) {
            if (!newHead) {
                newHead = buckets[i];
                newTail = tails[i];
            } else {
                newTail->next = buckets[i];
                newTail = tails[i];
            }
        }
    }
    return newHead;
}

Node* radixSort(Node* head) {
    int maxScore = getMax(head);
    for (int exp = 1; maxScore / exp > 0; exp *= 10)
        head = countSort(head, exp);
    return head;
}

void display(Node* head) {
    cout << "\nSorted Student Records:\n";
    cout << "------------------------------\n";
    cout << "Name\tScore\n";
    cout << "------------------------------\n";
    Node* temp = head;
    while (temp) {
        cout << temp->name << "\t" << temp->score << endl;
        temp = temp->next;
    }
    cout << "------------------------------\n";
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter score (0-100): ";
        cin >> score;
        insert(head, name, score);
    }

    cout << "\nSorting student scores using Radix Sort...\n";
    head = radixSort(head);
    display(head);

    return 0;
}

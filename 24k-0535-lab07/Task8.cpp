#include <iostream>
#include <string>
using namespace std;

struct Order {
    int orderID;
    string customerName;
    double totalPrice;
};

class OrderList {
private:
    Order orders[50];
    int n;

    void swap(Order &a, Order &b) {
        Order temp = a;
        a = b;
        b = temp;
    }

    int partition(int low, int high) {
        double pivot = orders[high].totalPrice;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (orders[j].totalPrice < pivot) {
                i++;
                swap(orders[i], orders[j]);
            }
        }
        swap(orders[i + 1], orders[high]);
        return i + 1;
    }

    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

public:
    void input() {
        cout << "Enter number of orders: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Enter details for Order " << i + 1 << ":\n";
            cout << "Order ID: ";
            cin >> orders[i].orderID;
            cout << "Customer Name: ";
            cin >> orders[i].customerName;
            cout << "Total Price: ";
            cin >> orders[i].totalPrice;
        }
    }

    void sortOrders() {
        quickSort(0, n - 1);
    }

    void display() {
        cout << "Sorted Orders by Total Price (Ascending):\n";
        cout << "Order ID\nCustomer Name\nTotal Price\n";
        for (int i = 0; i < n; i++) {
            cout << orders[i].orderID << "\n"
                 << orders[i].customerName << "\n"
                 << orders[i].totalPrice << "\n";
        }
    }
};

int main() {
    OrderList list;
    list.input();
    list.sortOrders();
    list.display();
    return 0;
}

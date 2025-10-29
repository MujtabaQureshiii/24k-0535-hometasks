#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[20];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
        cout << "\nAfter sorting by digit place " << exp << ":\n";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

int main() {
    int productIDs[20] = {
        45231, 12054, 98543, 67321, 33411, 78900, 54322, 87654, 23456, 67890,
        11223, 99123, 55555, 33333, 77777, 44444, 22222, 88888, 99999, 66666
    };

    int n = 20;

    cout << "Product IDs Before Sorting:\n";
    for (int i = 0; i < n; i++)
        cout << productIDs[i] << " ";
    cout << endl;

    radixSort(productIDs, n);

    cout << "\nProduct IDs After Complete Sorting (Ascending):\n";
    for (int i = 0; i < n; i++)
        cout << productIDs[i] << " ";
    cout << endl;

    return 0;
}

// Shell Sort is preferred over Bubble Sort because it reduces the number of swaps and comparisons 
// by initially comparing and moving elements far apart, allowing faster convergence toward sorted order. 
// Bubble Sort repeatedly compares adjacent elements, making it inefficient (O(n²)). 
// Shell Sort can achieve much better performance (O(n log² n) in practice). 
// If the luggage weights are nearly sorted, Shell Sort performs even faster — close to O(n) — since fewer swaps are needed.

#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
        cout << "After gap " << gap << ": ";
        printArray(arr, n);
    }
}

int main() {
    int weights[] = {32, 25, 40, 12, 18, 50, 28};
    int n = 7;
    cout << "Original weights: ";
    printArray(weights, n);
    shellSort(weights, n);
    cout << "Sorted weights: ";
    printArray(weights, n);
    return 0;
}

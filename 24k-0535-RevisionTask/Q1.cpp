// Shell Sort is more efficient than Insertion Sort because it reduces the total number of comparisons and shifts 
// by first comparing elements that are far apart. This allows elements to move closer to their correct position 
// faster, minimizing the amount of work needed in later passes when the gap becomes smaller. 
// In contrast, Insertion Sort only compares adjacent elements, which makes it slower for larger or unsorted lists.

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
    int arr[] = {205, 102, 310, 450, 120, 90};
    int n = 6;
    cout << "Original array: ";
    printArray(arr, n);
    shellSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}

#include <iostream>
using namespace std;

int comparisons = 0;

void swapValues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partitionFunc(int arr[], int left, int right, int pivot) {
    int leftPtr = left;
    int rightPtr = right - 1;
    while (true) {
        while (arr[++leftPtr] < pivot) {
            comparisons++;
            if (leftPtr >= rightPtr) break;
        }
        while (rightPtr > 0 && arr[--rightPtr] > pivot) {
            comparisons++;
        }
        if (leftPtr >= rightPtr)
            break;
        else
            swapValues(arr[leftPtr], arr[rightPtr]);
    }
    swapValues(arr[leftPtr], arr[right]);
    return leftPtr;
}

int getMedianIndex(int arr[], int low, int high) {
    int mid = (low + high) / 2;
    int a = arr[low], b = arr[mid], c = arr[high];
    if ((a > b) != (a > c))
        return low;
    else if ((b > a) != (b > c))
        return mid;
    else
        return high;
}

int choosePivotIndex(int low, int high, int type, int arr[]) {
    if (type == 1)
        return low;
    else if (type == 2)
        return (low + high) % (high - low + 1) + low;
    else if (type == 3)
        return (low + high) / 2;
    else
        return getMedianIndex(arr, low, high);
}

void quickSort(int arr[], int left, int right, int type) {
    if (left >= right)
        return;
    int pivotIndex = choosePivotIndex(left, right, type, arr);
    swapValues(arr[pivotIndex], arr[right]);
    int pivot = arr[right];
    int partitionPoint = partitionFunc(arr, left - 1, right, pivot);
    quickSort(arr, left, partitionPoint - 1, type);
    quickSort(arr, partitionPoint + 1, right, type);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {55, 23, 88, 12, 67, 43, 90, 34, 10, 76};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array:\n";
    printArray(arr, n);
    string names[] = {"First Element", "Pattern-based (Random)", "Middle Element", "Median of Three"};
    for (int type = 1; type <= 4; type++) {
        int temp[10];
        for (int i = 0; i < n; i++) temp[i] = arr[i];
        comparisons = 0;
        quickSort(temp, 0, n - 1, type);
        cout << "\nPivot Selection: " << names[type - 1] << endl;
        cout << "Sorted Array: ";
        printArray(temp, n);
        cout << "Comparisons: " << comparisons << endl;
    }
    return 0;
}

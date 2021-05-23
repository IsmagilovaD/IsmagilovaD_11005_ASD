#include <iostream>

using namespace std;

void selectionSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int help = arr[i];
                arr[i] = arr[j];
                arr[j] = help;
            }
        }
    }
}

void merge(int *arr, int *result, int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) {
            result[k] = arr[i];
            i++;
            k++;
        } else {
            result[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= m) {
        result[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        result[k] = arr[j];
        j++;
        k++;
    }
    for (i = l; i <= r; i++) {
        arr[i] = result[i];
    }
}

void mSort(int *arr, int *result, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mSort(arr, result, l, m);
    mSort(arr, result, m + 1, r);
    merge(arr, result, l, m, r);
}

void mergeSort(int *arr, int size) {
    int *result = new int[size];
    mSort(arr, result, 0, size - 1);
}

void printArray(int *a, int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int *arr = new int[10]{1, 5, 4, 3, 6, 8, 7, 9, 0, 2};
    int *arr1 = new int[13]{1, 5, 4, 3, 6, 8, 7, 9, 0, 2};
    selectionSort(arr, 10);
    mergeSort(arr1, 10);

    printArray(arr, 10);
    cout << endl;
    printArray(arr1, 10);
    return 0;
}

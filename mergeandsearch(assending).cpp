#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key > arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int binarySearch(int arr[], int key, int l, int r) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n1, n2;

    cout << "size of the first array: ";
    cin >> n1;
    int array1[n1];
    for (int i = 0; i < n1; ++i) {
        cin >> array1[i];
    }

    cout << "size of the second array: ";
    cin >> n2;
    int array2[n2];
    for (int i = 0; i < n2; ++i) {
        cin >> array2[i];
    }

    int mersize = n1 + n2;
    int merarr[mersize];

    for (int i = 0; i < n1; ++i) {
        merarr[i] = array1[i];
    }
    for (int i = 0; i < n2; ++i) {
        merarr[i + n1] = array2[i];
    }

    insertionSort(merarr, mersize);

    cout << "Merged and Sorted Array : ";
    for (int i = 0; i < mersize; ++i) {
        cout << merarr[i] << " ";
    }
    cout << endl;

    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    int index = binarySearch(merarr, key, 0, mersize - 1);

    if (index != -1) {
        int count = 0;
        for (int i = 0; i < mersize; ++i) {
            if (merarr[i] == key) {
                count++;
            }
        }
        cout << "Element found at index " << index << ". cout: " << count << endl;
    } else {
        cout << "not found." << endl;
    }

    return 0;
}

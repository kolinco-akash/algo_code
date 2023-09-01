#include <iostream>
#include <algorithm>

// Function to perform insertion sort on an array of strings
void insertionSort(std::string arr[], int n) {
    for (int i = 1; i < n; i++) {
        std::string key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Function to remove duplicates from a sorted array of strings
int removeDuplicates(std::string arr[], int n) {
    if (n <= 1) {
        return n; // No duplicates to remove
    }

    int newSize = 1; // New size of the array

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }

    return newSize;
}

int main() {
    int n;
    std::cout << "Enter the number of names: ";
    std::cin >> n;

    std::string names[n];

    std::cout << "Enter the names:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> names[i];
    }

    // Sort the names in alphabetical order using Insertion Sort
    insertionSort(names, n);

    // Remove duplicates and get the new size of the array
    int newSize = removeDuplicates(names, n);

    std::cout << "Sorted and de-duplicated names:" << std::endl;
    for (int i = 0; i < newSize; i++) {
        std::cout << names[i] << std::endl;
    }

    return 0;
}

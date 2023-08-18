#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int l, int h) {
    int pivot = arr[h];
    int i = l - 1;

    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

void quicksort(int arr[], int l, int h) {
    if (l < h) {
        int pi = partition(arr, l, h);
        quicksort(arr, l, pi - 1);
        quicksort(arr, pi + 1, h);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    double median;
    if (n % 2 == 1) {
        median = arr[n / 2];
    } else {
        median = (arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
    }

    cout << "Median value: " << median << endl;

    return 0;
}

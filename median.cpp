#include <iostream>

double calculateMedian(int arr[], int n) {
    if (n % 2 != 0) {
        // If the array has an odd number of elements, the median is the middle element.
        return static_cast<double>(arr[n / 2]);
    } else {
        // If the array has an even number of elements, the median is the average of the two middle elements.
        double middle1 = static_cast<double>(arr[(n - 1) / 2]);
        double middle2 = static_cast<double>(arr[n / 2]);
        return (middle1 + middle2) / 2.0;
    }
}

int main() {
    int sortedArray[] = {1, 3, 5, 7}; // Example sorted array
    int n = sizeof(sortedArray) / sizeof(sortedArray[0]);
    double median = calculateMedian(sortedArray, n);
    std::cout << "Median: " << median << std::endl;
    return 0;
}

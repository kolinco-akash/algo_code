#include <iostream>
#include <algorithm>
using namespace std;

int full_bin(int* items, int n, int binCapacity) {
    int numBins = 0;
    int currentBinLoad = 0;

    for (int i = 0; i < n; i++) {
        if (currentBinLoad + items[i] > binCapacity) {
            numBins++;
            currentBinLoad = 0;
        }

        currentBinLoad += items[i];
    }

    if (currentBinLoad > 0) {
        numBins++;
    }

    return numBins;
}

int main() {
    int binCapacity;
    int itemCount;

    cout << "Enter the bin capacity: ";
    cin >> binCapacity;

    cout << "Enter the number of items: ";
    cin >> itemCount;

    int items[itemCount];

    cout << "Enter the sizes of the items:" << endl;
    for (int i = 0; i < itemCount; i++) {
        cin >> items[i];
    }

    int numBins = full_bin(items, itemCount, binCapacity);

    cout << "The number of bins used is: " << numBins << endl;

    return 0;
}

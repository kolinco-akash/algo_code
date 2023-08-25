#include <iostream>
#include <algorithm> // For sorting
using namespace std;

int first_fit_decreasing(int* items, int n, int binCapacity) {
  sort(items, items + n, greater<int>()); // Sort items in decreasing order
  int numBins = 0;
  int bins[n] = {0}; // Using an array for bins

  for (int i = 0; i < n; i++) {
    bool placed = false;

    for (int j = 0; j < numBins; j++) {
      if (items[i] <= bins[j]) {
        bins[j] -= items[i];
        placed = true;
        break;
      }
    }

    if (!placed) {
      bins[numBins] = binCapacity - items[i];
      numBins++;
    }
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

  int numBins = first_fit_decreasing(items, itemCount, binCapacity);

  cout << "The number of bins used is: " << numBins << endl;

  return 0;
}

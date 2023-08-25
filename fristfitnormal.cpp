#include <iostream>

using namespace std;

int first_fit(int* items, int n, int binCapacity) {
  int numBins = 0;
  int* bins = new int[n];

  for (int i = 0; i < n; i++) {
    int j = 0;
    while (j < numBins && items[i] > bins[j]) {
      j++;
    }

    if (j == numBins) {
      numBins++;
      bins[numBins - 1] = 0;
    }

    bins[j] += items[i];
  }

  delete[] bins;

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

  int numBins = first_fit(items, itemCount, binCapacity);

  cout << "The number of bins used is: " << numBins << endl;

  return 0;
}

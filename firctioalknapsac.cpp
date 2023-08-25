#include <iostream>
#include <algorithm>

using namespace std;

void fractional_knapsack(int* profits, int* weights, int n, int capacity) {
  // Sort the items in decreasing order of profit/weight ratio.
  int items[n];
  for (int i = 0; i < n; i++) {
    items[i] = i;
  }
  sort(items, items + n, [&profits, &weights](int i, int j) {
    return static_cast<double>(profits[i]) / weights[i] > static_cast<double>(profits[j]) / weights[j];
  });

  // Initialize the current profit.
  double currentProfit = 0;

  // Iterate over the items.
  for (int i = 0; i < n; i++) {
    // Get the current item.
    int item = items[i];

    // Check if the item fits in the knapsack.
    if (weights[item] <= capacity) {
      // If it does, add it to the knapsack and update the current profit.
      currentProfit += profits[item];
      capacity -= weights[item];
    } else {
      // Otherwise, add a fraction of the item to the knapsack.
      double fraction = static_cast<double>(capacity) / weights[item];
      currentProfit += profits[item] * fraction;
      capacity = 0;
    }

    if (capacity == 0) {
      break; // Knapsack is full
    }
  }

  // Print the current profit.
  cout << "The maximum profit is: " << currentProfit << endl;
}

int main() {
  int itemCount;

  cout << "Enter the number of items: ";
  cin >> itemCount;

  int profits[itemCount];
  int weights[itemCount];

  cout << "Enter the profits and weights of items:" << endl;
  for (int i = 0; i < itemCount; i++) {
    cin >> profits[i] >> weights[i];
  }

  int capacity;

  cout << "Enter the capacity of the knapsack: ";
  cin >> capacity;

  // Solve the fractional knapsack problem.
  fractional_knapsack(profits, weights, itemCount, capacity);

  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0-1 Knapsack using Dynamic Programming
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    // Create a 2D DP array with (n+1) rows and (W+1) columns initialized to 0
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {              // Iterate over items
        for (int w = 1; w <= W; w++) {          // Iterate over possible weights
            if (weights[i - 1] <= w) {          // If item i can fit in the knapsack
                dp[i][w] = max(dp[i - 1][w],    // Don't take item i
                               values[i - 1] + dp[i - 1][w - weights[i - 1]]); // Take item i
            } else {
                dp[i][w] = dp[i - 1][w];        // Can't take item i, so carry forward the previous value
            }
        }
    }

    // The maximum value that can be obtained is in dp[n][W]
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter maximum weight of knapsack: ";
    cin >> W;

    vector<int> weights(n), values(n);
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> weights[i];
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> values[i];

    int max_value = knapsack(W, weights, values, n);
    cout << "Maximum value in Knapsack: " << max_value << endl;

    return 0;
}

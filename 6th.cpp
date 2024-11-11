#include <iostream>
using namespace std;
// Function to determine if a subset with sum equals to target_sum exists
bool isSubsetSum(int arr[], int n, int target_sum) {
// Create a DP table with dimensions (n+1) x (target_sum+1)
bool dp[n+1][target_sum+1];
// Initialize DP table
for (int i = 0; i <= n; i++)
dp[i][0] = true; // A sum of 0 is always possible
for (int j = 1; j <= target_sum; j++)
dp[0][j] = false; // With 0 elements, no positive sum is possible
// Fill the DP table
for (int i = 1; i <= n; i++) {
for (int j = 1; j <= target_sum; j++) {
if (arr[i-1] > j) {
dp[i][j] = dp[i-1][j]; // Exclude current element
} else {
dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]]; // Include or exclude current element
}
}
}
// Return whether it's possible to form target_sum
return dp[n][target_sum];
}
int main() {
int arr[] = {3, 34, 4, 12, 5, 2};
int target_sum = 9;
int n = sizeof(arr) / sizeof(arr[0]);
if (isSubsetSum(arr, n, target_sum))
cout << "Subset with the given sum exists" << endl;
else
cout << "Subset with the given sum does not exist" << endl;
return 0;
}

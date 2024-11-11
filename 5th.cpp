#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time measurement
#include <chrono> // For precise time calculation
using namespace std;
using namespace std::chrono;
// Function to swap two elements
void swap(int& a, int& b) {
int temp = a;
a = b;
b = temp;
}
// Partition function used by Quick Sort
int partition(vector<int>& arr, int low, int high) {
int pivot = arr[high]; // Choose the last element as pivot
int i = low - 1; // Index of the smaller element
for (int j = low; j < high; j++) {
// If current element is smaller than or equal to pivot
if (arr[j] <= pivot) {
i++; // Increment index of smaller element
swap(arr[i], arr[j]);
}
}
// Swap pivot with the element at i+1
swap(arr[i + 1], arr[high]);
return (i + 1);
}
// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
if (low < high) {
// Partition the array and get the pivot index
int pi = partition(arr, low, high);
// Recursively sort elements before and after partition
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}



}
// Function to generate random numbers and fill the array
vector<int> generateRandomArray(int n) {
vector<int> arr(n);
for (int i = 0; i < n; i++) {
arr[i] = rand() % 10000; // Generate random numbers between 0 and 9999
}
return arr;
}
int main() {
srand(time(0)); // Seed for random number generation
vector<int> arr;
int n;
// Input the number of elements
cout << "Enter the number of elements: ";
cin >> n;
// Generate a random array of size n
arr = generateRandomArray(n);
// Measure the time taken by Quick Sort
auto start = high_resolution_clock::now();
quickSort(arr, 0, n - 1);
auto stop = high_resolution_clock::now();
// Calculate the duration
auto duration = duration_cast<microseconds>(stop - start);
// Output the sorted array (can be commented if array is large)
cout << "Sorted array: ";
for (int i = 0; i < n; i++) {
cout << arr[i] << " ";
}
cout << endl;
// Output the time taken
cout << "Time taken to sort " << n << " elements: " << duration.count() << "
microseconds" << endl;
return 0;
}

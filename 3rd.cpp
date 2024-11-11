#include <iostream>
#include <unordered_map>
#include <vector>
void findFrequencies(const std::vector<int>& arr) {
// Initialize an unordered map to store frequencies
std::unordered_map<int, int> frequency;
// Iterate through the array
for (int element : arr) {
// Increment the count for the element in the unordered map
frequency[element]++;
}
// Output the frequencies
for (const auto& pair : frequency) {
std::cout << "Element: " << pair.first << " - Frequency: " << pair.second << std::endl;
}
}
int main() {
// Example usage
std::vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 5, 5};
findFrequencies(arr);
return 0;
}

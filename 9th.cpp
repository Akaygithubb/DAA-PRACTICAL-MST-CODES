#include <iostream>
#include <vector>
using namespace std;
vector<int> naivePatternSearch(const string &S, const string &P) {
int n = S.length(); // Length of the text string
int m = P.length(); // Length of the pattern string



vector<int> occurrences;
// Slide the pattern over text one by one
for (int i = 0; i <= n - m; i++) {
// Check if the pattern matches the current substring of the text
int j;
for (j = 0; j < m; j++) {
if (S[i + j] != P[j])
break;
}
// If the pattern matches, store the index
if (j == m) {
occurrences.push_back(i);
}
}
return occurrences;
}
int main() {
string S = "abracadabra";
string P = "abra";
// Call the pattern search function
vector<int> result = naivePatternSearch(S, P);
// Output the result
if (!result.empty()) {
cout << "Pattern found at indices: ";
for (int index : result) {
cout << index << " ";
}
cout << endl;
} else {
cout << "Pattern not found in the text." << endl;
}
return 0;
}

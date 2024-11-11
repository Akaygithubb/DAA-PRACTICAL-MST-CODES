#include <iostream>
using namespace std;

// Function to calculate x raised to the power n in O(log n) time
double power(double x, int n) {
    // Base case: any number raised to the power 0 is 1
    if (n == 0) 
        return 1;

    // Calculate half power recursively
    double halfPower = power(x, n / 2);

    // If n is even, return halfPower * halfPower
    if (n % 2 == 0) 
        return halfPower * halfPower;
    else {
        // If n is odd, return x * halfPower * halfPower
        // If n is negative, we take 1/x
        if (n > 0)
            return x * halfPower * halfPower;
        else
            return (1 / x) * halfPower * halfPower;
    }
}

int main() {
    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    cout << x << "^" << n << " = " << power(x, n) << endl;

    return 0;
}

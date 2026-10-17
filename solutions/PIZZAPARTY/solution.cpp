#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Chef is a boy, so total boys = A + 1.
 * - Total girls = B.
 * - Each boy eats 4 slices, each girl eats 3 slices.
 * - Total slices needed = (A + 1) * 4 + B * 3.
 * - Each pizza has 8 slices.
 * - Number of pizzas needed = ceil(total_slices / 8.0).
 * - Using integer arithmetic, ceil(x / y) is (x + y - 1) / y.
 * 
 * Constraints:
 * - 0 <= A, B <= 100.
 * - Max slices = (101 * 4) + (100 * 3) = 404 + 300 = 704.
 * - 704 fits easily into a standard integer.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // The problem description implies multiple test cases based on the 
    // "For each test case" instruction, though the input format says 
    // "The first and only line of input contains 2 integers".
    // We will handle the input as specified by the constraints/format.
    
    int A, B;
    if (cin >> A >> B) {
        long long total_boys = (long long)A + 1;
        long long total_girls = (long long)B;
        
        long long total_slices = (total_boys * 4) + (total_girls * 3);
        
        // Calculate ceiling division: (total_slices + 8 - 1) / 8
        long long pizzas_needed = (total_slices + 7) / 8;
        
        cout << pizzas_needed << "\n";
    }

    return 0;
}
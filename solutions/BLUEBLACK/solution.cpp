#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs either:
 * 1. 3 blue pens: Cost = 3 * A
 * 2. 1 blue pen and 1 black pen: Cost = A + B
 * 
 * We need to find the minimum of these two values.
 * Constraints: 10 <= A, B <= 50.
 * Since the values are small, standard integer types are sufficient, 
 * but long long is used for safety as per instructions.
 */

void solve() {
    long long A, B;
    if (!(cin >> A >> B)) return;

    long long option1 = 3 * A;
    long long option2 = A + B;

    cout << min(option1, option2) << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the format,
    // but standard competitive programming practice often involves handling 
    // multiple test cases if specified. Given the prompt "Handle multiple test cases",
    // we check if there's a test case count or just process the input.
    // Based on the provided format: "The first and only line contains 2 integers".
    // We will process the single line provided.
    
    solve();

    return 0;
}
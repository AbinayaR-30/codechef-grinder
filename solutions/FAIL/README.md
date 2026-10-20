# [Failing Grades (FAIL)](https://www.codechef.com/problems/FAIL)

- **Difficulty Rating**: 697
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef takes $N$ tests. To pass, his average marks after **every** test (from the 1st test up to the $N$-th test) must be at least 40. Given the marks for each test, determine if Chef maintains an average of at least 40 throughout the entire duration.

## Intuition & Mathematical Observation
The condition states that for every test $k$ (where $1 \le k \le N$), the average must be $\ge 40$. 
Let $S_k$ be the sum of marks after $k$ tests. The condition is:
$$\frac{S_k}{k} \ge 40$$

To avoid floating-point precision issues, we can multiply both sides by $k$:
$$S_k \ge 40 \times k$$

We iterate through the input marks, maintaining a running sum. After adding each mark, we check if the current running sum satisfies the inequality. If at any point the condition fails, we flag the result as "No". If we complete all $N$ tests without the condition failing, the result is "Yes".

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the $N$ marks exactly once.
- **Space Complexity**: $O(1)$, as we only store the running sum and the current mark, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs his average to be >= 40 after EACH test.
 * Let S_k be the sum of marks after k tests.
 * The condition is: (S_k / k) >= 40 for all 1 <= k <= N.
 * This is equivalent to: S_k >= 40 * k.
 * 
 * Constraints:
 * N <= 100, A_i <= 100.
 * The maximum sum S_k is 100 * 100 = 10,000.
 * This fits comfortably within a standard integer, but we use long long 
 * as per the instructions for safety.
 */

void solve() {
    int N;
    cin >> N;
    
    long long current_sum = 0;
    bool possible = true;
    
    for (int i = 1; i <= N; ++i) {
        long long marks;
        cin >> marks;
        current_sum += marks;
        
        // Check if average >= 40 after the i-th test
        // Average = current_sum / i
        // Condition: current_sum / i >= 40  =>  current_sum >= 40 * i
        if (current_sum < 40LL * i) {
            possible = false;
        }
    }
    
    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
```
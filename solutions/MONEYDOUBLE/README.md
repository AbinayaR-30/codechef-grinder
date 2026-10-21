# [Money Double (MONEYDOUBLE)](https://www.codechef.com/problems/MONEYDOUBLE)

- **Difficulty Rating**: 784
- **Solved in**: 3 attempt(s)

## Problem Summary
You start with an initial amount $X$. Over the course of $Y$ years, in each year, you can perform one of two operations:
1. Add 1000 to your current amount ($X = X + 1000$).
2. Double your current amount ($X = X \times 2$).

The goal is to maximize the final amount after exactly $Y$ years.

## Intuition & Mathematical Observation
While the problem can be solved using recursion (exploring all $2^Y$ paths), a greedy observation simplifies the logic significantly. 

Since we want to maximize the final result, we should consider the order of operations. Doubling a larger number yields a greater increase than doubling a smaller number. Therefore, it is always optimal to **add 1000 first** and **double later**. 

However, because $Y$ is very small ($Y \le 10$), the recursive approach provided in the solution is perfectly efficient. It explores every possible combination of operations to ensure the absolute maximum is found. The base case occurs when $Y=0$, at which point we return the accumulated amount.

## Complexity Analysis
- **Time Complexity**: $O(2^Y)$ per test case. Given $Y \le 10$, $2^{10} = 1024$, which is well within the time limits for the given constraints.
- **Space Complexity**: $O(Y)$ due to the recursion stack depth.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * At each year, we have two choices: add 1000 or double.
 * Since Y is small (up to 10), we can explore all 2^Y possible sequences 
 * of operations to find the maximum amount.
 */

long long findMax(long long x, int y) {
    // Base case: no more years left
    if (y == 0) {
        return x;
    }
    
    // Option 1: Add 1000
    long long option1 = findMax(x + 1000, y - 1);
    
    // Option 2: Double the amount
    long long option2 = findMax(x * 2, y - 1);
    
    // Return the maximum of the two paths
    return max(option1, option2);
}

void solve() {
    long long x;
    int y;
    cin >> x >> y;
    
    cout << findMax(x, y) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
```
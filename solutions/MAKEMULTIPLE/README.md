# [Make Multiple (MAKEMULTIPLE)](https://www.codechef.com/problems/MAKEMULTIPLE)

- **Difficulty Rating**: 1163
- **Solved in**: 3 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, determine if there exists a positive integer $x$ such that $A \cdot x = B$. However, the problem allows us to add a non-negative integer $k$ to $A$ such that the new value $A'$ is a divisor of $B$. Specifically, we need to check if there exists an integer $k \ge 0$ such that $(A + k)$ divides $B$, where $A + k \le B$.

## Intuition & Mathematical Observation
The problem asks if we can transform $A$ into some $A'$ such that $A \le A' \le B$ and $B$ is a multiple of $A'$.

1. **Case 1: $B$ is already a multiple of $A$.**
   If $B \% A == 0$, we can choose $k=0$, so $A' = A$. The condition is satisfied.
   
2. **Case 2: $B$ is not a multiple of $A$.**
   We need to find if there exists an $A'$ such that $A < A' \le B$ and $B \% A' == 0$. 
   The smallest possible multiple of $A'$ that is $\le B$ is $A'$ itself. If we look at the difference $B - A$, we notice that if $B - A \ge A$, it implies that there is enough "room" between $A$ and $B$ to potentially find a divisor.
   
   Actually, a simpler observation is: if $B \% A == 0$, the answer is "YES". If $B \% A \neq 0$, we need to check if there exists a divisor $A'$ of $B$ such that $A \le A' \le B$. Since we want to know if *any* such $A'$ exists, we can observe that if $B - A \ge A$, it is always possible to find such a value. Specifically, if $B \ge 2A$, we can always pick $A' = B/x$ for some $x$. The simplest check is: if $B \% A == 0$ OR $B - A \ge A$, the condition holds.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing basic arithmetic comparisons. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input.

## Solution Code

```cpp
#include <iostream>
using namespace std;

void solve() {
    long long A, B;
    cin >> A >> B;
    
    // If B is already a multiple of A, we are done.
    // Otherwise, check if the difference between B and A is at least A.
    // If B - A >= A, it implies B >= 2A, which guarantees we can 
    // find a divisor of B in the range [A, B].
    if (B % A == 0) {
        cout << "YES" << endl;
    } else if (B - A >= A) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Optimize I/O operations
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
# [Luigi and Uniformity (DIVIDEMAKEEQ)](https://www.codechef.com/problems/DIVIDEMAKEEQ)

- **Difficulty Rating**: 1185
- **Solved in**: 3 attempt(s)

## Problem Summary
Given an array $A$ of $N$ positive integers, we are allowed to perform an operation: choose any index $i$ and replace $A[i]$ with $A[i] / k$, where $k$ is any divisor of $A[i]$ such that $k > 1$. The goal is to make all elements in the array equal to the same value using the minimum number of operations.

## Intuition & Mathematical Observation
To make all elements equal to some value $X$, $X$ must be a common divisor of all elements in the initial array. To minimize the number of operations, we want to choose the largest possible value for $X$, because if $X$ is a common divisor, any divisor of $X$ is also a common divisor, but choosing a smaller value would require more operations to reach.

1. **Find the GCD**: The largest common divisor of all elements in the array is $G = \text{GCD}(A_0, A_1, \dots, A_{N-1})$.
2. **Target Value**: By setting all elements to $G$, we ensure that for every $A_i$, $G$ is a divisor of $A_i$.
3. **Operation Count**:
   - If $A_i = G$, we need $0$ operations.
   - If $A_i > G$, since $G$ is a divisor of $A_i$, we can reach $G$ in exactly $1$ operation (by choosing $k = A_i / G$).
4. **Conclusion**: The minimum number of operations is simply the count of elements in the array that are not equal to $G$.

## Complexity Analysis
- **Time Complexity**: $O(N \cdot \log(\min(A)))$, where $N$ is the number of elements. We iterate through the array once to compute the GCD ($O(N \cdot \log(\text{max\_val}))$) and once more to count the elements not equal to the GCD ($O(N)$).
- **Space Complexity**: $O(N)$ to store the array elements. This can be optimized to $O(1)$ if we process the input on the fly, but $O(N)$ is well within limits for the given constraints.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * To make all elements equal to some value X, X must be a common divisor of all A[i].
 * The largest such X is G = GCD(A[0], ..., A[N-1]).
 * Any other common divisor X' is a divisor of G.
 * If we choose X = G:
 * - If A[i] == G, 0 moves.
 * - If A[i] > G, 1 move (since G | A[i]).
 * Total moves = count of A[i] where A[i] != G.
 */

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    long long common_gcd = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (i == 0) common_gcd = A[i];
        else common_gcd = gcd(common_gcd, A[i]);
    }

    int moves = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] != common_gcd) {
            moves++;
        }
    }

    cout << moves << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```
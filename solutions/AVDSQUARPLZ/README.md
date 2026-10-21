# [Avoid Squares Please (AVDSQUARPLZ)](https://www.codechef.com/problems/AVDSQUARPLZ)

- **Difficulty Rating**: 960
- **Solved in**: 3 attempt(s)

## Problem Summary
Given an integer $N$, we need to arrange the numbers from $1$ to $N$ in a sequence such that for any two adjacent elements $a$ and $b$, their product $a \times b$ is **not** a perfect square.

## Intuition & Mathematical Observation
A product of two numbers $a \times b$ is a perfect square if and only if $a$ and $b$ share the same "square-free part." For example, $2 \times 8 = 16$ (a square) because both $2$ and $8$ have a square-free part of $2$ ($2 = 2 \times 1^2$, $8 = 2 \times 2^2$).

To solve this, we can use a **greedy approach**:
1. Start with any number (e.g., $N$).
2. For the current number, iterate through the remaining unused numbers from $1$ to $N$.
3. Pick the first number that, when multiplied by the current number, does not result in a perfect square.
4. Since $N$ is small ($N \le 500$), this $O(N^2)$ approach is well within the time limits. The greedy choice is highly likely to succeed because there are many numbers available that do not form a perfect square with the current number.

## Complexity Analysis
- **Time Complexity**: $O(T \times N^2)$, where $T$ is the number of test cases and $N$ is the input integer. For each of the $N$ positions, we scan up to $N$ numbers.
- **Space Complexity**: $O(N)$ to store the sequence and the boolean array tracking used numbers.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Two numbers a and b have a product that is a perfect square if and only if 
 * they have the same square-free part.
 * 
 * Strategy:
 * We use a greedy approach. For each position, we pick the first unused number 
 * that does not form a perfect square with the previous number.
 */

bool is_perfect_square(int n) {
    int root = round(sqrt(n));
    return root * root == n;
}

void solve() {
    int N;
    cin >> N;
    vector<int> p;
    vector<bool> used(N + 1, false);
    
    // Start with N to begin the sequence
    p.push_back(N);
    used[N] = true;
    
    for (int i = 1; i < N; ++i) {
        int last = p.back();
        // Try to find a number that doesn't form a square with the last element
        for (int next = 1; next <= N; ++next) {
            if (!used[next] && !is_perfect_square(last * next)) {
                p.push_back(next);
                used[next] = true;
                break;
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << p[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
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
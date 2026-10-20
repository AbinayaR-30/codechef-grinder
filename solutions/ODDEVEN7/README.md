# [Odd Even (ODDEVEN7)](https://www.codechef.com/problems/ODDEVEN7)

- **Difficulty Rating**: 877
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array of $N$ integers, we need to find the length of the longest subsequence such that the parity (odd/even) of the elements alternates. In other words, we want to pick the maximum number of elements such that no two adjacent elements in the subsequence have the same parity.

## Intuition & Mathematical Observation
To maximize the length of an alternating sequence, we should pair every odd number with an even number. 

1. Let $O$ be the count of odd numbers and $E$ be the count of even numbers.
2. If $O = E$, we can use all numbers to form an alternating sequence (e.g., $O, E, O, E, \dots$ or $E, O, E, O, \dots$), resulting in a length of $O + E$.
3. If $O \neq E$, we are limited by the smaller count. We can pair every element of the minority group with one from the majority group. This gives us $2 \times \min(O, E)$ elements. Since we have extra elements from the majority group, we can add exactly one more element to the end (or beginning) of the sequence to maintain the alternating property. Thus, the length becomes $2 \times \min(O, E) + 1$.

This logic can be simplified: if $O = E$, the answer is $2 \times O$. Otherwise, it is $2 \times \min(O, E) + 1$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array, as we iterate through the input exactly once.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store the counts of odd and even numbers regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: ODDEVEN7
 * Approach:
 * Count the number of odd and even integers in the array.
 * Let O be the count of odd numbers and E be the count of even numbers.
 * We can form an alternating sequence by taking pairs of (odd, even).
 * The maximum length is 2 * min(O, E) + (1 if O != E else 0).
 * 
 * Time Complexity: O(N) per test case
 * Space Complexity: O(1) auxiliary space
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    int odd_count = 0;
    int even_count = 0;
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }
    
    int result;
    if (odd_count == even_count) {
        result = odd_count + even_count;
    } else {
        result = 2 * min(odd_count, even_count) + 1;
    }
    
    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```
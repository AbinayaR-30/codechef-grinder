# [Double Strings (DOUBLE)](https://www.codechef.com/problems/DOUBLE)

- **Difficulty Rating**: 1134
- **Solved in**: 3 attempt(s)

## Problem Summary
The problem asks us to determine the length of the longest "double string" that can be formed given a length $N$. A double string is defined as a string where every character appears an even number of times (specifically, it is formed by repeating a string twice). Essentially, we need to find the largest even integer less than or equal to $N$.

## Intuition & Mathematical Observation
A "double string" of length $2k$ requires $k$ pairs of characters. 
- If the given length $N$ is **even**, all characters can be paired up perfectly. Thus, the longest double string has length $N$.
- If the given length $N$ is **odd**, one character will always be left over (the middle character in a palindrome or simply the remainder). Therefore, we must discard one character to make the count even, resulting in a length of $N-1$.

Both cases can be unified using integer division in C++:
$$\text{Result} = \left( \frac{N}{2} \right) \times 2$$

- If $N=4$: $(4/2) \times 2 = 4$
- If $N=3$: $(3/2) \times 2 = 1 \times 2 = 2$

This formula effectively rounds down to the nearest even number.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time arithmetic operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * A "double string" of length 2k requires k pairs of characters.
 * Given a palindrome of length N:
 * - If N is even, all characters can be paired up. We can form a double string of length N.
 * - If N is odd, there is one character left over (the middle one). We can form a double string of length N-1.
 * 
 * The formula (N / 2) * 2 correctly handles both cases:
 * - If N = 2, (2/2)*2 = 2
 * - If N = 3, (3/2)*2 = 2
 * - If N = 4, (4/2)*2 = 4
 */

int main() {
    // Optimize I/O operations for faster execution
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    if (!(std::cin >> T)) return 0;
    while (T--) {
        long long N;
        std::cin >> N;
        // The result is the largest even number less than or equal to N
        std::cout << (N / 2) * 2 << "\n";
    }
    return 0;
}
```
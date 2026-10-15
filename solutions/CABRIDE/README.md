# [Cab Rides (CABRIDE)](https://www.codechef.com/problems/CABRIDE)

- **Difficulty Rating**: 945
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to calculate the minimum cost to transport $N$ people using cabs. Each cab can hold a maximum of 4 people. The cost of a cab is determined by the number of people ($X$) inside it:
- If $X \le 4$, the cost is $\max(200, 100 \times X)$.
- This implies:
    - 1 person: 200
    - 2 people: 200
    - 3 people: 300
    - 4 people: 400

We need to find the optimal way to group $N$ people to minimize the total cost.

## Intuition & Mathematical Observation
By analyzing the cost structure, we can observe the following:
- For $N=1$, the cost is 200.
- For $N=2$, the cost is 200.
- For $N=3$, the cost is 300.
- For $N=4$, the cost is 400.
- For $N=5$, we can split them into groups of 3 and 2, costing $300 + 200 = 500$.
- For $N=6$, we can split them into groups of 3 and 3, costing $300 + 300 = 600$.

**Pattern Recognition:**
- If $N=1$, the cost is 200.
- For all $N > 1$, the most efficient way to transport people is to fill cabs such that the cost per person is effectively 100. Since the base cost for a single cab is 200, we can always group people into sets of 2, 3, or 4 to maintain an average cost of 100 per person.
- Therefore, for any $N > 1$, the total cost is simply $100 \times N$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case is solved in $O(1)$ constant time.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Cost per cab = max(200, 100 * X) where X <= 4.
 * X=1: 200
 * X=2: 200
 * X=3: 300
 * X=4: 400
 * 
 * Pattern: For N > 1, the cost is 100 * N. For N = 1, the cost is 200.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 200 << "\n";
        } else {
            cout << 100 * n << "\n";
        }
    }
    return 0;
}
```
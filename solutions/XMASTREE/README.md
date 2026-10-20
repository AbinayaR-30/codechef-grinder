# [Christmas Trees (XMASTREE)](https://www.codechef.com/problems/XMASTREE)

- **Difficulty Rating**: 300
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to calculate the total profit made from a Christmas tree business. We are given:
*   $N$: The number of trees purchased.
*   $A$: The cost price per tree.
*   $M$: The number of trees sold.
*   $B$: The selling price per tree.

The goal is to find the net profit, which is defined as the total revenue minus the total cost.

## Intuition & Mathematical Observation
The profit calculation is straightforward based on the definitions provided:
1.  **Total Cost**: Since we buy $N$ trees at a cost of $A$ each, the total expenditure is $N \times A$.
2.  **Total Revenue**: Since we sell $M$ trees at a price of $B$ each, the total income is $M \times B$.
3.  **Net Profit**: The profit is simply `Total Revenue - Total Cost`.

**Mathematical Formula**:
$$\text{Profit} = (M \times B) - (N \times A)$$

**Note on Data Types**: While the constraints for a 300-rated problem are typically small, it is good practice to use `long long` in C++ to prevent potential integer overflow if the input values were to be large.

## Complexity Analysis
- **Time Complexity**: $O(1)$. The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$. We only use a few variables to store the input and the result, requiring constant extra space.

## Solution Code

```cpp
#include <iostream>

using namespace std;

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, A, M, B;
    
    // Read the input values: N (bought), A (cost), M (sold), B (price)
    if (!(cin >> N >> A >> M >> B)) return 0;

    // Calculate profit: (Revenue) - (Cost)
    // Using long long to ensure no overflow occurs during multiplication
    long long profit = (long long)M * B - (long long)N * A;

    // Output the final result
    cout << profit << endl;

    return 0;
}
```
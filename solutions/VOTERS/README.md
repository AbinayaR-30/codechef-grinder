# [Discrepancies in the Voters List (VOTERS)](https://www.codechef.com/problems/VOTERS)

- **Difficulty Rating**: 1114
- **Solved in**: 1 attempt(s)

## Problem Summary
We are provided with three separate lists of voter IDs, each already sorted in ascending order. Our task is to identify all voter IDs that appear in at least two of the three lists. The final output must list these IDs in ascending order, preceded by the total count of such IDs.

## Intuition & Mathematical Observation
Since the total number of IDs across all three lists is at most 150,000 ($50,000 \times 3$), we need an efficient way to track occurrences. 

1. **Frequency Counting**: We can use a `std::map<int, int>` to store the frequency of each ID. As we iterate through all input IDs, we increment their respective counts in the map.
2. **Ordering**: A `std::map` in C++ stores keys in sorted order by default. This is perfect for our requirement to output the IDs in ascending order.
3. **Filtering**: After populating the map, we iterate through it and collect all keys whose associated value (frequency) is $\ge 2$.
4. **Efficiency**: Given the constraints, $O(N \log N)$ (where $N$ is the total number of IDs) is well within the time limit for competitive programming environments.

## Complexity Analysis
- **Time Complexity**: $O(N \log K)$, where $N$ is the total number of IDs ($N_1 + N_2 + N_3$) and $K$ is the number of unique IDs. Each insertion into the map takes $O(\log K)$ time.
- **Space Complexity**: $O(K)$, where $K$ is the number of unique IDs stored in the map. In the worst case, this is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three sorted lists of voter IDs. We need to find IDs that appear
 * in at least two of the three lists.
 * 
 * Constraints:
 * N1, N2, N3 <= 50,000. Total IDs <= 150,000.
 * Since the IDs are positive integers, we can use a frequency map (std::map)
 * to count occurrences. std::map is efficient enough (O(N log N)) and 
 * keeps keys sorted automatically.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, n3;
    if (!(cin >> n1 >> n2 >> n3)) return 0;

    // Use a map to store the frequency of each ID.
    // Map automatically keeps keys in ascending order.
    map<int, int> counts;

    int total_elements = n1 + n2 + n3;
    for (int i = 0; i < total_elements; ++i) {
        int id;
        cin >> id;
        counts[id]++;
    }

    // Collect IDs that appear in at least 2 lists.
    vector<int> result;
    for (auto const& [id, count] : counts) {
        if (count >= 2) {
            result.push_back(id);
        }
    }

    // Output the count of such IDs
    cout << result.size() << "\n";
    
    // Output the IDs in ascending order
    for (int id : result) {
        cout << id << "\n";
    }

    return 0;
}
```
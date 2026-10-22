# [Mode of Frequencies (MODEFREQ)](https://www.codechef.com/problems/MODEFREQ)

- **Difficulty Rating**: 1234
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to determine the "mode" of the frequencies of the elements. Specifically:
1. Calculate the frequency of each distinct number in the array.
2. Count how many numbers share the same frequency.
3. Identify the frequency that appears most frequently among the numbers.
4. If there is a tie in the count of frequencies, choose the smallest frequency value.

## Intuition & Mathematical Observation
The problem requires a two-step frequency counting process:
1. **First Pass:** Use a frequency map (or array) to count how many times each number $A_i$ appears in the input. Let this be `val_counts`.
2. **Second Pass:** Iterate through `val_counts` to determine how many distinct numbers have a specific frequency. We store this in a second map, `freq_of_freq`, where the key is the frequency and the value is the number of elements that have that frequency.
3. **Selection:** Iterate through `freq_of_freq` to find the key (frequency) associated with the maximum value (occurrence). Since we need the smallest frequency in case of a tie, and `std::map` in C++ stores keys in ascending order, we can simply iterate through the map and update our result only when we find a strictly greater occurrence count.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ (or $O(N)$ if using `std::unordered_map`). Given the constraints and the use of `std::map`, each insertion and lookup takes logarithmic time relative to the number of distinct elements.
- **Space Complexity**: $O(N)$ to store the frequency counts of the elements and the counts of those frequencies.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * 1. Count occurrences of each number in A.
 * 2. Count how many numbers have a specific frequency.
 * 3. Find the frequency that appears most often.
 * 4. Tie-break by choosing the smallest frequency.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    // Map to store frequency of each number
    map<int, int> val_counts;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        val_counts[a]++;
    }
    
    // Count how many numbers have a specific frequency
    // freq_of_freq[f] = how many numbers appear exactly f times
    map<int, int> freq_of_freq;
    for (auto const& [val, count] : val_counts) {
        freq_of_freq[count]++;
    }
    
    int max_occurrence = -1;
    int best_freq = -1;
    
    // Find the frequency that occurs most often
    // Since std::map is sorted by key, we naturally encounter 
    // smaller frequencies first.
    for (auto const& [freq, occurrence] : freq_of_freq) {
        if (occurrence > max_occurrence) {
            max_occurrence = occurrence;
            best_freq = freq;
        }
        // No need for explicit tie-breaking logic for smallest frequency
        // because we iterate through the map in ascending order of keys.
    }
    
    cout << best_freq << endl;
}

int main() {
    // Optimize I/O operations
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
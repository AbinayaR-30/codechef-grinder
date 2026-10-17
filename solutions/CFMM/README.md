# [Making a Meal (CFMM)](https://www.codechef.com/problems/CFMM)

- **Difficulty Rating**: 1214
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ strings, we need to determine the maximum number of times the word "codechef" can be formed using the characters available across all provided strings. Each character from the input strings can be used only once.

## Intuition & Mathematical Observation
To form one instance of "codechef", we require the following character frequencies:
- **c**: 2
- **o**: 1
- **d**: 1
- **e**: 2
- **h**: 1
- **f**: 1

By aggregating the total count of every character present in all $N$ input strings, we can determine how many "codechef" strings we can construct. Since the characters 'c' and 'e' are required twice per meal, their total available count must be divided by 2. The other characters ('o', 'd', 'h', 'f') are required once.

The total number of meals we can form is constrained by the "bottleneck" character—the character that allows for the fewest number of complete "codechef" sets. Mathematically, this is expressed as:
$$\text{meals} = \min\left( \left\lfloor\frac{\text{count}(c)}{2}\right\rfloor, \text{count}(o), \text{count}(d), \left\lfloor\frac{\text{count}(e)}{2}\right\rfloor, \text{count}(h), \text{count}(f) \right)$$

## Complexity Analysis
- **Time Complexity**: $O(S)$, where $S$ is the total number of characters across all $N$ strings. We iterate through each character exactly once to populate the frequency map.
- **Space Complexity**: $O(1)$, as the map stores a constant number of characters (at most 26 lowercase English letters), regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form the string "codechef", we need the following counts of characters:
 * c: 2, o: 1, d: 1, e: 2, h: 1, f: 1
 * 
 * We count the total occurrences of each character across all input strings.
 * The maximum number of "codechef" strings is limited by the character
 * that runs out first, considering the required frequency per meal.
 */

void solve() {
    int n;
    cin >> n;
    map<char, int> counts;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            counts[c]++;
        }
    }

    // Calculate how many times each required character can satisfy the "codechef" requirement
    int c = counts['c'] / 2;
    int o = counts['o'];
    int d = counts['d'];
    int e = counts['e'] / 2;
    int h = counts['h'];
    int f = counts['f'];

    // The answer is the minimum of these values
    int ans = min({c, o, d, e, h, f});
    cout << ans << "\n";
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
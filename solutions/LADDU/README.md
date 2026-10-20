# [Laddu (LADDU)](https://www.codechef.com/problems/LADDU)

- **Difficulty Rating**: 1241
- **Solved in**: 3 attempt(s)

## Problem Summary
The goal is to calculate the total number of "Laddus" a user has earned based on a series of activities and then determine how many months of "redeemable" service they can afford. Each activity type has a specific point value:
- **CONTEST_WON**: 300 points + bonus (if rank < 20, bonus = 20 - rank).
- **TOP_CONTRIBUTOR**: 300 points.
- **BUG_FOUND**: Points equal to the severity of the bug.
- **CONTEST_HOSTED**: 50 points.

After calculating the total, we divide by a threshold (200 for `INDIAN` users, 400 for `NON_INDIAN` users) to find the maximum number of months the user can redeem.

## Intuition & Mathematical Observation
1. **Accumulation**: The problem is a straightforward simulation. We maintain a running total (`total_laddus`) and update it based on the activity type provided in the input.
2. **Conditional Logic**: 
   - For `CONTEST_WON`, we must handle the conditional bonus logic carefully: `300 + (rank < 20 ? 20 - rank : 0)`.
   - For `BUG_FOUND`, we must read the additional integer representing the severity.
3. **Redemption**: Since we need the *maximum* number of months, integer division (`total_laddus / threshold`) is the correct mathematical operation, as it effectively floors the result to the nearest whole month.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the total number of activities across all test cases. We iterate through each activity exactly once.
- **Space Complexity**: $O(1)$, as we only store a few variables (`total_laddus`, `threshold`, `rank`, etc.) regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <string>

using namespace std;

/**
 * Problem Analysis:
 * 1. CONTEST_WON: 300 + (20 - rank) if rank < 20, else 300.
 * 2. TOP_CONTRIBUTOR: 300.
 * 3. BUG_FOUND: severity.
 * 4. CONTEST_HOSTED: 50.
 * 5. Redemption threshold: 200 for INDIAN, 400 for NON_INDIAN.
 * 6. Max months = total_laddus / threshold.
 */

void solve() {
    int activities;
    string origin;
    if (!(cin >> activities >> origin)) return;

    long long total_laddus = 0;

    for (int i = 0; i < activities; ++i) {
        string type;
        cin >> type;
        if (type == "CONTEST_WON") {
            int rank;
            cin >> rank;
            total_laddus += 300;
            if (rank < 20) {
                total_laddus += (20 - rank);
            }
        } else if (type == "TOP_CONTRIBUTOR") {
            total_laddus += 300;
        } else if (type == "BUG_FOUND") {
            int severity;
            cin >> severity;
            total_laddus += severity;
        } else if (type == "CONTEST_HOSTED") {
            total_laddus += 50;
        }
    }

    int threshold = (origin == "INDIAN") ? 200 : 400;
    
    // The user can redeem as long as they have at least the threshold amount
    // per month. Integer division naturally handles the "maximum number of months".
    cout << (total_laddus / threshold) << "\n";
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
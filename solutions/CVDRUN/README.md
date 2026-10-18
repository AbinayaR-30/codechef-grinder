# [Covid Run (CVDRUN)](https://www.codechef.com/problems/CVDRUN)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
There are $N$ cities arranged in a circle, indexed from $0$ to $N-1$. A virus starts at city $X$ and jumps to city $(X + K) \pmod N$ every day. We need to determine if the virus will ever reach city $Y$ given the parameters $N, K, X,$ and $Y$.

## Intuition & Mathematical Observation
The movement of the virus follows a modular arithmetic sequence: $X, (X+K) \pmod N, (X+2K) \pmod N, \dots$. 

Since there are only $N$ cities, the sequence of visited cities must eventually repeat. Because $N$ is relatively small ($N \le 1000$), we can simulate the process by keeping track of the cities we have already visited using a boolean array. If we encounter a city that has already been marked as visited, we have completed a full cycle without reaching $Y$, meaning the virus will never reach it. If we land on $Y$ before hitting a previously visited city, the answer is "YES".

Alternatively, this can be solved using number theory: the virus reaches $Y$ if and only if there exists a non-negative integer $i$ such that $(X + i \cdot K) \equiv Y \pmod N$. This is equivalent to solving the linear congruence $i \cdot K \equiv (Y - X) \pmod N$, which has a solution if and only if $(Y - X)$ is divisible by $\gcd(K, N)$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. In the worst case, we visit every city exactly once before the cycle repeats.
- **Space Complexity**: $O(N)$ to maintain the `visited` array to track the cities the virus has already infected.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The virus starts at city X and jumps by K each day in a circular arrangement of N cities.
 * This is equivalent to visiting cities (X + i * K) % N for i = 0, 1, 2, ...
 * We need to determine if Y is in this sequence.
 * 
 * Since N is small (up to 1000), we can simulate the process.
 * The sequence will eventually repeat because there are only N possible cities.
 * If we visit a city that has already been visited, we stop.
 */

void solve() {
    int N, K, X, Y;
    if (!(cin >> N >> K >> X >> Y)) return;

    // visited array to keep track of infected cities
    vector<bool> visited(N, false);
    
    int current = X;
    bool reached = false;
    
    // Simulate the jumps
    while (!visited[current]) {
        visited[current] = true;
        
        if (current == Y) {
            reached = true;
            break;
        }
        
        // Next city calculation
        current = (current + K) % N;
    }
    
    if (reached) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
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
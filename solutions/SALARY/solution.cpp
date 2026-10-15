#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N workers with salaries W_i.
 * An operation consists of choosing one worker and increasing everyone else's salary by 1.
 * This is equivalent to saying: "Decrease the chosen worker's salary relative to the others."
 * 
 * Let the target salary for everyone be S. Since we can only increase salaries, 
 * the final salary S must be at least the maximum of the initial salaries.
 * However, notice that increasing everyone except one worker by 1 is equivalent to 
 * decreasing one worker's salary by 1 relative to the others.
 * 
 * If we want to equalize all salaries to the minimum value currently present in the array,
 * we would need to perform operations to bring everyone down to that minimum.
 * But we can only increase salaries.
 * 
 * Let the minimum salary be 'min_w'. To make everyone equal to some value S, 
 * each worker i needs (S - W_i) increments.
 * In one operation, we increase (N-1) workers by 1.
 * Total increments needed = sum(S - W_i) for all i.
 * Each operation contributes (N-1) to the total sum of increments.
 * 
 * Actually, there is a simpler observation:
 * Increasing everyone except worker i by 1 is equivalent to increasing everyone by 1 
 * and then decreasing worker i by 1.
 * If we perform this operation X times, the final salary of worker i will be:
 * W_i + (Total_Operations - Count_i), where Count_i is the number of times worker i was the "loser".
 * For all workers to be equal to some value S:
 * W_i + Total_Operations - Count_i = S
 * Count_i = W_i + Total_Operations - S
 * Since Count_i >= 0, the minimum number of operations is achieved when S = min(W_i).
 * Then Count_i = W_i - min(W_i).
 * The total number of operations is the sum of (W_i - min(W_i)) for all i.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> w(n);
    long long min_val = 20000; // Larger than max constraint 10000
    long long sum = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        if (w[i] < min_val) {
            min_val = w[i];
        }
        sum += w[i];
    }
    
    // The total number of operations is sum(W_i - min_val)
    // which is sum(W_i) - n * min_val
    long long result = sum - (long long)n * min_val;
    cout << result << "\n";
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
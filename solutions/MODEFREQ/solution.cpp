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
    
    // Constraints say A_i <= 10, but we should handle general cases
    // Using a map to store frequency of each number
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
    // If ties, pick the smallest frequency
    for (auto const& [freq, occurrence] : freq_of_freq) {
        if (occurrence > max_occurrence) {
            max_occurrence = occurrence;
            best_freq = freq;
        } else if (occurrence == max_occurrence) {
            if (best_freq == -1 || freq < best_freq) {
                best_freq = freq;
            }
        }
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
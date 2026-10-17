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
 * or a hash map (std::unordered_map) to count occurrences.
 * Given the constraints and the requirement for ascending order, a std::map
 * is efficient enough (O(N log N)) and keeps keys sorted.
 * Alternatively, since we have a total of 150,000 elements, we can store all
 * elements in a single vector, sort them, and count consecutive occurrences.
 */

int main() {
    // Optimize I/O operations
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
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find a permutation A of size N such that A[i] != (A[i-1] | A[i-2]) for all 3 <= i <= N.
 * 
 * Consider the property of bitwise OR: (x | y) >= max(x, y).
 * If we arrange the numbers in a specific order, we can easily satisfy this.
 * A simple construction is to output the numbers in increasing order: 1, 2, 3, ..., N.
 * Let's check: A[i] = i, A[i-1] = i-1, A[i-2] = i-2.
 * Is i == ((i-1) | (i-2))?
 * For example, if i=4: 4 != (3 | 2) => 4 != 3. This holds.
 * If i=3: 3 != (2 | 1) => 3 != 3. This fails.
 * 
 * Let's try a simple permutation: 1, 2, 3, ..., N.
 * Actually, the simplest way to satisfy A[i] != (A[i-1] | A[i-2]) is to output 
 * the numbers in increasing order: 1, 2, 3, ..., N.
 * Wait, the condition is A[i] != (A[i-1] | A[i-2]).
 * If we use the sequence 1, 2, 3, ..., N:
 * For i=3: A[3]=3, A[2]=2, A[1]=1. (2 | 1) = 3. 3 == 3. Fails.
 * 
 * Let's try the sequence: 1, 3, 2, 4, 5, 6, ..., N.
 * For i=3: A[3]=2, A[2]=3, A[1]=1. (3 | 1) = 3. 2 != 3. Holds.
 * For i=4: A[4]=4, A[3]=2, A[2]=3. (2 | 3) = 3. 4 != 3. Holds.
 * For i=5: A[5]=5, A[4]=4, A[3]=2. (4 | 2) = 6. 5 != 6. Holds.
 * 
 * Actually, the simplest valid permutation is just 1, 2, 3, ..., N reversed? No.
 * How about just 1, 2, 3, ..., N? No.
 * How about N, N-1, ..., 1?
 * For N=3: 3, 2, 1. (2 | 3) = 3. 1 != 3. Holds.
 * For N=4: 4, 3, 2, 1. 
 * i=3: A[3]=2, A[2]=3, A[1]=4. (3 | 4) = 7. 2 != 7. Holds.
 * i=4: A[4]=1, A[3]=2, A[2]=3. (2 | 3) = 3. 1 != 3. Holds.
 * 
 * Yes, the sequence N, N-1, ..., 1 works for all N >= 3.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // Output the permutation N, N-1, ..., 1
        for (int i = n; i >= 1; --i) {
            cout << i << (i == 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
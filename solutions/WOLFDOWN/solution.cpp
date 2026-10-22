#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A wolf at position x eats a bird at x+1 and moves to x+1.
 * This effectively means a wolf can eat a bird if it is to the left of the bird.
 * Specifically, a bird at position 'i' is eaten if there exists a wolf at position 'j' (j < i)
 * such that the number of wolves to the left of or at 'j' is less than or equal to the 
 * number of birds available to be eaten.
 * 
 * More simply: A bird at position 'i' is safe if and only if the number of wolves 
 * to its left is 0. If there is at least one wolf to the left of a bird, that bird 
 * will eventually be eaten because wolves move forward and consume birds.
 * 
 * Let's verify:
 * If there is a wolf at index j < i, the wolf will move rightward. 
 * Since birds don't move, the wolf will eventually reach the bird at i unless 
 * it gets blocked or runs out of birds. However, the problem states the wolf 
 * moves to x+1 after eating. This implies the wolf effectively "claims" the 
 * space. Any bird at index i will be eaten if there is at least one wolf at 
 * any index j < i.
 * 
 * Therefore, a bird at index i is safe if and only if there are no wolves 
 * at any index j < i.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int safe_birds = 0;
    bool wolf_seen = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            wolf_seen = true;
        } else {
            // It's a bird
            if (!wolf_seen) {
                safe_birds++;
            }
        }
    }

    cout << safe_birds << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
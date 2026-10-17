#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N truth-tellers and M liars/truth-tellers (let's call them "unreliable").
 * We ask X people. We need to be sure of the path regardless of which X people we pick.
 * 
 * Let the two paths be P1 and P2.
 * Truth-tellers will always point to the correct path.
 * Unreliable people can point to either P1 or P2.
 * 
 * If we pick X people, in the worst case, we pick some number of truth-tellers (T) 
 * and some number of unreliable people (U), where T + U = X.
 * 
 * To be absolutely sure, the number of truth-tellers must be strictly greater than 
 * the number of unreliable people, because the unreliable people could all collude 
 * to lie or point to the wrong path.
 * 
 * Specifically, if we pick X people, the worst-case scenario is that we pick 
 * all M unreliable people and (X - M) truth-tellers.
 * If X <= M, we could pick only unreliable people, and they could all lie. 
 * Thus, we need X > M.
 * 
 * Even if X > M, we need to ensure that the truth-tellers provide a majority 
 * that cannot be overcome by the liars.
 * If we pick X people, the number of truth-tellers we are guaranteed to have is 
 * (X - M) (if X > M) or 0 (if X <= M).
 * The number of unreliable people is at most M.
 * We need the number of guaranteed truth-tellers to be greater than the number 
 * of unreliable people to identify the truth.
 * So, (X - M) > M  => X > 2M.
 * 
 * However, we are also limited by the total number of people N + M.
 * If N > M, we can always distinguish the truth by asking everyone (N + M).
 * If N <= M, even if we ask everyone, the liars (M) are >= truth-tellers (N), 
 * so we cannot be sure.
 * 
 * Re-evaluating:
 * If we ask X people, we are guaranteed to have at least max(0, X - M) truth-tellers.
 * We are also potentially facing M liars.
 * We need the number of truth-tellers to be strictly greater than the number of liars.
 * So, (X - M) > M => X > 2M.
 * Also, we must have enough truth-tellers available, so X <= N + M.
 * The condition is X = M + 1 + M = 2M + 1.
 * This is only possible if 2M + 1 <= N + M, which simplifies to M + 1 <= N.
 */

void solve() {
    int N, M;
    cin >> N >> M;

    // We need to be sure regardless of which X people we pick.
    // The worst case is picking all M unreliable people and some truth-tellers.
    // To be sure, the number of truth-tellers must be > number of liars.
    // If we pick X people, we have at least (X - M) truth-tellers.
    // We need (X - M) > M  => X > 2M.
    // The smallest such X is 2M + 1.
    // This is only possible if 2M + 1 <= N + M, which is N > M.
    
    if (N > M) {
        cout << 2 * M + 1 << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
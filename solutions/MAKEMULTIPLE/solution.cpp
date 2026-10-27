#include <iostream>
using namespace std;

void solve() {
    long long A, B;
    cin >> A >> B;
    if (B % A == 0) {
        cout << "YES" << endl;
    } else if (B - A >= A) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
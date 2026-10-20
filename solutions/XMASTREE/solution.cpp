#include <iostream>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, A, M, B;
    if (!(cin >> N >> A >> M >> B)) return 0;

    // Based on the explanation:
    // Profit = (Total Revenue from selling M trees) - (Total Cost of buying N trees)
    // Revenue = M * B
    // Cost = N * A
    long long profit = (long long)M * B - (long long)N * A;

    cout << profit << endl;

    return 0;
}
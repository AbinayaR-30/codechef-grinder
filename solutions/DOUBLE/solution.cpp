#include <iostream>

/**
 * Problem Analysis:
 * A "double string" of length 2k requires k pairs of characters.
 * Given a palindrome of length N:
 * - If N is even, all characters can be paired up. We can form a double string of length N.
 * - If N is odd, there is one character left over (the middle one). We can form a double string of length N-1.
 * 
 * The formula (N / 2) * 2 correctly handles both cases:
 * - If N = 2, (2/2)*2 = 2
 * - If N = 3, (3/2)*2 = 2
 * - If N = 4, (4/2)*2 = 4
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    if (!(std::cin >> T)) return 0;
    while (T--) {
        long long N;
        std::cin >> N;
        // The result is the largest even number less than or equal to N
        std::cout << (N / 2) * 2 << "\n";
    }
    return 0;
}
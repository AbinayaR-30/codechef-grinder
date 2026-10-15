#include <iostream>

/**
 * Problem Analysis:
 * Ved is a NEWBIE if M >= N / 2.0.
 * To avoid floating point arithmetic, we can multiply both sides by 2:
 * 2 * M >= N
 * 
 * If this condition holds, output NEWBIE, otherwise output PRO.
 * 
 * Constraints:
 * 1 <= N, M <= 1000.
 * The logic fits well within standard integer types.
 * 
 * Note: The input format specifies a single pair of N and M, 
 * not multiple test cases.
 */

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    if (std::cin >> N >> M) {
        // Condition: M >= N / 2.0
        // Equivalent to: 2 * M >= N
        if (2 * M >= N) {
            std::cout << "NEWBIE" << std::endl;
        } else {
            std::cout << "PRO" << std::endl;
        }
    }

    return 0;
}
#include <iostream>

/**
 * Problem Analysis:
 * Chef needs at least 25 total wins.
 * Current wins = X.
 * Wins needed = 25 - X.
 * Each year, Chef wins 4 Grand Slams.
 * Let Y be the number of years.
 * We need 4 * Y >= 25 - X.
 * 
 * Since X <= 24, 25 - X is always positive (1 to 25).
 * The number of years Y is the smallest integer such that 4 * Y >= 25 - X.
 * This is equivalent to ceil((25 - X) / 4.0).
 * Using integer arithmetic, this is (25 - X + 3) / 4.
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int X;
    if (!(std::cin >> X)) return 0;
    
    int needed = 25 - X;
    
    // Since constraints are 0 <= X <= 24, needed is always > 0.
    // Calculate ceiling of (needed / 4)
    int years = (needed + 3) / 4;
    
    std::cout << years << std::endl;

    return 0;
}
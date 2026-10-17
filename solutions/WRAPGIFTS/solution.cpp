#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The surface area of a rectangular box with dimensions H, L, and W is given by:
 * Surface Area = 2 * (H*L + L*W + W*H)
 * 
 * Chef has a total of 1000 square centimeters of wrapping paper.
 * The number of gifts that can be wrapped is the floor of (Total Area / Surface Area of one gift).
 * 
 * Constraints:
 * T <= 1000
 * 1 <= H, L, W <= 10
 * Surface Area = 2 * (H*L + L*W + W*H)
 * Max Surface Area = 2 * (10*10 + 10*10 + 10*10) = 2 * 300 = 600
 * Min Surface Area = 2 * (1*1 + 1*1 + 1*1) = 6
 * 
 * Since 1000 / 6 is approximately 166, the result will always fit in a standard integer.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long h, l, w;
        cin >> h >> l >> w;
        
        // Calculate surface area of one gift
        long long surface_area = 2 * (h * l + l * w + w * h);
        
        // Total available paper
        long long total_paper = 1000;
        
        // Calculate maximum number of gifts
        long long max_gifts = total_paper / surface_area;
        
        cout << max_gifts << "\n";
    }
    
    return 0;
}
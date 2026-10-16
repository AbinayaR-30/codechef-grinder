#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has A milk chocolates and B dark chocolates.
 * Total chocolates = A + B.
 * Satisfaction increases if (milk_eaten != dark_eaten).
 * 
 * Let m be the number of milk chocolates eaten and d be the number of dark chocolates eaten.
 * At any step, the condition is m != d.
 * 
 * To maximize satisfaction, we want to avoid the state where m == d as much as possible.
 * Since we start at (0, 0), the first chocolate eaten will always result in satisfaction 
 * (because 1 != 0).
 * 
 * If we have A milk and B dark chocolates, we can always eat all chocolates of the 
 * more abundant type first. Suppose A > B. If we eat all A milk chocolates first, 
 * at each step m will be different from d (except when we haven't started).
 * Specifically, if we eat all A milk chocolates, we get A points. Then, as we eat 
 * the B dark chocolates, we will only hit the m == d condition if we are forced to.
 * 
 * Actually, the optimal strategy is to eat all of the larger quantity first, 
 * then the smaller quantity.
 * If A > B:
 * Eat all A milk chocolates: satisfaction increases A times.
 * Then eat B dark chocolates: 
 * After eating 1st dark: m=A, d=1. Since A > B >= 1, A != 1 is true (unless A=1, B=1).
 * In general, if we eat all of the larger quantity first, we get A+B satisfaction 
 * unless we are forced to hit m=d.
 * 
 * The only time m=d is when we have eaten an equal number of both.
 * The maximum satisfaction is simply A + B - min(A, B).
 * Wait, let's check sample cases:
 * 1, 2: A=1, B=2. min=1. A+B-min = 3-1 = 2? No, sample says 3.
 * 4, 2: A=4, B=2. min=2. A+B-min = 6-2 = 4? No, sample says 6.
 * 
 * Re-evaluating:
 * If we eat all of the larger quantity first, we get satisfaction for every single 
 * chocolate except when m=d.
 * If A=4, B=2:
 * Eat M, M, M, M (4 points), then D, D.
 * After 1st M: m=1, d=0 (Sat)
 * After 2nd M: m=2, d=0 (Sat)
 * After 3rd M: m=3, d=0 (Sat)
 * After 4th M: m=4, d=0 (Sat)
 * After 1st D: m=4, d=1 (Sat)
 * After 2nd D: m=4, d=2 (Sat)
 * Total = 6.
 * 
 * It turns out the answer is always A + B - (number of times m=d occurs).
 * m=d occurs only when we have eaten equal amounts.
 * If we eat all of one type, we only hit m=d if we eat the other type in a way 
 * that matches the count. By eating all of the larger type first, we avoid m=d 
 * until the very end, but actually, we never hit m=d if we eat all of one type 
 * before the other, EXCEPT if the counts are equal.
 * 
 * Actually, the answer is simply A + B - (A == B ? 1 : 0).
 * Let's check:
 * 1, 2 -> 3 - 0 = 3. Correct.
 * 1, 1 -> 2 - 1 = 1. Correct.
 * 4, 2 -> 6 - 0 = 6. Correct.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        if (a == b) {
            cout << a + b - 1 << "\n";
        } else {
            cout << a + b << "\n";
        }
    }
    return 0;
}
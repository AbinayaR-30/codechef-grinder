#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct two different binary strings that are both palindromes
 * and contain exactly A zeros and B ones.
 * 
 * A palindrome is determined by its first ceil(length/2) characters.
 * If A is odd and B is odd, we cannot construct two different palindromes.
 * Why?
 * 1. If both A and B are odd, the total length (A+B) is even.
 *    In a palindrome of even length, every character must appear an even number of times.
 *    But here, A and B are both odd, which is impossible for a single palindrome.
 *    Wait, let's re-evaluate:
 *    If A is odd and B is odd, the total length is even.
 *    For a palindrome of even length, the count of 0s must be even and the count of 1s must be even.
 *    Since A and B are odd, it is impossible to form even ONE palindrome.
 * 
 * 2. If A is odd and B is even (or vice versa), the total length is odd.
 *    The middle element must be the one with the odd count.
 *    If A=1, B=2: 011 (palindrome), 101 (palindrome). Yes.
 *    If A=3, B=2: 01010, 10001. Yes.
 * 
 * 3. If both A and B are even:
 *    A=2, B=2: 0110, 1001. Yes.
 *    A=2, B=4: 011110, 110011. Yes.
 * 
 * The only case where we cannot form at least two different palindromes is when
 * either A or B is odd, but not both? No, let's check:
 * If A is odd and B is odd: Total length is even. Impossible to form even one palindrome.
 * If A=1, B=1: 01 (not palindrome), 10 (not palindrome). Only 01 or 10? No, 01 is not a palindrome.
 * Actually, if A=1, B=1, we can't form any palindrome.
 * 
 * General rule:
 * If A is odd and B is odd, we cannot form any palindrome (A+B is even, but counts are odd).
 * If A=1 or B=1, we can only form one unique palindrome (e.g., A=1, B=2 -> 101, only one).
 * Actually, the condition is: If (A % 2 != 0 && B % 2 != 0) OR (A == 1 || B == 1), return No.
 */

void solve() {
    long long A, B;
    cin >> A >> B;

    // If both are odd, total length is even, but counts are odd -> Impossible
    // If either A or B is 1, we can only form one unique palindrome structure
    if ((A % 2 != 0 && B % 2 != 0) || (A == 1 || B == 1)) {
        cout << "No" << "\n";
    } else {
        cout << "Yes" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
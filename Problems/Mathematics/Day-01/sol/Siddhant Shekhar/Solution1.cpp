/*
 * Problem: Find who person c is looking at in a circle
 * 
 * Approach:
 * - If a is looking at b, then the distance between opposite people is |b - a|
 * - This distance equals n/2 where n is total people
 * - So n = 2 * |b - a|
 * - Person c looks at person c + n/2 (or c - n/2 if that goes beyond n)
 * - Valid only if a, b, c are all within range [1, n]
 * 
 * Time Complexity: O(1) per test case
 * Space Complexity: O(1)
 * 
 * Submission Link: [ADD YOUR CODEFORCES SUBMISSION LINK HERE]
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        // Distance between opposite people = n/2
        long long half = abs(b - a);
        
        // Total people n = 2 * half
        long long n = 2 * half;
        
        // Check if a, b, c are valid (within [1, n])
        if (a > n || b > n || c > n || half == 0) {
            cout << -1 << endl;
            continue;
        }
        
        // Person c looks at person c + half or c - half
        long long ans;
        if (c + half <= n) {
            ans = c + half;
        } else {
            ans = c - half;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}

/*
 * Example I/O:
 * Input:
 * 7
 * 6 2 4
 * 2 3 1
 * 2 4 10
 * 5 3 4
 * 1 3 2
 * 2 5 4
 * 4 3 2
 * 
 * Output:
 * 8
 * -1
 * -1
 * -1
 * 4
 * 1
 * -1
 */

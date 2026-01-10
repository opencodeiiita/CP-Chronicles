/*
DAY 10
Q1 D1. Removal of a Sequence (Easy Version)

*/
/*
APPROACH:
Instead of simulating forward, work backwards from position k. For each removal 
operation, calculate the original position before removal using: 
position = position + (position-1)/(y-1). This formula works because every (y-1) 
surviving elements correspond to y original elements in the sequence.

TIME COMPLEXITY: O(x) per test case
SPACE COMPLEXITY: O(1)

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;
        
        // Special case: if y=1, all elements are removed
        if (y == 1) {
            cout << -1 << endl;
            continue;
        }
        
        long long position = k;
        bool valid = true;
        
        // Apply reverse operation x times to find original position
        for (int i = 0; i < x; i++) {
            // After removal, position k was originally at: k + (k-1)/(y-1)
            position = position + (position - 1) / (y - 1);
            
            // Check if position exceeds the sequence length
            if (position > 1000000000000LL) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            cout << position << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}

/*
My submission : https://codeforces.com/contest/2169/submission/356458328
*/
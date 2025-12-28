/*
DAY 3
Q2  Rational Resistance
.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    
    long long result = 0;
    
    while (a != 0) {
        result += b / a;
        long long temp = a;
        a = b % a;
        b = temp;
    }
    
    cout << result << "\n";
    
    return 0;
}


//Time Complexity: O(log min(a,b))
//Space Complexity: O(1)
/*
My submission : https://codeforces.com/contest/343/submission/355471064
*/
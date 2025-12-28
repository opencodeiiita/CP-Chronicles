#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int n = 2*(abs(a-b));

        if(a == b){
            cout << -1 << endl;
            continue;
        }

        if(a > n || b > n || c > n){
            cout  << -1 << endl;
            continue;
        }

        if(c + (n/2) <= n){
            cout << (c+(n/2)) << endl;
        }else{
            cout << (c-(n/2)) << endl;
        }

    }
    return 0;
}




/* Explaination : The opposite numbers must be having exactly n/2 numbers in between, hence the total number, ie. n = 2*abs(a-b).

Time Complexity : O(t), t is the number of test cases. 

Submission Link : https://codeforces.com/contest/1560/submission/355247479

*/
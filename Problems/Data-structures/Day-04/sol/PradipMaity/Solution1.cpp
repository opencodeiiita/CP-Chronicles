#include <bits/stdc++.h>
using namespace std;

/*
 cost of RBS = sum of current balance after each character
 so to minimize cost we keep balance as small as possible

 Strategy:
 fill odd positions greedily
 try to put ')' whenever possible
 only put '(' if necessary to stay valid or to ensure
 we can still place required '(' later
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int needOpen = n/2;              // total '(' required
        for(char c: s)
            if(c == '(') needOpen--;

        int bal = 0;                     // current balance
        long long cost = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '_'){
                int remaining = (n - i - 1);
                
                // if we place ')'
                // only allowed if:
                // 1) balance > 0 (won't go negative)
                // 2) still possible to place enough '(' later
                // i.e., remaining positions >= needOpen
                if(bal > 0 && remaining >= needOpen){
                    s[i] = ')';
                    bal--;
                }
                else{
                    s[i] = '(';
                    bal++;
                    needOpen--;
                }
            }
            else{
                if(s[i] == '(') bal++;
                else bal--;
            }

            cost += bal;
        }

        cout << cost << '\n';
    }
}


// Submission Link: https://codeforces.com/problemset/status?my=on 
/*
DAY 10
Q2 Perfect Ranges

*/
/*
APPROACH:
At every index we keep two values: the longest valid subsequence ending at this index if we choose a[i], and if we choose b[i].
For each position, we extend from the previous position only if the chosen value is strictly greater than the previous chosen value; otherwise we restart from length 1.
The answer is the sum of the better choice at every index.
TIME COMPLEXITY: O(n) 
SPACE COMPLEXITY: O(n)

*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void run() {
    ll n;
    cin >> n;

    vector<ll> x(n), y(n);
    for (auto &v : x) cin >> v;
    for (auto &v : y) cin >> v;

//pair banao ll,ll ka nahi toh scene hojayega
    vector<pair<ll,ll>> len(n);
    len[0] = {1, 1};

    for (ll i = 1; i < n; ++i) {
        ll a1 = 1, a2 = 1;

        if (x[i] > x[i-1] && x[i] > y[i-1])
            a1 = max(len[i-1].first, len[i-1].second) + 1;
        else if (x[i] > x[i-1])
            a1 = len[i-1].first + 1;
        else if (x[i] > y[i-1])
            a1 = len[i-1].second + 1;

        if (y[i] > x[i-1] && y[i] > y[i-1])
            a2 = max(len[i-1].first, len[i-1].second) + 1;
        else if (y[i] > x[i-1])
            a2 = len[i-1].first + 1;
        else if (y[i] > y[i-1])
            a2 = len[i-1].second + 1;

        len[i] = {a1, a2};
    }

    ll res = 0;
    for (auto &p : len) res += max(p.first, p.second);
    cout << res << "\n";
}

int main() {
  

    ll t;
    cin >> t;
    while (t--)
    {
        run();
    }
    //kardo return 0;
    return 0;
}


/*
My submission : https://www.codechef.com/viewsolution/1223516137
*/
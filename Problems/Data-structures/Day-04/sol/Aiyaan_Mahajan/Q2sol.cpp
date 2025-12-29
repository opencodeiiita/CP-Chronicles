/*
DAY 4
Q2 Accumulator Apex
.*/

#include <bits/stdc++.h>
using namespace std;

struct Item {
    long long pref;
    long long minPref;
    int idx;
};

struct Cmp {
    bool operator()(const Item& a, const Item& b) const {
        if (a.minPref != b.minPref) return a.minPref < b.minPref;
        return a.pref < b.pref;
    }
};

int main() {
 

    long long x;
    int k;
    cin >> x >> k;

    vector<vector<long long>> lists(k);
    for (int i = 0; i < k; ++i) {
        int len;
        cin >> len;
        lists[i].resize(len);
        for (int j = 0; j < len; ++j) cin >> lists[i][j];
    }

    priority_queue<Item, vector<Item>, Cmp> pq;
    vector<vector<long long>> pref(k);

    for (int i = 0; i < k; ++i) {
        long long s = 0, mn = 0;
        pref[i].push_back(0);
        for (auto v : lists[i]) {
            s += v;
            mn = min(mn, s);
            pref[i].push_back(s);
            pq.push({s, mn, i});
        }
    }

    long long best = x;
    vector<long long> taken(k, 0);

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (best + cur.minPref < 0) break;

        if (cur.pref > taken[cur.idx]) {
            best -= taken[cur.idx];
            best += cur.pref;
            taken[cur.idx] = cur.pref;
        }
    }

    cout << best << "\n";
    return 0;
}




//TC =O(Nlog(N)) and SC = O(N)
/*
My submission : https://codeforces.com/contest/1912/submission/355690272
*/
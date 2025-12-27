#include <bits/stdc++.h>
using namespace std;

static const int maxi = 100000;
int spf[maxi + 1];
int k;

/*sieve*/
void buildSPF() {
    for (int i = 1; i <= maxi; i++)
        spf[i] = i;

    for (int i = 2; i * i <= maxi; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= maxi; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

/*factorise*/
vector<pair<int,int>> getSignature(int x) {
    map<int,int> factors;

    while (x > 1) {
        int p = spf[x];
        factors[p]++;
        x /= p;
    }

    vector<pair<int,int>> sig;
    for (auto &it : factors) {
        int exp = it.second % k;
        if (exp != 0)
            sig.push_back({it.first, exp});
    }
    return sig;
}

/*how many needed*/
vector<pair<int,int>> getComplement(const vector<pair<int,int>> &sig) {
    vector<pair<int,int>> comp;
    for (auto &p : sig) {
        comp.push_back({p.first, (k - p.second) % k});
    }
    return comp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    buildSPF();

    map<vector<pair<int,int>>, long long> freq;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        vector<pair<int,int>> sig = getSignature(a[i]);
        vector<pair<int,int>> need = getComplement(sig);
        ans += freq[need];
        freq[sig]++;
    }
    cout << ans << "\n";
    return 0;
}
//https://codeforces.com/problemset/submission/1225/355302622
//time  complexity O(nlognlog(10^5))
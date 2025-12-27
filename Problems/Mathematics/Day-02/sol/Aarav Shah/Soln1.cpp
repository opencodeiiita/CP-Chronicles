    #include <bits/stdc++.h>
    using namespace std;

    #define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
    #define ll long long
    #define vll vector<ll>
    #define vi vector<int>
    #define pb push_back
    #define all(x) (x).begin(), (x).end()
    #define endl '\n'

    const ll MOD = 1e9 + 7;
    const ll INF = 1e18;

    ll gcdll(ll a, ll b) { return b ? gcdll(b, a % b) : a; }
    ll lcmll(ll a, ll b) { return a / gcdll(a, b) * b; }

    void solve() {
        int n;
        cin>>n;

        vll nums(n);
        for (int i = 0; i < n; i++)
        {
            cin>>nums[i];
        }
        long long maxi=INT_MIN;
        long long mini=INT_MAX;
        for (long long i = 0; i < n; i++)
        {
            maxi = max(maxi,nums[i]);
        }
        for (ll  i = 0; i < n; i++)
        {
            mini = min(mini,nums[i]);
        }
        long long diff = maxi-mini;

        map<int,int>mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
        }
        ll cnt1=mpp[maxi];
        ll cnt2=mpp[mini];
        
        if (maxi == mini) {
    cout << 1LL * n * (n - 1) << endl;
    return;
}
    cout<<cnt1*cnt2*2<<endl;

        
        
    }

    int main() {
        fastio;
        int t = 1;
        cin >> t;
        while (t--) solve();
        return 0;
    }
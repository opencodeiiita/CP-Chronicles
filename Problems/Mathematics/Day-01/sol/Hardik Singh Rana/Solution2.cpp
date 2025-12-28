#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fb(i,a,b) for(ll i=a;i>=b;i--)
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const ll MOD = 1e9+7;
const ll INF = 1e18;
/*
We need to count the no of pairs such that their product makes some number's k-th power-this means the product of the two numbers should have
factors frequency that is divisible by k. For every number first factorize it using spf(also store its factors mod k) and also store how much
factor more it needs to make the k-th power add this for all numbers.

*/

/* Submission Link: https://codeforces.com/contest/1225/submission/355183203 */
void solve() {
    int n,k;
    cin>>n>>k;
    vi a(n);
    f(i,0,n) cin>>a[i];
    vi spf(1e5+1);
    f(i,1,1e5+1) spf[i]=i;
    for(int i=2;i*i<=1e5;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=1e5;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
    map<vpii,ll> cnt;
    ll ans=0;
    for(int x:a){
        map<int,int> factors;
        while(x>1){
            int p=spf[x];
            int c=0;
            while(x%p==0){
                x/=p;
                c++;
            }
            c%=k;
            if(c>0)
                factors[p]=c;
        }
        vpii key,need;
        for(auto &it:factors){
            key.pb(it);
            int y=(k-it.second)%k;
            if(y>0){
                need.pb({it.first,y});
            }
        }
        ans+=cnt[need];
        cnt[key]++;
    }
    cout<<ans<<endl;
}

int main() {
    fast_io;
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}

// ----------------------------------------------------------------------
//                   ██████╗ ██████╗ ██████╗ ███████╗
//                  ██╔════╝██╔═══██╗██╔══██╗██╔════╝
//                  ██║     ██║   ██║██║  ██║█████╗
//                  ██║     ██║   ██║██║  ██║██╔══╝
//                  ╚██████╗╚██████╔╝██████╔╝███████╗
//                   ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝
// ----------------------------------------------------------------------
//                       Prashant'S CP TEMPLATE
//                       "Think. Code. Conquer."
// ----------------------------------------------------------------------
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<bit>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<iterator>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstdint>
#include<cstdlib>
using namespace std;
#define ll long long
#define int long long
#define MOD 1000000007
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(x) (int)(x).size()
#define srt(v) sort(v.begin(),v.end())
#define Rsrt(v) sort(v.begin(),v.end(),greater<int>())
#define endl "\n"
#define F first
#define S second
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define umap unordered_map
#define mii map<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i>b;i--)
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
void solve(){
    int x,y,k;
    cin>>x>>y>>k;
    int pos=k;
    fr(i,0,x){
        int maxPossible=1e12;
        int removed=maxPossible/y;
        int remaining=maxPossible-removed;
        if(pos>remaining){
            cout<<-1<<endl;
            return;
        }
        pos=pos+(pos-1)/(y-1);
    }
    cout<<pos<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

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
vi bfs(int start,int n,vvi& adj){
    vi dist(n+1,-1);
    queue<int> q;
    q.push(start);
    dist[start]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vvi adj(n+1);
    fr(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi distAlice=bfs(1,n,adj);
    vi distBob=bfs(x,n,adj);
    int maxDist=0;
    fr(i,1,n+1){
        if(distBob[i]<distAlice[i]){
            maxDist=max(maxDist,distAlice[i]);
        }
    }
    cout<<2*maxDist<<endl;
    return 0;
}

/*
Submission Link:
https://codeforces.com/contest/813/submission/356727323



Problem: The Tag Game
Link: https://codeforces.com/contest/813/problem/C
Author: Krishna200608

Approach:

    1. The game is played on a tree with Alice starting at node 1 and Bob at node x.
    2. Alice wants to catch Bob as quickly as possible, while Bob wants to delay.
    3. Bob’s optimal strategy is to move to a node that he can reach before Alice
    and that is as far from the root as possible.
    4. Once Bob reaches such a node, Alice is forced to travel down that path
    and back, increasing the total moves.
    5. Use two BFS traversals to calculate distances from Alice (node 1)
    and Bob (node x) to all nodes.
    6. For every node Bob reaches earlier than Alice, compute 2 × distance from root.
    7. The maximum such value is the number of moves Alice makes.

Complexity:
    Time: O(N)
    Space: O(N)
*/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
const int M = 1e9+7;
const double PI = acos(-1.0);
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define ll long long
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define ff first
#define ss second
#define inn(x) int x; cin >> x;
#define ill(x) ll x; cin >> x;
#define all(x) x.begin(),x.end()
#define in(a) for(int i = 0; i < (int)a.size(); i++) cin >> a[i];
#define out(a) for(int i = 0; i < (int)a.size(); i++) cout << a[i] << " ";
typedef vector<int> vi;
typedef vector<ll> vll;
#define ceil_div(n, x) (((n) % (x) == 0) ? ((n) / (x)) : ((n) / (x) + 1))
#define debug(x) cout << "x -> " << x << endl;
#define outt(x) cout << x << endl;
#define endl "\n"

vi adj[200005];
int d1[200005];
int d2[200005];

void bfs(int start, int *dist, int n) {
    for(int i = 1; i <= n; i++) dist[i] = -1;
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve() {

    inn(n) inn(x)

    for(int i = 1; i <= n; i++) 
        adj[i].clear();

    for(int i = 0; i < n - 1; i++) {
        inn(u)
        inn(v)
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bfs(1, d1,n);
    bfs(x, d2, n);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(d2[i] < d1[i]) {
            ans = max(ans, 2 * d1[i]);
        }
    }

    outt(ans);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto begin = chrono::high_resolution_clock::now();

    int t = 1;
    while(t--) solve();

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-6 << "ms";

    return 0;
}

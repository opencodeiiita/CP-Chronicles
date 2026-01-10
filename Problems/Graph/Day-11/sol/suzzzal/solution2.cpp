//submission - https://codeforces.com/contest/813/submission/357010458
/*
Approach:
ffirst, we build the tree using an adjacency list.
then we run a BFS from node 1 to find the distance of every node from node 1.
after that, we start another BFS from node x.
in this BFS, we   move only to those nodes where the stored distance is greater than the current time.
while doing this, we keep updating the maximum distance we can reach safely.
Finally, we print twice this maximum distance because we go and return.

Time Complexity:
O(N)  
Space Complexity:
O(N)  
Data Structures Used:
Adjacency List to store the tree.  
Queue for BFS.  
Vectors to store distance and visited information.


*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> d(n + 1, INT_MAX);
    vector<int> vis(n + 1, 0);

    queue<pair<int,int>> q;
    q.push({1, 0});
    vis[1] = 1;

    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        int cur = p.first;
        int dis = p.second;

        d[cur] = dis;

        for (int nxt : g[cur]) {
            if (!vis[nxt]) {
                vis[nxt] = 1;
                q.push({nxt, dis + 1});
            }
        }
    }

    for (int i = 1; i <= n; i++) vis[i] = 0;

    int mx = d[s];

    vis[s] = 1;
    q.push({s, 0});

    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        int cur = p.first;
        int t = p.second + 1;

        for (int nxt : g[cur]) {
            if (!vis[nxt] && d[nxt] > t) {
                vis[nxt] = 1;
                mx = max(mx, d[nxt]);
                q.push({nxt, t});
            }
        }
    }

    cout << mx+mx << endl;

    return 0;
}

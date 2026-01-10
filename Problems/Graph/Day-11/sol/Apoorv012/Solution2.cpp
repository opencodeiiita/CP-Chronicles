/*
Submission Link: https://codeforces.com/contest/813/submission/356911553

First get the distance of each node from root node, by djikstras.
Then, go BFS from the X, and calculate the time taken to reach that node by Bob.
If the distance is more than time taken, then we can consider that node, and get the max distance.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n+1, INT_MAX);
    vector<int> vis(n+1, 0);
    queue<pair<int, int>> q;
    q.push({1, 0});
    vis[1] = 1;
    while (!q.empty()) {
        auto [node, d] = q.front();
        q.pop();
        dist[node] = d;
        for (auto neigh: adj[node]) {
            if (!vis[neigh]) {
                vis[neigh] = 1;
                q.push({neigh, d+1});
            }
        }
    }
    vis.assign(n+1, 0);
    int maxDist = dist[x];

    vis[x] = 1;
    q.push({x, 0});
    while (!q.empty()) {
        auto [node, time] = q.front();
        q.pop();
        time++;
        for (auto neigh: adj[node]) {
            if (!vis[neigh] && dist[neigh] > time) {
                vis[neigh] = 1;
                maxDist = max(maxDist, dist[neigh]);
                q.push({neigh, time});
            }
        }
    }

    cout << (2*maxDist) << endl;




    // for (int i = 1; i <= n; i++) {
    //     cout << dist[i] << " ";
    // }
    // cout << endl;
}
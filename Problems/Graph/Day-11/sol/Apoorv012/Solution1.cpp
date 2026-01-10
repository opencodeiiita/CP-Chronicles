/*
Submission Link: https://codeforces.com/contest/580/submission/357196048

So, I kept a record of the current consecutive cats found. Then applied a DFS traversal, and if the the record is more than allowed, so, i end that vine. I only add 1 at leaf nodes.
*/
    
#include <bits/stdc++.h>
using namespace std;

int solve(int node, int parent, int curr, int tolerance, vector<int> &cat, vector<vector<int>> &adj) {
    // cout << "at node: " << node << endl;
    if (curr + cat[node] > tolerance) return 0;
    if (adj[node].size() <= 1 && parent != -1) {
        // cout << node << " ans\n";
        return 1;
    }

    if (cat[node]) {
        curr++;
    }
    else {
        curr = 0;
    }

    int ans = 0;
    for (auto neigh: adj[node]) {
        if (neigh == parent) continue;
        ans += solve(neigh, node, curr, tolerance, cat, adj);
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> cat(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> cat[i];
    }

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = solve(1, -1, 0, m, cat, adj);
    cout << ans;
}
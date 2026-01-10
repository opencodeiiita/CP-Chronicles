/*

Submission link - https://codeforces.com/contest/580/submission/356912179

TC- O(N)
SC -O(N)

APProach:
Store the graph as a list where each node keeps track of its neighbors.
Keep a list (visited) to remember which nodes we have already seen.
Go through every node one by one:
If a node has not been visited yet, start a DFS from it.
During DFS, mark the current node and all nodes connected to it as visited.
This means we have found one complete group (one connected component).
Count how many times we start DFS.
That count is the number of connected components in the graph.



*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int cats[MAXN];
int n, m, ans = 0;

void dfs(int u, int p, int streak) {
    if (cats[u]) streak++;
    else streak = 0;

    if (streak > m) return;

    bool leaf = true;
    for (int v : adj[u]) {
        if (v != p) {
            leaf = false;
            dfs(v, u, streak);
        }
    }

    if (leaf && u != 0) {
        ans++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);

    cout << ans << endl;

    return 0;
}
/*
submission - https://codeforces.com/problemset/submission/580/357009417


Approach:
We are given a tree and each node may or may not have a cat.
We start from node 1 and use DFS to visit all possible paths.
While moving, we keep track of how many cats we have seen continuously using an array.
If at any point the number of cats becomes more than m, we stop exploring that path.
Whenever we reach a leaf node and the condition is still satisfied, we count it as a valid path.
In this way, we explore all paths and count only the valid ones.

Time Complexity:
O(N)  
Each node and edge is visited only once in the DFS traversal.

Space Complexity:
O(N)  
Used for adjacency list, visited array, and recursion stack.

Data Structure Used:
Adjacency List (vector of vectors) for storing the tree.  
Arrays/Vectors for visited nodes and cat count.  
Recursion stack for DFS traversal.
*/

#include <bits/stdc++.h>
using namespace std;

int answer = 0;

void dfs(int node,
         vector<int>& cats,
         vector<vector<int>>& adj,
         vector<int>& visited,
         int maxCats,
         vector<int>& countCats) {

    visited[node] = 1;
    bool hasChild = false;
    bool invalidPath = false;

    for (int next : adj[node]) {
        if (!visited[next]) {
            hasChild = true;

            if (cats[next] == 1) {
                countCats[next] = countCats[node] + 1;
                if (countCats[next] > maxCats) {
                    invalidPath = true;
                    continue;
                }
            }

            dfs(next, cats, adj, visited, maxCats, countCats);
        }
    }

    if (!invalidPath && !hasChild) {
        answer++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> cats(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n + 1, 0);
    vector<int> countCats(n + 1, 0);

    if (cats[1] == 1) {
        countCats[1] = 1;
    }

    dfs(1, cats, adj, visited, m, countCats);

    cout << answer << endl;

    return 0;
}

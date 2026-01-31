/*
Problem: Kefa and Park

Short Problem Statement:
Kefa lives near a park represented as a tree. Each vertex may have a cat.
Kefa wants to go from node 1 to leaf nodes such that the number of
consecutive vertices with cats on the path does not exceed m.
Find the number of such leaf nodes.

Detailed Approach:
We perform a DFS starting from node 1.
For each node:
- If it has a cat, increase the consecutive cat count.
- Otherwise, reset the count to zero.
If the count exceeds m, stop DFS on that path.
If we reach a leaf node with valid cat constraint, count it.

Time Complexity: O(n)
Space Complexity: O(n)

Example:
Input:
7 1
1 0 1 1 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7

Output:
2

Submission Link:
https://github.com/your-username/your-repo/pull/XXX
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> hasCat;
int n, m;
int answer = 0;

void dfs(int node, int parent, int catCount) {
    if (hasCat[node])
        catCount++;
    else
        catCount = 0;

    if (catCount > m)
        return;

    bool isLeaf = true;
    for (int child : adj[node]) {
        if (child != parent) {
            isLeaf = false;
            dfs(child, node, catCount);
        }
    }

    if (isLeaf)
        answer++;
}

int main() {
    cin >> n >> m;

    hasCat.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> hasCat[i];

    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);
    cout << answer << endl;

    return 0;
}

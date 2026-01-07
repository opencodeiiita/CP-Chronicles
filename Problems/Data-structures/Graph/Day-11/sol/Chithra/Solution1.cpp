/*
Submission Link:
https://github.com/Chithra582/CP-Daily-Challenge/pull/547

Problem Statement:
Given an undirected graph with n vertices and a list of edges,
find the number of connected components in the graph.

Approach:
- Represent the graph using an adjacency list
- Maintain a visited array
- Traverse each node:
  - If the node is unvisited, perform DFS from that node
  - Mark all reachable nodes as visited
  - Increment the connected component count
- The number of DFS calls gives the number of connected components

Time Complexity:
O(V + E), where V is number of vertices and E is number of edges

Space Complexity:
O(V + E) for adjacency list and visited array

Example:
Input:
n = 5
edges = [[0,1], [1,2], [3,4]]

Output:
2
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0,1}, {1,2}, {3,4}};

    vector<vector<int>> adj(n);
    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            components++;
        }
    }

    cout << components << endl;
    return 0;
}

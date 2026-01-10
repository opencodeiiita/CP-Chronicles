#include <iostream>
#include <vector>


/*
Problem: Kefa and Park (Codeforces 580C)

Short Statement:
Given a rooted tree with vertices marked as having a cat or not, find the number of leaf nodes (restaurants) 
reachable from the root such that the path contains no more than 'm' consecutive vertices with cats.

Detailed Approach:
1. We represent the tree using an adjacency list.
2. We perform a Depth First Search (DFS) starting from the root (vertex 1).
3. During the traversal, we maintain a variable `consecutiveCats` for the current path:
   - If the current node has a cat, we increment `consecutiveCats`.
   - If the current node does not have a cat, we reset `consecutiveCats` to 0 (since the sequence is broken).
4. Pruning Condition: If `consecutiveCats` exceeds 'm' at any point, we stop traversing that branch immediately 
   because any restaurant down that path is unreachable.
5. Leaf Check: If we reach a node that has no children (except its parent) and the path is valid, we increment our answer.

Time Complexity: O(N) - We visit each node and edge exactly once.
Space Complexity: O(N) - Used for the adjacency list and the recursion stack.

// Submission Link: https://codeforces.com/contest/580/submission/357205990
*/

using namespace std;
const int MAXN = 100005;
vector<int> adj[MAXN];
int hasCat[MAXN];
int n, m;
int totalRestaurants = 0;
void dfs(int u, int p, int consecutiveCats) {
    if (hasCat[u]) {
        consecutiveCats++;
    } else {
        consecutiveCats = 0;
    }
    if (consecutiveCats > m) {
        return;
    }
    bool isLeaf = true;
    for (int v : adj[u]) {
        if (v != p) {
            isLeaf = false;
            dfs(v, u, consecutiveCats);
        }
    }
    if (isLeaf) {
        totalRestaurants++;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!(cin >> n >> m)) return 0;
    for (int i = 1; i <= n; i++) cin >> hasCat[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1, 0);
    cout << totalRestaurants << endl;
    return 0;
}
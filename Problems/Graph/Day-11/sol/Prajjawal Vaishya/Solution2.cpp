#include <iostream>
#include <vector>
#include <algorithm>


/*
Problem: The Tag Game (Codeforces 813C)

Short Statement:
Alice (at root 1) and Bob (at node x) play a tag game on a tree. They move in turns (Bob first). 
Bob wants to maximize the game duration, Alice wants to minimize it. The game ends when they meet.
Calculate the total number of moves made.

Detailed Approach:
1. This is a shortest-path problem on a tree. We need two distance arrays:
   - `distAlice[u]`: Distance from the root (1) to node u.
   - `distBob[u]`: Distance from Bob's start (x) to node u.
2. We perform two DFS traversals to populate these arrays.
3. Bob's strategy: He will try to reach a node `u` that is as far from the root as possible 
   (maximizing the game duration), but he can only safely reach nodes where he arrives strictly 
   faster than Alice (`distBob[u] < distAlice[u]`).
4. If Bob reaches such a node `u`, Alice is forced to chase him there. Since she has to traverse 
   the full path down and effectively "catch" him at the deepest point, the total moves will be `2 * distAlice[u]`.
5. We iterate through all nodes, check the condition, and find the maximum result.

Time Complexity: O(N) - Two DFS traversals and one linear scan.
Space Complexity: O(N) - For adjacency list and distance arrays.

// Submission Link: https://codeforces.com/contest/813/submission/357208042
*/

using namespace std;

const int MAXN = 200005;

vector<int> adj[MAXN];
int distAlice[MAXN];
int distBob[MAXN];     
void dfs(int u, int p, int d, int* distArray) {
    distArray[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1, distArray);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    if (!(cin >> n >> x)) return 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0, distAlice);
    dfs(x, 0, 0, distBob);
    int maxMoves = 0;
    for (int i = 1; i <= n; i++) {
        if (distBob[i] < distAlice[i]) {
            maxMoves = max(maxMoves, 2 * distAlice[i]);
        }
    }
    cout << maxMoves << endl;
    return 0;
}
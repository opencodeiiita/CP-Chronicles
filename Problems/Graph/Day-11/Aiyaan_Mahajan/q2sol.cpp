/*
DAY 11 The Tag Game

*/
/*
APPROACH:
Alice starts at the root (1) and Bob starts at node x.

Bob wants to maximize the time before Alice catches him, Alice wants to minimize it.

Optimal play leads to this insight:

Bob will run away from Alice along the tree, choosing a node farthest from Alice.

Alice will always move along the shortest path to Bob.

The game length depends on:

distAlice[v] = distance from root (Alice)

distBob[v] = distance from Bob’s start

Bob can safely stay at nodes where distBob[v] < distAlice[v]

Among such nodes, Bob chooses the maximum distAlice[v]

Final answer = 2 * max(distAlice[v])
TIME COMPLEXITY: O(n) 
SPACE COMPLEXITY: O(n)

*/
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, x;
    cin >> n >> x;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Distance from Alice (root = 1)
    vector<int> distAlice(n + 1, -1);
    queue<int> q;
    q.push(1);
    distAlice[1] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (distAlice[v] == -1) {
                distAlice[v] = distAlice[u] + 1;
                q.push(v);
            }
        }
    }

    // Distance from Bob (start = x)
    vector<int> distBob(n + 1, -1);
    q.push(x);
    distBob[x] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (distBob[v] == -1) {
                distBob[v] = distBob[u] + 1;
                q.push(v);
            }
        }
    }

    int best = 0;
    for (int v = 1; v <= n; v++) {
        if (distBob[v] < distAlice[v]) {
            best = max(best, distAlice[v]);
        }
    }

    cout << 2 * best << "\n";
    return 0;
}
/*
My submission :https://codeforces.com/contest/813/submission/357114596
*/
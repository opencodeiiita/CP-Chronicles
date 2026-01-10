/*
DAY 11 Kefa and park

*/
/*
APPROACH:
Use DFS starting from the root (node 1) and keep track of the number of consecutive vertices with cats along the current path. If the count exceeds m, stop exploring that path. Whenever a leaf node is reached within the limit, count it as a valid restaurant.
TIME COMPLEXITY: O(n) 
SPACE COMPLEXITY: O(n)

*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> hasCat;
int n, m;
int answer = 0;

void dfs(int node, int parent, int consecutiveCats) {
    // Update consecutive cat count
    if (hasCat[node] == 1)
        consecutiveCats++;
    else
        consecutiveCats = 0;

    // If limit exceeded, stop exploring this path
    if (consecutiveCats > m)
        return;

    bool isLeaf = true;

    for (int child : tree[node]) {
        if (child != parent) {
            isLeaf = false;
            dfs(child, node, consecutiveCats);
        }
    }

    // If node is a leaf (not root), count it
    if (isLeaf && node != 1)
        answer++;
}

int main() {

    cin >> n >> m;

    hasCat.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> hasCat[i];
    }

    tree.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(1, 0, 0);

    cout << answer << "\n";
    return 0;
}


/*
My submission : https://codeforces.com/contest/580/submission/357001196
*/
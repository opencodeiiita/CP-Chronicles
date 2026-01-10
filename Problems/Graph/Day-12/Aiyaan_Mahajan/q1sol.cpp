/*
DAY 12 Cycle in Maze

*/
/*
APPROACH:
First, run BFS from the start cell to compute the minimum distance from every cell back to the start.

A valid cycle is possible only if k is even and the start cell has at least one reachable neighbor.

Build the answer greedily for k steps, always trying moves in lexicographical order (D, L, R, U).

A move is chosen only if the robot can still return to the start within the remaining steps.
TIME COMPLEXITY: O(n*m) 
SPACE COMPLEXITY: O(n*m)

*/
#include <bits/stdc++.h>
using namespace std;

int main() {


    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                sx = i;
                sy = j;
                grid[i][j] = '.';
            }
        }
    }

    if (k % 2 == 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;
    dist[sx][sy] = 0;
    q.push({sx, sy});

    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == '*' || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    if (dist[sx][sy] != 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    string ans;
    int x = sx, y = sy;
    long long rem = k;

    string dir = "DLRU";
    int mx[4] = {1, 0, 0, -1};
    int my[4] = {0, -1, 1, 0};

    while (rem--) {
        bool moved = false;
        for (int d = 0; d < 4; d++) {
            int nx = x + mx[d];
            int ny = y + my[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == '*') continue;
            if (dist[nx][ny] != -1 && dist[nx][ny] <= rem) {
                ans += dir[d];
                x = nx;
                y = ny;
                moved = true;
                break;
            }
        }
        if (!moved) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    if (x == sx && y == sy) cout << ans << "\n";
    else cout << "IMPOSSIBLE\n";

    return 0;
}

/*
My submission :https://codeforces.com/contest/769/submission/357206548
*/
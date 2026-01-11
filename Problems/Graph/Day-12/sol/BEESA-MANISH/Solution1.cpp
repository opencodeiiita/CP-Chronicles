/*
Submission link - https://codeforces.com/contest/769/submission/357350706

TC - O(N*M+K)
SC - O(N*M+K)

Approach :
First, use BFS to find the minimum distance from every cell back to the starting cell.
A cycle is possible only if k is even and the start cell can move to at least one neighbor.
Now build the path step by step for k moves.
At each step, try moves in alphabetical order (D, L, R, U) and choose a move only if it’s still possible to come back to the start in the remaining steps.
*/


#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dc[] = {'D', 'L', 'R', 'U'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    if (k % 2 != 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<string> grid(n);
    int sx = -1, sy = -1;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'X') {
                sx = i;
                sy = j;
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '*' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[curr.first][curr.second] + 1;
                q.push({nx, ny});
            }
        }
    }

    string path = "";
    int cx = sx, cy = sy;

    bool can_move = false;
    for (int i = 0; i < 4; ++i) {
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '*') {
            can_move = true;
            break;
        }
    }

    if (!can_move) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int step = 1; step <= k; ++step) {
        bool moved = false;
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '*') {
                if (dist[nx][ny] <= k - step) {
                    path += dc[i];
                    cx = nx;
                    cy = ny;
                    moved = true;
                    break;
                }
            }
        }
        if (!moved) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << path << endl;

    return 0;
}
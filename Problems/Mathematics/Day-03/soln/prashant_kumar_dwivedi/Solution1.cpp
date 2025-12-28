#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
You are given a string of length 48 consisting of characters:
'U', 'R', 'D', 'L' and '?'.

You start at cell (1,1) in a 7×7 grid and must reach cell (7,1)
in exactly 48 moves.

Rules:
- Each move goes one cell Up, Right, Down, or Left.
- You cannot visit the same cell more than once.
- If the character is fixed (U/R/D/L), you must follow it.
- If the character is '?', you may choose any direction.

The task is to count the total number of valid paths.

---------------------------------------
Pruning Rules Used:
1. If both left and right cells are blocked, but up and down are free,
   the grid is split vertically → invalid path.
2. If both up and down cells are blocked, but left and right are free,
   the grid is split horizontally → invalid path.

---------------------------------------
Implementation Details:
- A 9×9 grid is used instead of 7×7.
- The outer boundary is permanently marked as visited.
  This avoids explicit boundary checks during DFS.
- DFS tracks the current step and position.
- Backtracking is used to unmark cells after recursion.

---------------------------------------
Approach:
1. Read the input string.
2. Initialize the grid with blocked borders.
3. Run DFS starting from (1,1) with step = 0.
4. Count all valid paths that reach (7,1) at exactly step 48.

---------------------------------------
Time Complexity:
Highly pruned DFS.
Effectively runs within limits due to early termination
of impossible paths.

---------------------------------------
Space Complexity:
O(1), since the grid size is constant (9×9).

---------------------------------------
Constraints:
- Path length is fixed at 48.
- Grid size is fixed (7×7 usable area).

---------------------------------------
*/

string s;
bool used[9][9];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int dfs(int step, int r, int c) {

    if (r == 7 && c == 1) {
        return step == 48 ? 1 : 0;
    }

    if (step == 48) return 0;

    if (used[r][c - 1] && used[r][c + 1] &&
       !used[r - 1][c] && !used[r + 1][c]) return 0;

    if (used[r - 1][c] && used[r + 1][c] &&
       !used[r][c - 1] && !used[r][c + 1]) return 0;

    used[r][c] = true;
    int ways = 0;

    char ch = s[step];

    if (ch != '?') {
        int d;
        if (ch == 'U') d = 0;
        else if (ch == 'R') d = 1;
        else if (ch == 'D') d = 2;
        else d = 3;

        int nr = r + dr[d];
        int nc = c + dc[d];
        if (!used[nr][nc]) {
            ways += dfs(step + 1, nr, nc);
        }
    } else {
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (!used[nr][nc]) {
                ways += dfs(step + 1, nr, nc);
            }
        }
    }

    used[r][c] = false;
    return ways;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    for (int i = 0; i < 9; i++) {
        used[0][i] = used[8][i] = true;
        used[i][0] = used[i][8] = true;
    }

    cout << dfs(0, 1, 1) << '\n';
    return 0;
}

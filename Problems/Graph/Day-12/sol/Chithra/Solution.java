//Submission Link - https://codeforces.com/contest/769/submission/360846897
//// Approach:
// Use BFS to compute the shortest distance from every cell to the starting cell.
// Then greedily build the path of length k by always choosing the lexicographically
// smallest valid move (D, L, R, U) that allows returning to the start within the
// remaining steps while preserving parity.
// Time Complexity:
// BFS takes O(n * m) and path construction takes O(k), so total time is O(n * m + k).
// Space Complexity:
// O(n * m) for the grid and distance array.
import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int k;
    static char[][] grid;
    static int[][] dist;
    static int sx, sy;

    static int[] dx = {1, 0, 0, -1};     // D L R U
    static int[] dy = {0, -1, 1, 0};
    static char[] dir = {'D', 'L', 'R', 'U'};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        grid = new char[n][m];
        dist = new int[n][m];

        for (int i = 0; i < n; i++) {
            Arrays.fill(dist[i], -1);
        }

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                grid[i][j] = s.charAt(j);
                if (grid[i][j] == 'X') {
                    sx = i;
                    sy = j;
                    grid[i][j] = '.';
                }
            }
        }

        if (k % 2 == 1) {
            System.out.println("IMPOSSIBLE");
            return;
        }

        bfs();

        if (dist[sx][sy] == -1) {
            System.out.println("IMPOSSIBLE");
            return;
        }

        StringBuilder ans = new StringBuilder();
        int x = sx, y = sy;

        for (int step = 0; step < k; step++) {
            boolean moved = false;
            int remaining = k - step - 1;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (grid[nx][ny] == '*') continue;
                if (dist[nx][ny] == -1) continue;

                if (dist[nx][ny] <= remaining && (remaining - dist[nx][ny]) % 2 == 0) {
                    ans.append(dir[d]);
                    x = nx;
                    y = ny;
                    moved = true;
                    break;
                }
            }

            if (!moved) {
                System.out.println("IMPOSSIBLE");
                return;
            }
        }

        System.out.println(ans.toString());
    }

    static void bfs() {
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{sx, sy});
        dist[sx][sy] = 0;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0], y = cur[1];

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (grid[nx][ny] == '*') continue;
                if (dist[nx][ny] != -1) continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.add(new int[]{nx, ny});
            }
        }
    }
}
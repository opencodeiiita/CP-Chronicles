/*Submission Link - https://codeforces.com/contest/813/submission/360850628
Approach & Complexity: Use two BFS to compute distances from Alice and Bob, let Bob choose the 
farthest node where dB < dA, and the answer is 2 × max(dA) with O(n) time and O(n) space. */
import java.io.*;
import java.util.*;

public class Main {
    static int n, x;
    static List<Integer>[] tree;
    static int[] distA, distB;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());

        tree = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++)
            tree[i] = new ArrayList<>();

        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            tree[a].add(b);
            tree[b].add(a);
        }

        distA = bfs(1);  
        distB = bfs(x);   

        int best = 0;
        for (int i = 1; i <= n; i++) {
            if (distB[i] < distA[i]) {
                best = Math.max(best, distA[i]);
            }
        }

        System.out.println(2 * best);
    }

    static int[] bfs(int start) {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, -1);

        Queue<Integer> q = new ArrayDeque<>();
        q.add(start);
        dist[start] = 0;

        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : tree[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.add(v);
                }
            }
        }
        return dist;
    }
}
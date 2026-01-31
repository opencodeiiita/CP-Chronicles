/*
Problem: C. Kefa and Park

Approach:
- Represent the park as a tree using an adjacency list.
- Use DFS starting from the root (node 1).
- Track the number of consecutive vertices with cats on the current path.
- If the count exceeds m, stop exploring that path.
- Count leaf nodes (restaurants) that satisfy the condition.

Time Complexity: O(n)
Space Complexity: O(n)

Submission link: https://codeforces.com/contest/769/submission/360849037
*/
import java.io.*;
import java.util.*;
 
public class Main {
    static int n, m;
    static int[] cat;
    static List<Integer>[] tree;
    static int answer = 0;
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
 
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
 
        cat = new int[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            cat[i] = Integer.parseInt(st.nextToken());
        }
 
        tree = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            tree[i] = new ArrayList<>();
        }
 
        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            tree[u].add(v);
            tree[v].add(u);
        }
 
        dfs(1, 0, 0);
 
        System.out.println(answer);
    }
 
    static void dfs(int node, int parent, int consecutiveCats) {
        if (cat[node] == 1) {
            consecutiveCats++;
        } else {
            consecutiveCats = 0;
        }
        if (consecutiveCats > m) return;
 
        boolean isLeaf = true;
 
        for (int next : tree[node]) {
            if (next != parent) {
                isLeaf = false;
                dfs(next, node, consecutiveCats);
            }
        }
 
        if (isLeaf) {
            answer++;
        }
    }
}
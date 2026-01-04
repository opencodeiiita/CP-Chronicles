// 1. Problem Statement -------------------------------------------------
/*
Given an array of n distinct integers.
Define the weakness as the number of triplets (i, j, k) such that:
i < j < k and a[i] > a[j] > a[k].

You need to count all such decreasing triplets.
Constraints are large, so brute force is not allowed.
*/

// 2. Approach -----------------------------------------------------------
/*
Fix j as the middle element.
For each j:
- Count how many elements greater than a[j] exist on its left
- Count how many elements smaller than a[j] exist on its right

Each combination forms a valid triplet.
Fenwick Tree (Binary Indexed Tree) is used to compute counts efficiently.
Coordinate compression is applied because values are large.
*/

// 3. Complexity ---------------------------------------------------------
/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

// 4. Problem Submission Link --------------------------------------------
/*
https://codeforces.com/contest/61/submission/356384283
*/

import java.io.*;
import java.util.*;

public class Solution2 {

    static class Fenwick {
        int n;
        long[] bit;

        Fenwick(int n) {
            this.n = n;
            bit = new long[n + 1];
        }

        void update(int i, long v) {
            while (i <= n) {
                bit[i] += v;
                i += i & -i;
            }
        }

        long query(int i) {
            long s = 0;
            while (i > 0) {
                s += bit[i];
                i -= i & -i;
            }
            return s;
        }

        long range(int l, int r) {
            return query(r) - query(l - 1);
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);

        int n = fs.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = fs.nextInt();

        int[] b = a.clone();
        Arrays.sort(b);
        Map<Integer, Integer> map = new HashMap<>(n);
        int id = 1;
        for (int x : b) if (!map.containsKey(x)) map.put(x, id++);

        int[] c = new int[n];
        for (int i = 0; i < n; i++) c[i] = map.get(a[i]);

        long[] L = new long[n];
        long[] R = new long[n];

        Fenwick fw = new Fenwick(n);
        for (int i = 0; i < n; i++) {
            L[i] = fw.range(c[i] + 1, n);
            fw.update(c[i], 1);
        }

        fw = new Fenwick(n);
        for (int i = n - 1; i >= 0; i--) {
            R[i] = fw.query(c[i] - 1);
            fw.update(c[i], 1);
        }

        long ans = 0;
        for (int i = 0; i < n; i++) ans += L[i] * R[i];

        System.out.println(ans);
    }

    static class FastScanner {
        private final byte[] buf = new byte[1 << 16];
        private int idx = 0, size = 0;
        private final InputStream in;

        FastScanner(InputStream in) {
            this.in = in;
        }

        int read() throws IOException {
            if (idx >= size) {
                size = in.read(buf);
                idx = 0;
                if (size <= 0) return -1;
            }
            return buf[idx++];
        }

        int nextInt() throws IOException {
            int c, s = 1, x = 0;
            do c = read(); while (c <= ' ');
            if (c == '-') {
                s = -1;
                c = read();
            }
            while (c > ' ') {
                x = x * 10 + (c - '0');
                c = read();
            }
            return x * s;
        }
    }
}

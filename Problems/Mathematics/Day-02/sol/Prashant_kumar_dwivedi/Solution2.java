/*
Problem Statement:
Masha wants to hire exactly k bloggers out of n bloggers.
Each blogger i has ai followers.

Her goal is to maximize the total number of followers.
Among all selections that achieve this maximum total,
she wants to count how many different ways there are
to choose such k bloggers.

Two ways are different if the chosen sets of bloggers differ.

Since the answer can be large, output it modulo 1e9 + 7.

---------------------------------------
Key Observation:
To maximize the total followers, Masha must always choose
the k bloggers with the highest follower counts.

However, if there are duplicate values among the k-th largest
followers, multiple valid selections may exist.

---------------------------------------
Important Insight:
1. Sort the array of followers.
2. Let x be the k-th largest value.
3. All values strictly greater than x must be selected.
4. For values equal to x:
   - Let `need` = how many times x appears in the top k.
   - Let `total` = how many times x appears in the entire array.

Then the number of valid selections is:
C(total, need)

---------------------------------------
Why Combination Works:
- Bloggers with followers > x are forced.
- Bloggers with followers < x cannot be chosen.
- We are free to choose `need` bloggers with followers = x
  from `total` such bloggers.

---------------------------------------
Approach:
1. Precompute factorials and inverse factorials up to n.
2. For each test case:
   - Sort the array.
   - Identify x = k-th largest follower count.
   - Count `need` and `total`.
   - Output C(total, need) modulo 1e9 + 7.

---------------------------------------
Time Complexity:
Sorting per test case: O(n log n)
Combination computation: O(1)

Overall: O(n log n)

---------------------------------------
Space Complexity:
O(n)

---------------------------------------
Constraints:
1 ≤ t ≤ 1000
1 ≤ k ≤ n ≤ 1000
Sum of n over all test cases ≤ 1000
---------------------------------------
*/
/*---submission link
https://codeforces.com/contest/1475/submission/355271674
 */

import java.io.*;
import java.util.*;

public class Solution2 {

    static final long MOD = 1_000_000_007L;
    static long[] fact = new long[2005];
    static long[] invFact = new long[2005];

    /* Fast modular exponentiation */
    static long modPow(long a, long e) {
        long res = 1;
        while (e > 0) {
            if ((e & 1) == 1) res = res * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return res;
    }

    /* Compute nCr modulo MOD */
    static long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);

        /* Precompute factorials and inverse factorials */
        fact[0] = 1;
        for (int i = 1; i < fact.length; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[fact.length - 1] = modPow(fact[fact.length - 1], MOD - 2);
        for (int i = fact.length - 2; i >= 0; i--)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;

        int t = fs.nextInt();
        while (t-- > 0) {
            int n = fs.nextInt();
            int k = fs.nextInt();

            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = fs.nextInt();

            /* Sort followers */
            Arrays.sort(a);

            /* k-th largest element */
            int x = a[n - k];

            int need = 0;   // count of x in top k
            int total = 0;  // total count of x in array

            for (int i = n - k; i < n; i++)
                if (a[i] == x) need++;

            for (int v : a)
                if (v == x) total++;

            System.out.println(nCr(total, need));
        }
    }

    /* Fast input reader */
    static class FastScanner {
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;
        private final InputStream in;

        FastScanner(InputStream in) {
            this.in = in;
        }

        private int readByte() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c, sign = 1, val = 0;
            do {
                c = readByte();
            } while (c <= ' ');

            if (c == '-') {
                sign = -1;
                c = readByte();
            }
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = readByte();
            }
            return val * sign;
        }
    }
}

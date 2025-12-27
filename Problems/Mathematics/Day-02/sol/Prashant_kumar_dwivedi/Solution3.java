/*
Problem Statement:
You are given an integer N.

Define the following summation:

∑_{i=1..N} ∑_{j=1..N} ∑_{k=1..i} ∑_{l=1..j}
gcd(k, i) × gcd(l, j) × gcd(i, j)

Your task is to compute the value of this summation modulo 1000000007.

---------------------------------------
Observations:
1. The inner sums:
   ∑_{k=1..i} gcd(k, i)
   depend only on i, not on j.

2. Let:
   S(n) = ∑_{k=1..n} gcd(k, n)

   It is a known number-theoretic identity that:
   S(n) = ∑_{d | n} φ(d) × (n / d)

3. Using the identity:
   gcd(i, j) = ∑_{d | i and d | j} φ(d)

   we can rearrange the original 4D summation
   into a divisor-based formulation.

---------------------------------------
Final Reduced Formula:
The entire expression becomes:

∑_{d=1..N} φ(d) × ( ∑_{m ≤ N, d | m} S(m) )²

---------------------------------------
Approach:
1. Precompute Euler's Totient Function φ(i) for all i ≤ N using sieve.
2. Compute S(n) for all n using divisor enumeration.
3. For each d, compute F(d) = sum of S(m) where d divides m.
4. Accumulate the answer using:
   ans += φ(d) × F(d)²

---------------------------------------
Time Complexity:
- Totient sieve:        O(N log log N)
- Computing S(n):       O(N log N)
- Computing F(d):       O(N log N)

Overall: O(N log N)

---------------------------------------
Space Complexity:
O(N)

---------------------------------------
Constraints:
1 ≤ N ≤ 10⁶

---------------------------------------
*/
/*------------------Problem submission link -------------------------
https://www.codechef.com/viewsolution/1221660384
 */

import java.io.*;

public class Solution3 {

    static final long MOD = 1_000_000_007L;

    public static void main(String[] args) throws Exception {

        FastScanner fs = new FastScanner(System.in);
        int N = fs.nextInt();

        /* Step 1: Compute Euler Totient φ for all numbers */
        int[] phi = new int[N + 1];
        for (int i = 1; i <= N; i++) phi[i] = i;

        for (int i = 2; i <= N; i++) {
            if (phi[i] == i) { // i is prime
                for (int j = i; j <= N; j += i) {
                    phi[j] -= phi[j] / i;
                }
            }
        }

        /* Step 2: Compute S(n) = sum_{k=1..n} gcd(k, n) */
        long[] S = new long[N + 1];
        for (int d = 1; d <= N; d++) {
            for (int m = d; m <= N; m += d) {
                S[m] += (long) phi[d] * (m / d);
            }
        }

        /* Step 3: Compute F(d) = sum of S(m) where d divides m */
        long[] F = new long[N + 1];
        for (int d = 1; d <= N; d++) {
            long sum = 0;
            for (int m = d; m <= N; m += d) {
                sum += S[m];
                // prevent overflow in extreme cases
                if (sum >= Long.MAX_VALUE / 4) sum %= MOD;
            }
            F[d] = sum % MOD;
        }

        /* Step 4: Final accumulation */
        long ans = 0;
        for (int d = 1; d <= N; d++) {
            long x = F[d];
            long sq = (x * x) % MOD;
            ans = (ans + phi[d] * sq) % MOD;
        }

        System.out.println(ans);
    }

    /* Fast input reader for large constraints */
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

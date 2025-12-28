/*
Problem Statement:
You are given an integer n and an integer k (k ≥ 2), along with an array of n
positive integers.

Your task is to count the number of unordered index pairs (i, j) such that:
1 ≤ i < j ≤ n
The product ai × aj is a perfect k-th power.

---------------------------------------
Approach:
A number is a perfect k-th power if, in its prime factorization,
the exponent of every prime is divisible by k.

For each number:
1. Factorize it using smallest prime factor (SPF).
2. Reduce each prime’s exponent modulo k.
3. Store this reduced form as a "signature".

For a pair (ai, aj) to form a perfect k-th power:
- Their signatures must complement each other such that
  the sum of exponents (mod k) becomes 0 for every prime.

---------------------------------------
Time Complexity:
O(n log a)

Space Complexity:
O(n)
---------------------------------------
*/
/*---------Problem link--------------------
https://codeforces.com/problemset/status?my=on
 */

import java.util.*;

public class Solution2 {

    static int MAX = 100000;
    static int[] spf = new int[MAX + 1];

    // Precompute smallest prime factor for every number
    static void computeSPF() {
        for (int i = 1; i <= MAX; i++)
            spf[i] = i;

        for (int i = 2; i * i <= MAX; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAX; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }

    // Build reduced prime-exponent signature
    static Map<Integer, Integer> buildSignature(int x, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        while (x > 1) {
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            cnt %= k;
            if (cnt > 0)
                map.put(p, cnt);
        }
        return map;
    }

    // Build complement signature
    static Map<Integer, Integer> buildComplement(Map<Integer, Integer> sig, int k) {
        Map<Integer, Integer> comp = new HashMap<>();
        for (Map.Entry<Integer, Integer> e : sig.entrySet()) {
            comp.put(e.getKey(), (k - e.getValue()) % k);
        }
        return comp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        computeSPF();

        int n = sc.nextInt();
        int k = sc.nextInt();

        Map<Map<Integer, Integer>, Long> freq = new HashMap<>();
        long ans = 0;

        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();

            Map<Integer, Integer> sig = buildSignature(x, k);
            Map<Integer, Integer> comp = buildComplement(sig, k);

            ans += freq.getOrDefault(comp, 0L);
            freq.put(sig, freq.getOrDefault(sig, 0L) + 1);
        }

        System.out.println(ans);
        sc.close();
    }
}

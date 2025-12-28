// Link to Submission: https://codeforces.com/contest/1225/submission/355410192

/*
Problem Statement:
You are given n positive integers a1, …, an, and an integer k ≥ 2.
Count the number of pairs i, j such that 1 ≤ i < j ≤ n, and there exists an integer x such that ai ⋅ aj = x^k.
*/

/*
Brief Explanation:
To avoid TLE we avoid comparing each combination of elements, rather we calculate the reduced form of each element in the array.
The reduced form of an element can be calculated as -> A = q^x * p^y... ~ q^(x % k) * p^(y %k)...
We then get the complement i.e. Ac ~ q^((k - (x % k)) % k) * p^((k - (y % k)) % k)
While iterating through the array, we maintain a frequency map of reduced forms.
For each element, we count how many previously seen reduced forms equal its complement and add that to the pair count.
*/

import java.util.*;

public class Solution2 {
    static long[] reducedAndComplement(long x, int k) {
        long rf = 1;
        long comp = 1;

        for (long p = 2; p * p <= x; p++) {
            int count = 0;

            while (x % p == 0) {
                x /= p;
                count++;
            }

            count %= k;

            for (int i = 0; i < count; i++)
                rf *= p;

            int req = (k - count) % k;
            for (int i = 0; i < req; i++)
                comp *= p;
        }

        if (x > 1) {
            rf *= x;
            int req = (k - 1) % k;
            for (int i = 0; i < req; i++)
                comp *= x;
        }

        return new long[]{rf, comp};
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashMap<Long, Integer> freq = new HashMap<>();
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        long fc = 0;

        for (int i = 0; i < n; i++) {
            long a = sc.nextLong();
            long[] rc = reducedAndComplement(a, k);
            long r = rc[0];
            long c = rc[1];

            fc += freq.getOrDefault(c, 0);

            freq.put(r, freq.getOrDefault(r, 0) + 1);
        }

        System.out.println(fc);

        sc.close();
    }
}

// Time Complexity: O(n * sqr.root(A))
// Space Complexity: O(n)
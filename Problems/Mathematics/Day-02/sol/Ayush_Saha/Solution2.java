// SUBMISSION LINK: https://codeforces.com/contest/1475/submission/355447020

/*
PROBLEM STATEMENT:
Masha works in an advertising agency. In order to promote the new brand, she wants to conclude contracts with some bloggers.
In total, Masha has connections of n different bloggers. Blogger numbered i has ai followers.
Since Masha has a limited budget, she can only sign a contract with k different bloggers.
Of course, Masha wants her ad to be seen by as many people as possible.
Therefore, she must hire bloggers with the maximum total number of followers.
Help her, find the number of ways to select k
bloggers so that the total number of their followers is maximum possible.
Two ways are considered different if there is at least one blogger in the first way, which is not in the second way.
Masha believes that all bloggers have different followers (that is, there is no follower who would follow two different bloggers).
*/

/*
Brief Explanation:
We sort the array into descending order. We only need the first k elements.
However there may be multiple bloggers with the least followers (in the top k), thus giving us multiple possibilities.
We need to find combinations containing different bloggers in each case.
Total number of bloggers with the least followers in the top k = count
Total number of bloggers with the least followers needed to fill k = topC.
Number of combinations = C(count, topC)
*/

import java.util.*;

public class Solution2 {
    static final int MAX = 1000;
    static final long MOD = 1000000007;

    static long[][] C = new long[MAX + 1][MAX + 1];

    static void combinations() {
        for (int i = 0; i <= MAX; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        combinations();
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            long[] arr = new long[n];
            int count = 0;
            int topC = 0;

            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextLong();
            }

            Arrays.sort(arr);

            long mark = arr[n - k];

            for (int i = n - 1; i >= 0; i--)
            {
                if (arr[i] == mark) {
                    count++;
                    if (i > n - k - 1)
                        topC++;
                }
            }

            System.out.println(C[count][topC]);
        }
        sc.close();
    }
}

// Time Complexity = O(n log n)
// precomputing combinations will have time complexity = O(MAX^2)
// Space Complexity = O(MAX^2)
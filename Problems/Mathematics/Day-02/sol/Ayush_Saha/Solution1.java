// Link to submission: https://codeforces.com/contest/1771/submission/355440128

/*
PROBLEM STATEMENT: 
Hossam woke up bored, so he decided to create an interesting array with his friend Hazem.
Now, they have an array a of n positive integers, Hossam will choose a number ai and Hazem will choose a number aj.
Count the number of interesting pairs (ai, aj) that meet all the following conditions:
-> 1 ≤ i, j ≤ n
-> i ≠ j
-> The absolute difference |ai − aj| must be equal to the maximum absolute difference over all the pairs in the array.
    More formally, |ai − aj| = max|ap − aq|, 1 ≤ p, q≤ n.
*/

/*
Brief Explanation:
We find the minimum and the maximum element in the entire array and count the number of ordered pairs of min and max in the array.
We count the frequency of miminum and maximum elements and use the formula of combinatorics to compute number of pairs.
if min != max, we have count = freqMin C 1 * freqMax C 1 * 2
if min == max, we have count = freqMax P 2
*/

import java.util.*;

public class Solution1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            long min = 100000;
            long max = 0;
            long freqMin = 0;
            long freqMax = 0;
            int n = sc.nextInt();
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextLong();
                if (arr[i] < min)
                    min = arr[i];
                if (arr[i] > max)
                    max = arr[i];
            }
            for (int i = 0; i < n; i++) {
                if (arr[i] == min)
                    freqMin++;
                if (arr[i] == max)
                    freqMax++;
            }

            long count = 0;
            if (min == max)
                count = freqMax * (freqMax - 1);
            else
                count = freqMin * freqMax * 2;
            System.out.println(count);
        }
        sc.close();
    }
}

// Time Complexity: O(n)
// Space Complexity: O(n)

// CODEFORCES SUBMISSION LINK: https://codeforces.com/contest/1560/submission/355168755

/*
PROBLEM STATEMENT :

There are n people standing in a circle. They are numbered from 1 to n in a clockwise order. The circle is even (i.e. n is even).

Each person is looking at the person standing exactly opposite him in the circle.

You are given three distinct integers a, b, and c. It is known that person a is looking at person b.

Determine the number of the person that person c is looking at.
If there are multiple answers, print any of them.
If there is no answer, print -1.
*/

/*
Approach:
We first calculate the size of the circle. Knowing 'a' and 'b' is enough to know the size of the circle.
Because we can know the number of people between 'a' and 'b' which would give us half the total number.
We can easily get the person sitting opposite to any number once we know the size of the circle.
*/

/*
Time Complexity: O(1)
Space Complexity: O(1)
*/

import java.util.Scanner;

public class Solution1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            int d;

            int n = 2 * Math.abs(a - b);
            if (a > n || b > n || c > n)
                d = -1;
            else {
                int res = (c + (n / 2)) % n;
                d = res != 0? res : n;
            }

            System.out.println(d);
        }
        sc.close();
    }
}
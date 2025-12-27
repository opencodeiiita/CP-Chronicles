// 1. Problem Statement -------------------------------------------------
/*
There are n people standing in a circle, where n is even.
Each person looks at the person standing exactly opposite to them.

You are given three distinct integers a, b, and c.
It is known that person a is looking at person b.

Determine the person that person c is looking at.
If such a person cannot exist, print -1.
*/

// 2. Approach -----------------------------------------------------------
/*
The pair (a, b) fixes the entire circle.
Once the circle is fixed, every person has exactly one opposite person.

If person c does not fit into this fixed circle, the answer is -1.
Otherwise, move half the circle from c to find the person they are looking at.
*/

// 3. Complexity ---------------------------------------------------------
/*
Time Complexity: O(1) per test case
Space Complexity: O(1)
*/

//4. problem submission link-----------------------------------
// https://codeforces.com/problemset/status?my=on

// Compiling Code in Java (Solution1.java) -------------------------------

import java.util.*;

public class Solution1 {

    public static int findOpposite(int a, int b, int c) {
        int n = 2 * Math.abs(a - b);
        if (a > n || b > n || c > n) {
            return -1;
        }
        int half = n / 2;
        if (c + half <= n) {
            return c + half;
        }
        return c - half;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            System.out.println(findOpposite(a, b, c));
        }
        sc.close();
    }
}

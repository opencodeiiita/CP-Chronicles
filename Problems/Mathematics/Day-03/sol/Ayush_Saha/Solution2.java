/* 
FOREWORD:
I took help from the internet in designing the recursive method `continuedFraction`. I hope that's ok.
From this post in particular: https://stackoverflow.com/questions/48094595/convert-fraction-to-continued-fraction.
That said, I am proud to say that I came up with the idea of continued fraction on my own.
*/

// Link to Submission: https://codeforces.com/contest/343/submission/355493183

/*
PROBLEM STATEMENT:
You have unlimited unit resistors. You are given the Req.
Find the minimum number of unit resistors you need to build a circuit using series and parallel configuration to achieve the Req.
*/

/*
EXPLANATION:
A fraction can either be proper or improper.
For improper fractions we can convert it to mixed form i.e for a > b, we can write
    a / b = k + (r / b), where r is a % b and k is floor(a / b).
    r / b is a proper fraction so the next steps are same for both.
Proper fractions mean the resistors are arranged in parallel.
The simplest proper fraction to work with is of the type 1 / b, which means b resistors arranged in parallel.
The first step of the converting a proper fraction to it's continued fraction form is to convert it into an improper fraction.
So a / b becomes 1 / (b / a). Now we convert b / a to it's mixed form ki + (ri / ai). We keep doing this until we get r / ai, where r = 1.
We keep tracking ki, because that gives us number of resistors arranged in series the final ai, gives the last few resistors
    that are arranged in parallel.
*/


import java.util.*;

public class Solution2 {
    static long res = 0;
    static void continuedFraction(long a, long b) {
        if (b == 0) {
            return;
        }

        long k = a / b;
        long r = a % b;

        res += k;

        if (r != 0) {
            continuedFraction(b, r);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        
        continuedFraction(a, b);

        System.out.println(res);
        sc.close();
    }
}

// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(1) <- Not Sure


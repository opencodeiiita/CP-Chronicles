/*
What this program does:

For each test case, we start with an infinite sequence of natural numbers.
An operation removes every y-th position from the current sequence.
This operation is performed x times.

The goal is to find which number ends up at position k after all removals.
If the sequence becomes shorter than k, output -1.


How the logic works:

- If y == 1, every operation deletes the entire sequence immediately,
  so the answer is always -1.

- Instead of simulating removals, we track how many numbers are needed
  before removals so that k numbers survive.

- Each operation effectively removes one number for every (y - 1) survivors,
  so we update the required position iteratively.

- If the value grows beyond a safe limit, we stop and return -1.


Complexity:

Time:  O(x) per test case  
Space: O(1)


Submission link :----------------------------------------------------------------
https://codeforces.com/contest/2169/submission/356459820

*/

import java.util.*;
import java.io.*;

public class Solution1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null) return;
        
        int t = Integer.parseInt(line.trim());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());
            long k = Long.parseLong(st.nextToken());

            if (y == 1) {
                System.out.println("-1");
                continue;
            }

            long current = k;
            long maxVal = 1000000000000L;
            boolean ok = true;

            for (int i = 0; i < x; i++) {
                current += (current - 1) / (y - 1);
                if (current > maxVal) {
                    ok = false;
                    break;
                }
            }

            if (!ok) {
                System.out.println("-1");
            } else {
                System.out.println(current);
            }
        }
    }
}
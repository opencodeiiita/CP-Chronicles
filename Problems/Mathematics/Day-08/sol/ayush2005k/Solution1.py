"""
Problem: B. Sasha and the Apartment Purchase
Link: https://codeforces.com/contest/2098/problem/B

Short Problem Statement:
There are n bars located on a street at given house numbers.
At most k bars can close.
For a house x, define f(x) as the sum of distances from x to all open bars.
Sasha can buy a house x if it is possible to close at most k bars such that
f(x) is minimal among all houses.
The task is to count how many different houses Sasha can potentially buy.

Approach:
The sum of absolute distances is minimized at the median.
After closing at most k bars, the number of remaining bars is m = n - k.
For all subsets of size m, the possible medians form a continuous range.
After sorting the bar positions:
- The minimum possible median is at index (m - 1) // 2
- The maximum possible median is at index (n - m) + (m // 2)
Any integer house number between these two values (inclusive) is valid.
The answer is the length of this interval.

Time Complexity:
O(n log n) per test case due to sorting.

Space Complexity:
O(n)

Example:
Input:
4 0
1 2 3 4

Output:
2

Submission Link:
https://codeforces.com/contest/2098/submission/356283081
"""

import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    a.sort()

    m = n - k

    left_index = (m - 1) // 2
    right_index = (n - m) + (m // 2)

    result = a[right_index] - a[left_index] + 1
    print(result)

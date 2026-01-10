# Submission Link: https://www.codechef.com/viewsolution/1223654670
# Time Complexity: O(N)
# Approach: DP from right computing farthest reachable index choosing A or B

import sys
input = sys.stdin.readline

t = int(input())
out = []

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    reachA = [0] * n
    reachB = [0] * n

    for i in range(n - 1, -1, -1):
        reachA[i] = i
        reachB[i] = i

        if i + 1 < n:
            ra = i
            rb = i

            if a[i + 1] > a[i]:
                ra = max(ra, reachA[i + 1])
            if b[i + 1] > a[i]:
                ra = max(ra, reachB[i + 1])

            if a[i + 1] > b[i]:
                rb = max(rb, reachA[i + 1])
            if b[i + 1] > b[i]:
                rb = max(rb, reachB[i + 1])

            reachA[i] = ra
            reachB[i] = rb

    ans = 0
    for i in range(n):
        ans += max(reachA[i], reachB[i]) - i + 1

    out.append(str(ans))

print("\n".join(out))

# Submission Link: https://codeforces.com/contest/2169/submission/356515259
# Approach: binary search on answer m, simulate count of remaining <= m by subtracting removed across x steps
# Time Complexity: O(x * log(Max(N)))

import sys
input=sys.stdin.readline

def remaining_count(m, y, x):
    ost = m - 1
    for _ in range(x):
        ost -= ost // y
        if ost < 0:
            break
    return ost + 1

t=int(input().strip())
for _ in range(t):
    x,y,k=map(int,input().split())
    lo,hi=1,10**12+1
    ans=-1
    while lo<=hi:
        mid=(lo+hi)//2
        if remaining_count(mid,y,x)>=k:
            ans=mid
            hi=mid-1
        else:
            lo=mid+1
    if ans==10**12+1:
        print(-1)
    else:
        print(ans)

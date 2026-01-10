# Submission: https://codeforces.com/contest/813/submission/356818920
# Approach: find the farthest node bob can delay to by dfs the distances and simulate optimal moves
# Runtime: O(n)
import sys
sys.setrecursionlimit(500000)
input=sys.stdin.readline

n,x=map(int,input().split())
x-=1
g=[[] for _ in range(n)]
for _ in range(n-1):
    u,v=map(int,input().split())
    u-=1; v-=1
    g[u].append(v)
    g[v].append(u)

distA=[-1]*n
distB=[-1]*n

def dfs(start,dist):
    stack=[start]
    dist[start]=0
    while stack:
        u=stack.pop()
        for v in g[u]:
            if dist[v]==-1:
                dist[v]=dist[u]+1
                stack.append(v)

dfs(0,distA)
dfs(x,distB)

ans=0
for i in range(n):
    if distB[i]>distA[i]:
        ans=max(ans,distA[i]+distB[i])
print(ans+1)

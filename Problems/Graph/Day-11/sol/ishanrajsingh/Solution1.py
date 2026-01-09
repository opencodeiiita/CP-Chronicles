# Submission: https://codeforces.com/contest/580/submission/356792507
# Approach: build tree and DFS tracking consecutive cats, count leaves reachable with ≤m cats
# Runtime: O(n)
import sys
sys.setrecursionlimit(3000000)
input=sys.stdin.readline

n,m=map(int,input().split())
cats=list(map(int,input().split()))
g=[[] for _ in range(n)]
for _ in range(n-1):
    u,v=map(int,input().split())
    u-=1; v-=1
    g[u].append(v)
    g[v].append(u)

res=0
visited=[False]*n
def dfs(u,consec):
    global res
    visited[u]=True
    if cats[u]==1: consec+=1
    else: consec=0
    if consec>m: return
    leaf=True
    for v in g[u]:
        if not visited[v]:
            leaf=False
            dfs(v,consec)
    if leaf: res+=1

dfs(0,0)
print(res)

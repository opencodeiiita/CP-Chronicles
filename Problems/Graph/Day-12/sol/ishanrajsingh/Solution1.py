# Submission Link: https://codeforces.com/contest/769/submission/357188627
# Approach: use BFS and precompute dist from start and greedy build lexicographically smallest valid cycle by choosing moves in order L,R,U,D
# Runtime: O(n*m + k)
import sys
from collections import deque
input=sys.stdin.readline
n,m,k=map(int,input().split())
maze=[list(input().strip()) for _ in range(n)]
dirs=[('D',1,0),('L',0,-1),('R',0,1),('U',-1,0)]
sx=sy=0
for i in range(n):
    for j in range(m):
        if maze[i][j]=='X':
            sx,sy=i,j
dist=[[10**18]*m for _ in range(n)]
dist[sx][sy]=0
dq=deque([(sx,sy)])
while dq:
    x,y=dq.popleft()
    for _,dx,dy in dirs:
        nx,ny=x+dx,y+dy
        if 0<=nx<n and 0<=ny<m and maze[nx][ny]!='*' and dist[nx][ny]>dist[x][y]+1:
            dist[nx][ny]=dist[x][y]+1
            dq.append((nx,ny))
if k%2==1:
    print("IMPOSSIBLE")
    sys.exit()
res=[]
cx,cy=sx,sy
for _ in range(k):
    moved=False
    for ch,dx,dy in [('D',1,0),('L',0,-1),('R',0,1),('U',-1,0)]:
        nx,ny=cx+dx,cy+dy
        if 0<=nx<n and 0<=ny<m and maze[nx][ny]!='*':
            rem=k-len(res)-1
            if dist[nx][ny]<=rem:
                res.append(ch)
                cx,cy=nx,ny
                moved=True
                break
    if not moved:
        print("IMPOSSIBLE")
        sys.exit()
print("".join(res))

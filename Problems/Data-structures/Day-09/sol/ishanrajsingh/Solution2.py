#Submission Link - https://codeforces.com/contest/61/submission/356379545
#Approach - Count triplets i < j < k where a[i] > a[j] > a[k] using two Fenwick Trees implicitly
#Time Complexity - O(n log n)
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.read
data = input().split()

n = int(data[0])
a = list(map(int, data[1:]))
pos = [0] * (n + 1)

for i in range(n):
    pos[a[i]] = i + 1

N = n + 10
ft = [0] * (N + 1)

def update(idx, val):
    while idx <= N:
        ft[idx] += val
        idx += idx & -idx

def query(idx):
    res = 0
    while idx > 0:
        res += ft[idx]
        idx -= idx & -idx
    return res

ans = 0
for i in range(n - 1, -1, -1):
    r = pos[a[i]]
    smaller_right = query(r - 1)
    ans += smaller_right * query(a[i] - 1)
    update(r, 1)

print(ans)

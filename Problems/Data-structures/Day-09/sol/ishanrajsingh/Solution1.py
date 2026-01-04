#Salary Queries - A company has n employees with certain salaries. We have to keep track of the salaries and process queries.
#Approach - Use coordinate compression + Binary Indexed Tree
#Time Complexity - O((n+q)log(n+q))

import sys
input = sys.stdin.readline

n, q = map(int, input().split())
p = list(map(int, input().split()))

queries = []
vals = set(p)

for _ in range(q):
    s = input().split()
    if s[0] == '!':
        k, x = int(s[1]), int(s[2])
        queries.append(('!', k - 1, x))
        vals.add(x)
    else:
        a, b = int(s[1]), int(s[2])
        queries.append(('?', a, b))
        vals.add(a)
        vals.add(b)

vals = sorted(vals)
idx = {v: i + 1 for i, v in enumerate(vals)}

m = len(vals)
bit = [0] * (m + 1)

def add(i, v):
    while i <= m:
        bit[i] += v
        i += i & -i

def sum_(i):
    s = 0
    while i > 0:
        s += bit[i]
        i -= i & -i
    return s

for x in p:
    add(idx[x], 1)

for qu in queries:
    if qu[0] == '!':
        i, x = qu[1], qu[2]
        add(idx[p[i]], -1)
        p[i] = x
        add(idx[x], 1)
    else:
        a, b = qu[1], qu[2]
        print(sum_(idx[b]) - sum_(idx[a] - 1))

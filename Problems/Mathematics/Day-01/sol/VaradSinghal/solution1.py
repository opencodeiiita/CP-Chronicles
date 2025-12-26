def solve():
    t = int(input())
    for _ in range(t):
        a, b, c = map(int, input().split())
        
        d = abs(a - b)
        n = 2 * d
        
        if n == 0 or max(a, b, c) > n:
            print(-1)
            continue
        
        half = n // 2
 
        if c + half <= n:
            print(c + half)
        else:
            print(c - half)

# Run
solve()

ti=int(input())

for _ in range(ti):
    k,l,p=map(int,input().split())
    
    d=abs(k-l)
    f=2*d
    
    if k>f or l>f or p>f:
        print(-1)
    else:
        if p+d<=f:
            print(p+d)
        else:
            print(p-d)
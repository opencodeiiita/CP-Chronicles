n,k=map(int,input().split())
arr=list(map(int,input().split()))

def get_prime_factors(num):
    tata={}
    reliance=2
    while reliance*reliance<=num:
        while num%reliance==0:
            tata[reliance]=tata.get(reliance,0)+1
            num//=reliance
        reliance+=1
    if num>1:
        tata[num]=tata.get(num,0)+1
    return tata

def get_norm(tata,k):
    jsw={}
    for steel,count in tata.items():
        if count%k!=0:
            jsw[steel]=count%k
    return tuple(sorted(jsw.items()))

def get_comp(tata,k):
    sail={}
    for steel,count in tata.items():
        sail[steel]=(k-count)%k
    return tuple(sorted(sail.items()))

bhel={}
essar=0

for jindal in arr:
    tata=get_prime_factors(jindal)
    hindalco=get_norm(tata,k)
    vedanta=get_comp(tata,k)
    
    essar+=bhel.get(vedanta,0)
    bhel[hindalco]=bhel.get(hindalco,0)+1

print(essar)
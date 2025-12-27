#pragma GCC optimize("03")
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
// #define ld long double
#define pll pair<ll,ll>
 
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int MOD = 998244353;
int addm(int x, int y)
{
    return ((x + y) % MOD + MOD) % MOD;
}
int mulm(int x, int y)
{
    return x * 1ll * y % MOD;   
}
int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y&1) z = mulm(z, x);
        x = mulm(x, x);
        y /= 2;
    }
    return z;
}
int inv(int x)
{
    return binpow(x, MOD - 2);    
}
int divide(int x, int y)
{
    return mulm(x, inv(y));
}
int ncrm(int n, int r)
{
    int num = 1;
    int a,b,c;
    if(r < n-r)
    {
        for(int i=1; i<=r; i++)
        {
            num = mulm(num, i);
        }
        a = num;
        for(int i=r+1; i<=n-r; i++)
        {
            num = mulm(num, i);
        }
        b = num;
        for(int i=n-r+1; i<=n; i++)
        {
            num = mulm(num, i);
        }
        c = num;
    }
    else if(r > n-r)
    {
        for(int i=1; i<=n-r; i++)
        {
            num = mulm(num, i);
        }
        a = num;
        for(int i=n-r+1; i<=r; i++)
        {
            num = mulm(num, i);
        }
        b = num;
        for(int i=r+1; i<=n; i++)
        {
            num = mulm(num, i);
        }
        c = num;
    }
    else
    {
        for(int i=1; i<=r; i++)
        {
            num = mulm(num, i);
        }
        a = b = num;
        for(int i=r+1; i<=n; i++)
        {
            num = mulm(num, i);
        }
        c = num;
    }
    int den = mulm(a,b);
    return divide(c,den);
}
void yes()
{
    cout << "YES" << endl;
}
void no()
{
    cout << "NO" << endl;
}
 
int32_t main()
{
    fastio
    int t;
    cin >> t;
    while (t--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(a < b) swap(a,b);
        int d = a - b;
        int p = d + c;
        int q = d + 1;
        int r = d + q - 1;
        if(a > r || c > r) {
            cout << -1 << endl;
        }
        else {
            if(p > r) p %= r;
            if(p == 0) p = r;
            cout << p << endl;
        }
    }
}

/*
DAY 6
Q2  Rudolf and Snowflakes (hard version)
.*/
/*

n is valid if it equals 1+k+k^2+k^3+......+k^d  and d>=2

*/

#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const i64 Mod = 1e9 + 7;
const i64 Inf = 1e8;
const int Len = 2e5 + 5;
map<i64,int> mp;
 
void solve(void)
{
    i64 n;
    cin >> n;
    if(mp[n])
    {
        cout << "YES\n";
        return;
    }
    n--;
    i64 l = 2,r = 1e9;
    while(l <= r)
    {
        i64 mid = (l + r) >> 1;
        if(mid * (mid + 1ll) == n)
        {
            cout << "YES\n";
            return;
        }
        else if(mid * (mid + 1ll) > n)
        {
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << "NO\n";
}
 
int main(void)
{
    i64 n = 1e6,nn = 1e18;
    for(i64 i = 2;i <= n;i++)
    {
        i64 tmp = i * i,now = 1 + i + i * i;
        while(now <= nn)
        {
            mp[now] = 1;
            i64 tt = nn / tmp;
            if(i > tt)break;
            tmp *= i;
            now += tmp;
        }
    }
    int t;
    cin >> t;
    while(t--)solve();
    cout.flush();
    return 0;
}





// SC = O(M)
/*
My submission : https://codeforces.com/contest/1846/submission/356068357
*/

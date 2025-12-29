Submission LInk: https://codeforces.com/contest/1475/submission/355652328

/*
E. Advertising Agency: We are given n bloggers and each blogger has at max n followers. We have to find the number of ways to select k 
bloggers so that the total number of their followers is maximum possible.

So first I made an array to count the number of followers of each blogger in an array and then iterated through the array from last checking if the number of bloggers 
having that many followers are equal or greater or less than k. If they are less than k then all need to be counted in order to get the maximum so I subtracted 
those blogger's count from k. If the number of bloggers with index number of followers is equal to or greater than k then we have to select any k of them so we 
apply C(no.of blogger with given no. of follower, k) and then break through the loop as our work is done. 
Now we need to handle the time complexity. For nCr we need to again and again find factorial so in order to remove that problem I made an array of factorial from 0 
to 1000. Since array size is small therefore it take O(1) T.C. and we can get factorial of any number in O(1).Also while calculating factorial using dp I made sure 
to take mod in each multiplication step. Now to find nCr we use the formula (n! / (r! * (n-r)!)). However, since we are working with modulo arithmetic, division is
not straightforward. We multiply by the modular inverse instead. By Fermat's Little Theorem, the modular inverse of a number a modulo m (where m is prime) is 
a^{m-2}. The function `binexp` calculates this power efficiently in O(log n) time. 
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
 
const long long mod=1e9+7;
 
vector<long long> fact(1001);
 
long long binexp(long long a, long long b) {
    long long ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans%mod;
}
 
long long C(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * binexp(fact[r], mod - 2) % mod * binexp(fact[n - r], mod - 2) % mod;
}
 
int main() {
    fastio;
    fact[0]=1;
    for(long long i=1; i<1001; i++) fact[i]=(fact[i-1]*i)%mod;
    long long t;
    cin>>t;
    while(t--) {
        long long n,k;
        cin>>n>>k;
        long long cnt[n+1]={0};
        for(long long i=0; i<n; i++) {
            long long a;
            cin>>a;
            cnt[a]++;
        }
        for(long long i=n; i>=0; i--) {
            if(cnt[i]>=k) {
                cout<<C(cnt[i], k)%mod<<endl;
                break;
            }
            else k-=cnt[i];
        }
    }   
}

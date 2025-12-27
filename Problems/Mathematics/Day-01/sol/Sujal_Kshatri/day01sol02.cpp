/*
submission link - https://codeforces.com/contest/1225/submission/355299661
n = number of elements (≤ 100000)
A = maximum value of ai (≤ 100000)

Time Complexity:
- Sieve creation: O(A log log A)
- Factorization of all elements: O(n log A)
Overall: O(n log A)

Space Complexity:
- SPF array + maps: O(A + n)

Approach:
We want to count pairs of numbers whose product is a perfect k-th power.

For each number:
1. Factorize it using the Smallest Prime Factor (SPF) sieve.
2. Keep prime exponents modulo k to form a signature.
3. Compute the required signature needed to complete k.
4. Count how many times this required signature appeared before.
5. Add it to the answer and store the current signature.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int size,power;
    cin>>size>>power;

    vector<int>arr(size);
    for(int i=0;i<size;i++)cin>>arr[i];

    const int limit=100000;
    vector<int>spf(limit+1);
    for(int i=1;i<=limit;i++)spf[i]=i;
    for(int i=2;i*i<=limit;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=limit;j+=i){
                if(spf[j]==j)spf[j]=i;
            }
        }
    }

    map<vector<pair<int,int>>,long long>store;
    long long result=0;

    for(int val:arr){
        map<int,int>count;
        while(val>1){
            int prime=spf[val];
            int exp=0;
            while(val%prime==0){
                val/=prime;
                exp++;
            }
            count[prime]+=exp;
        }

        vector<pair<int,int>>sign,need;
        for(auto &it:count){
            int prime=it.first;
            int rem=it.second%power;
            if(rem!=0){
                sign.push_back({prime,rem});
                need.push_back({prime,(power-rem)%power});
            }
        }

        sort(sign.begin(),sign.end());
        sort(need.begin(),need.end());

        result+=store[need];
        store[sign]++;
    }

    cout<<result<<"\n";
    return 0;
}

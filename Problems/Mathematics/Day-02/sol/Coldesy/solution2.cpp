#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/1475/submission/355286426


//time complexity:O(1001*1001*t) other for loop will be negligible
//space complexity: O(1001*1001) due to combination 2d array


//New learning: direct multiplication to calculate factorial will lead to overflow even in long long
// So we make a pre existing factorial 2d array which calculcates with Modulo applied so no overflow



// long long ncr(long long n, long long r) {
//     if (r < 0 || r > n) return 0; 
//     if (r == 0 || r == n) return 1;   // WE CANNOT CALCULATE FACTORIAL THIS WAY DUE TO OVERFLOW IN LONG LONG
    

//     if (r > n / 2) {
//         r = n-r;
//     }
    
//     long long ans = 1;
//     for (int i = 1; i <= r; ++i) {
//         ans = ans * (n - i + 1);
//         ans = ans / i;
//     }
//     return ans;
// }


int main() {
     long long MOD=1000000007;
    long long C[1001][1001];
    for (int i = 0; i <= 1000; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n,k;
       
        cin >> n>>k;
        vector <int> a;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        long long countall=0;//we know that,any element greater than a[n-k] is forced to                 // be in array so we can calculate the needed and total
                            // a[n-k] element and find its combination
        long long countneed=0;
        for(int i=0;i<n;i++){
            if(a[i]==a[n-k]){
                countall++;
            }
        }
        for(int i=0;i<k;i++){
            if(a[n-i-1]==a[n-k]){
                countneed++;
            }
        }
      
        cout<<C[countall][countneed]%MOD<<endl;
        }
    }


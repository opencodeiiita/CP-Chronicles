// submission link - https://codeforces.com/problemset/submission/1771/355587277

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
1. The maximum absolute difference between any two elements in the array
   is always (maximum element - minimum element).
2. A pair (ai, aj) is interesting only if one of them is the minimum value
   and the other is the maximum value.
3. Count how many times the minimum value appears (cntMin)
   and how many times the maximum value appears (cntMax).
4. Since (ai, aj) and (aj, ai) are considered different pairs,
   the total number of interesting pairs is:
      2 * cntMin * cntMax
5. Special case:
   - If all elements are equal (min == max), then every ordered pair
     (i, j) with i ≠ j is valid.
   - The answer becomes n * (n - 1).
*/

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<long long> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        long long mn = *min_element(a.begin(), a.end());
        long long mx = *max_element(a.begin(), a.end());

        if(mn == mx){
            cout << 1LL * n * (n - 1) << "\n";
            continue;
        }

        long long cntMin = 0, cntMax = 0;
        for(long long x : a){
            if(x == mn) cntMin++;
            if(x == mx) cntMax++;
        }

        cout << 2LL * cntMin * cntMax << "\n";
    }
    return 0;
}

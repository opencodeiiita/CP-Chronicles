/*https://codeforces.com/contest/1771/submission/355306957
PROBLEM STATEMENT:
Hossam woke up bored, so he decided to create an interesting array with his friend Hazem.

They are given an array 'a' of 'n' positive integers.
Hossam chooses an element a[i] and Hazem chooses an element a[j].

An ordered pair (a[i], a[j]) is considered interesting if it satisfies:
1) 1 ≤ i, j ≤ n
2) i ≠ j
3) The absolute difference |a[i] − a[j]| is equal to the maximum absolute
   difference among all possible pairs in the array, i.e.,
   |a[i] − a[j]| = max₁≤p,q≤n |a[p] − a[q]|

Input:
- The first line contains an integer t (1 ≤ t ≤ 100), representing the number of test cases.
- For each test case:
  - The first line contains an integer n (2 ≤ n ≤ 10⁵).
  - The second line contains n integers a₁, a₂, …, aₙ (1 ≤ aᵢ ≤ 10⁵).

Constraints:
- The total sum of n across all test cases does not exceed 10⁵.

Output:
- For each test case, output the number of interesting pairs (a[i], a[j]).
*/

//T.C.:O(t.nlogn)
//S.C.:O(n)

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    long long t, n, i, j, f, e, diff;
	cin >> t;  

    while(t--){
        cin >> n;
        vector <long long> v(n);
        
        for(i=0; i<n; i++)  cin >> v[i];
        
        f=0, e=0;
        
        sort(v.begin(),v.end()); //sorting the array from ascending to descending
        diff = v[n-1] - v[0];  //maximum absolute difference
        
        if(diff == 0)   cout << n*(n-1) << endl; //if same element is present throughout the array  
        
        else    {
            for(i=0; i<n; i++){
                if(v[i] == v[0])    f++; //counting no. of smallest duplicate elements
                if(v[i] == v[n-1])    e++; //counting no. of largest duplicate elements
            }
            
            cout << 2*f*e << endl; //2 times the no. of pairs
        }
    }
}

/*## Problem Description

Hossam woke up bored, so he decided to create an interesting array with his friend Hazem.

You are given an array of `n` positive integers  
`a1, a2, ..., an`.

Hossam will choose a number `ai` and Hazem will choose a number `aj`.

Your task is to count the number of index pairs `(i, j)` such that:

- `1 ≤ i, j ≤ n`
- `i ≠ j`
- The absolute difference `|ai − aj|` is equal to the **maximum absolute difference** over all pairs in the array

---

## Input Format

- The first line contains a single integer `t` — the number of test cases.
- For each test case:
  - The first line contains an integer `n`
  - The second line contains `n` integers `a1, a2, ..., an`

---

## Output Format

- For each test case, print a single integer — the number of valid pairs `(i, j)`.

---

## Constraints

- `1 ≤ t ≤ 100`
- `2 ≤ n ≤ 100000`
- `1 ≤ ai ≤ 100000`
- The sum of `n` over all test cases does not exceed `100000`

---*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        if (a[0] == a[n - 1]) {
            cout << 1LL*n*(n-1)<< "\n";
            continue;
        }
        long long maxdiff=a[n-1]-a[0];
        long long min=0;
        long long max=0;
        for(int i=0;i<n;i++){
            if(a[i]==a[0]){
                min++;
            }
            if(a[i]==a[n-1]){
                max++;
            }
           
        }
        cout<<2LL*max*min<<endl;
    }
}
//Time Complexity=O(t*nlogn+t*n)
//space complexity=O(n)
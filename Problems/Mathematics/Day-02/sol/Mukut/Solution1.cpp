/*
Problem: counting pairs where absolute difference equals max possible difference in array

My approach:
basically max diff is always gonna be max_element - min_element
so we just need pairs where one is max and other is min
first find both values then count how many times each appears
if everything is same number then answer is just n*(n-1) (all pairs work)
otherwise its 2*count_max*count_min (since both (i,j) and (j,i) count as different)

TimeComplexity: O(n) 
SpaceC: O(n)

CodeForces submission: https://codeforces.com/contest/1771/submission/355388765
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int maxi = arr[0], mini = arr[0];
        for(int i=1; i<n; i++){
            if(arr[i] > maxi) maxi = arr[i];
            if(arr[i] < mini) mini = arr[i];
        }
        if(maxi == mini){
            long long result = (long long)n * (n-1);
            cout << result << endl;
            continue;
        }
        long long max_count = 0, min_count = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == maxi) max_count++;
            if(arr[i] == mini) min_count++;
        }
        long long answer = 2 * max_count * min_count;
        cout << answer << endl;
    }
    
    return 0;
}

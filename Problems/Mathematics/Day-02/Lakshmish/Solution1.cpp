//https://codeforces.com/problemset/submission/1771/355264331
//time complexity:O(t*n*nlogn)because of for loop and sort function
//space complexity:O(1) not counting input
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);//input
        }
        sort(a.begin(), a.end());//sorting
        long long last = 0;
        long long first = 0; // maximum difference is from first and last element 
        if(a[0]==a[n-1]){
            
            cout<<(n*(n-1))<<endl;//if all elements are same,max diff is 0 so we output number of ordered pairs
        }
        else {
            for (int i = 0; i < n; i++) {
                if (a[i] == a[n - 1]) {//number of last(high) element repeated
                    last++;  
                }
                else if (a[i] == a[0]) { // number of first(low)element repeated
                    first++;
                }
            }

            cout << 2 * last * first << endl; //2 indicates ordered pair
        }
    }

}

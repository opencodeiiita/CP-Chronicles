#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int mini = *min_element(arr.begin(), arr.end());
        int maxi = *max_element(arr.begin(), arr.end());
        if (mini == maxi){
            cout << 1LL * n * (n - 1) << endl;
        }else{
            long long a = 0, b = 0;
            for (int i = 0; i < n; i++){
                if (arr[i] == mini) a++;
                if (arr[i] == maxi) b++;
            }
            cout << 2LL*a*b << endl;
        }
    }
    return 0;
}


/*

Submission Link : https://codeforces.com/contest/1771/submission/355270636

Explaination : There will be n*m combinnations possible, and Hossam and Hazem can choose any of the two numbers, so answer becomes 2*a*b.

*/
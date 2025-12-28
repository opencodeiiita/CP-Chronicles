// https://codeforces.com/contest/1771/submission/355275007

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> A;
        long long tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            A.push_back(tmp);
        }
        long long min = *(min_element(A.begin(), A.end()));
        long long max = *(max_element(A.begin(), A.end()));
        long long min_count = count(A.begin(), A.end(), min);
        long long max_count = count(A.begin(), A.end(), max);
        if (min == max)
            cout << min_count * (min_count - 1) << endl;
        else
            cout << min_count * max_count * 2 << endl;
    }
}
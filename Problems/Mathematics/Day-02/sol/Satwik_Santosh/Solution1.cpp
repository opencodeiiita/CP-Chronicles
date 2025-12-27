/*
Problem Statement:
Hossam and Hazem want to count the number of interesting pairs (i, j) such that:
1. 1 <= i, j <= n
2. i != j
3. |a[i] - a[j]| == max(|a[p] - a[q]|) for all 1 <= p, q <= n.

---------------------------------------
Approach:
1.  Find the maximum and minimum values in the array. Let them be maxi and mini.
2.  The maximum absolute difference is diff = maxi - mini.
3.  We need to find pairs (a[i], a[j]) such that |a[i] - a[j]| = diff.
4.  Case 1: If maxi == mini (all elements are same), then any pair (i, j) with i != j works.
    The count is n * (n - 1).
5.  Case 2: If maxi != mini, we need one element to be maxi and the other to be mini.
    Count the occurrences of maxi (cntmax) and mini (cntmin).
    The number of pairs is 2 * cntmin * cntmax (since order matters.

----------------------------------------
Time Complexity: O(n) - find min, max and their counts.
Space Complexity: O(n) - store the input array.

----------------------------------------
Example:
Input:
5
6 2 3 8 1

Process:
1. mini = 1, maxi = 8.
2. diff = 7.
3. cntmin (1) = 1.
4. cntmax (8) = 1.
5. Result = 2 * 1 * 1 = 2.

Output:
2
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define out(x) cout << (x) << endl
#define outr(x)            \
    {                      \
        cout << x << endl; \
        return;            \
    }

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < mini)
            mini = a[i];
        if (a[i] > maxi)
            maxi = a[i];
    }

    if (mini == maxi)
    {
        cout <<  n * (n - 1) << endl;
        return;
    }

    ll cntmin = 0;
    ll cntmax = 0;
    for (int x : a)
    {
        if (x == mini)
            cntmin++;
        if (x == maxi)
            cntmax++;
    }

    cout << 2*cntmin*cntmax << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//submission link: https://codeforces.com/problemset/submission/1771/355269691
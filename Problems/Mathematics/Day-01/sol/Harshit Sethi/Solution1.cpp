// https://codeforces.com/problemset/submission/1560/355220642

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        long long order = fabs(a - b);
        if ((2 * order < a) || (2 * order < b) || (2 * order < c))
            cout << -1 << endl;
        else if (order < c)
            cout << c - order << endl;
        else
            cout << c + order << endl;
    }
}
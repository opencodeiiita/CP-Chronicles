// submission link - https://codeforces.com/contest/343/submission/355607613

#include <bits/stdc++.h>
using namespace std;

/*
1. We want to make fraction a/b using smallest number of 1 resistors.
2. We can add resistor in line (series) or side (parallel).
3. Instead of making from 1, we go backward from a/b.
4. If a is bigger than b, then we minus b from a.
5. If b is bigger than a, then we minus a from b.
6. Every minus means we used one resistor.
7. We count how many times we can minus using divide.
8. This work same like Euclid algo (gcd thing).
9. When one number become zero, we stop.
10. Total count is our answer.
*/

int main()
{
    unsigned long long a, b;
    cin >> a >> b;

    long long totalResistors = 0;

    while (a && b)
    {
        totalResistors += a / b;
        a %= b;
        swap(a, b);
    }

    cout << totalResistors;
    return 0;
}

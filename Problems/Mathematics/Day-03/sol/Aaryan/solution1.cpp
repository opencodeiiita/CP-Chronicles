// link : https://codeforces.com/contest/343/submission/355845658


#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long a,b;
    cin>>a>>b;
    long long ans=0;
    while(a>0 && b>0) {
        if(a>b) {
            ans+=a/b;
            a=a%b;
        }
        else {
            ans+=b/a;
            b=b%a;
        }
    }
    cout<<ans<<endl;
}



/*
Explanation:

We need to construct a resistance equal to a / b using unit resistors.
Series and parallel connections correspond to increasing or reducing the
fraction exactly like steps in the Euclidean Algorithm.

If a > b:
- We can add 1 in series floor(a / b) times
- a becomes a % b

If b > a:
- We can add 1 in parallel floor(b / a) times
- b becomes b % a

Each division step adds the quotient to the number of resistors used.
Thus, the answer is the sum of all quotients during the Euclidean process.

The fraction is irreducible, so the algorithm always terminates.

Time Complexity:
O(log(min(a, b)))

Space Complexity:
O(1)
*/
